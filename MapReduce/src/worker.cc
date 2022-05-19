#include "worker.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "utils.h"
#include <thread>

grpc::Status WorkerServiceImpl::DoJob(grpc::ServerContext* context, const DoJobRequest* req, DoJobResponse* rsp) {
    // handle req
    vector<string> files;
    for(int i=0; i<req->files_size();i++){
        // cout << response.addresses(i) <<" ";
        files.push_back ( req->files(i) );
    }
    auto job_type = req->jobtype();
    cout << "Worker get DoJob request: "<<files <<" "<< job_type <<std::endl;
    if (job_type == "map") {
        this->doMap(files);
    } else if (job_type == "reduce") {
        this->doReduce(files);
    } else {
        
    }
    
    // handle rsp
    rsp->set_done("Done");

    // return status
    return grpc::Status::OK;
};

void WorkerServiceImpl::setMasterClient(string masterAddress) {
    this->masterClient = new MasterClient(grpc::CreateChannel(masterAddress, grpc::InsecureChannelCredentials()));
};

void WorkerServiceImpl::doMap(vector<string> files){
    return ;
};

void WorkerServiceImpl::doReduce(vector<string> files){
    return ;
};


bool MasterClient::Register(std::string address) {
    // create request & response
    RegisterRequest request;
    request.set_address(address);
    RegisterResponse response;

    // context for the client 
    grpc::ClientContext context;

    // remote procedure call
    grpc::Status status = stub_->Register(&context, request, &response);

    // act upon its status
    if (status.ok()) {
        for(int i=0; i<response.addresses_size();i++){
            cout << response.addresses(i) <<" ";
        }
        cout<<endl;
        return true;
    } else {
        cout << status.error_code() << ": " << status.error_message() << std::endl;
        return false;
    }
}

Worker::Worker(string port, string masterAddress) {
    this->port = port;
    this->masterAddress = masterAddress;
    this->workerService = new WorkerServiceImpl();
    this->workerService->setMasterClient(masterAddress);
}

void Worker::startWorkerService() {
    
    grpc::ServerBuilder builder;

    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(this->port, grpc::InsecureServerCredentials());

    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(this->workerService);

    // Finally assemble the server.
    unique_ptr<grpc::Server> server(builder.BuildAndStart());
    cout << "Server (worker) Listening on port: " << this->port << endl;

    // Wait for the server to shutdown.
    // server -> Wait();
    thread t1(&grpc::Server::Wait, move(server) );
    bool reply = this->workerService->masterClient->Register(this->port);
    cout << "client call register => received: " << reply << endl;
    t1.join();


}


