#include "master.h"
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include "utils.h"
#include <thread>
#include <unistd.h>

using namespace std;

bool WorkerClient::doJob(vector<string> files, string jobType) {
    // create request & response
    DoJobRequest request;
    request.set_jobtype(jobType);
    for (auto & file : files){
        request.add_files(file);
    }
    DoJobResponse response;

    // context for the client 
    grpc::ClientContext context;

    // remote procedure call
    grpc::Status status = stub_->DoJob(&context, request, &response);

    // act upon its status
    if (status.ok()) {
        cout << "dojob response: "<<response.done() <<endl;
        return true;
    } else {
        cout << status.error_code() << ": " << status.error_message() << std::endl;
        return false;
    }
}


WorkerInfo::WorkerInfo(string workerAddress) {
    this->workerClient = new WorkerClient(grpc::CreateChannel(workerAddress, grpc::InsecureChannelCredentials()));
    this->workerAddress = workerAddress;
    this->status = "idle";
}

grpc::Status MasterServiceImpl::Register(grpc::ServerContext* context, const RegisterRequest* req, RegisterResponse* rsp) {
    // handle req
    string workerAddress = req->address();
    cout << "Master get Register request: "<<workerAddress <<endl;
    this->workerInfo.push_back(WorkerInfo(workerAddress) );
        
    // handle rsp
    for(WorkerInfo& w: this->workerInfo) {
        rsp->add_addresses(w.workerAddress);
    };

    // return status
    return grpc::Status::OK;
};

void MasterServiceImpl::setMasterAddress(string port) {
    this->masterAddress = port;
}

Master::Master(string port, string file,int num_mapTask, int num_reduceTask) {
    this->port = port;
    this->txtfile = file;
    this->num_mapTask = num_mapTask;
    this->num_reduceTask = num_reduceTask;
    this->shards_folder = "./shards";
    this->masterService = new MasterServiceImpl();
}

void Master::startMasterService() {
    //MasterServiceImpl service;
    //this->masterService->setMasterAddress(this->port);

    grpc::ServerBuilder builder;

    // Listen on the given address without any authentication meCreateChannelism.
    builder.AddListeningPort(this->port, grpc::InsecureServerCredentials());

    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(this->masterService);

    // Finally assemble the server.
    unique_ptr<grpc::Server> server(builder.BuildAndStart());
    cout << "Server (master) Listening on port: " << this->port << endl;

    // Wait for the server to shutdown.
    //server -> Wait();
    thread t1(&grpc::Server::Wait, move(server) );
    this->startMapReduce();
    t1.join();
}

Task* Master::getIdleTask(){
    Task * t = nullptr;
    vector<Task>* tasks = nullptr;
    int num_remain_mapTask = this->num_mapTask;
    int num_remain_reduceTask = this->num_reduceTask;
    // decide it is in map_phase/reduce_phase/end
    if (num_remain_mapTask > 0) {
        tasks = &this->mapTasks;
    } else if (num_remain_reduceTask > 0) {
        tasks = &this->reduceTasks;
    } else {
        t = new Task("end", -1, "", "");
        return t;
    }

    // get a idle task by iterating through all tasks
    for(Task & task: *tasks) {
        if (task.status == "idle") {
            t = &task;
            return t;
        }
    }
    return t;
}

WorkerInfo* Master::getIdleWorker(){
    WorkerInfo * w = nullptr;
    for(WorkerInfo& worker: this->masterService->workerInfo) {
        if (worker.status == "idle") {
            w = &worker;
            break;
        }
    }
    return w;
}

void Master::startMapReduce() {
    string filler =  " ------------------------------ " ;

    cout << filler << "Split "<<this->txtfile <<" into shards"<< filler <<endl;
    this->splitFile(4096);

    cout << filler << "Initialize task lists"<< filler <<endl;
    this->initTasks();

    cout << filler << "Start assigning tasks to workers"<< filler <<endl;
    while (true){
        // get idle task
        Task* t = this->getIdleTask();
        if(t->type == "end") {
            break;
        }

        // get idle worker
        WorkerInfo* w = this->getIdleWorker();
        if (w == NULL) {
            cout << "no idle worker => sleep for 1 second"<<endl;
            usleep(1000*1000);
            continue;
        }
        cout <<"idle task   => "<< *t <<endl;
        cout <<"idle worker => " << w->workerAddress <<endl;

        // rpc
        auto shards_all = getShards("./shards");
        vector<string> shards_assigned;
        for(string & shard : shards_all) {
            string name = getFileNameFromPath(shard, "/", true);
            int file_id = stoi(name);
            if (file_id % this->num_mapTask == t->id) {
                shards_assigned.push_back(shard);
            }
        }
        cout <<"master call "<<w->workerAddress << "'s doJob "<< *t <<endl;
        w->workerClient->doJob(shards_assigned, "map");

        t->status = "busy";
        w->status = "busy";

    }

    // merge result



}

void processLine(string s, char delimiter, queue<string> &tokens ) {
    string token;
    stringstream ss(s);
    while(getline(ss,token,delimiter)) {
        if(token.length()>0) {
            tokens.push(token);
        }
    }
}

void Master::splitFile(int chunkSize = 1024) {
    deleteDirectoryContents(this->shards_folder);

    int idx_shard = 0;
    string shard_path = this->shards_folder + "/" + to_string(idx_shard) +".txt";
    this->shards.push_back(shard_path);
    ofstream shard;
    shard.open(shard_path);

    ifstream file(this->txtfile, std::ios::in);
    int currentSize = 0;
    queue<string> tokens;
    for( string line ; getline( file, line ); )
    {
        processLine(line, ' ', tokens);
        while(tokens.size()){
            string token = tokens.front();
            tokens.pop();
            shard << token <<endl;
            currentSize += 1;
            if(currentSize == chunkSize) {
                idx_shard += 1;
                shard.close();
                shard_path = this->shards_folder + "/" + to_string(idx_shard) +".txt";
                this->shards.push_back(shard_path);
                shard.open(shard_path);
                currentSize = 0;
            }
        }
    }
    shard.close();
    cout << "Number of shards:" << idx_shard <<endl;
}

void Master::initTasks() {
    for(int id=0 ; id < this->num_mapTask ; id++) {
        Task t("map",id,"idle","");
        this->mapTasks.push_back(t);
    }
    for(int id=0 ; id < this->num_reduceTask ; id++) {
        Task t("reduce",id,"idle","");
        this->reduceTasks.push_back(t);
    }
    cout << "map    tasks: \n    "<<this->mapTasks << endl;
    cout << "\nreduce tasks: \n    "<<this->reduceTasks <<endl;
}











