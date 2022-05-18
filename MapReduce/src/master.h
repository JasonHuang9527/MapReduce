#ifndef _MASTER_H_
#define _MASTER_H_

#include <iostream>
#include <string>
#include <vector>
#include "rpc/mr.grpc.pb.h"
#include <grpcpp/grpcpp.h>

using namespace std;

class Task {
    public:
        Task(string type, int id, string status, string worker): type(type),id(id),status(status),worker(worker) {};
        string type;
        int id;
        string status;
        string worker;
};

inline ostream& operator << (ostream& os, const Task& t) 
{
    os << "( type: "<<t.type<<", id: "<<t.id<<", status: "<<t.status<<")"<<endl;
    return os;
};

class WorkerClient{
    public:
        WorkerClient(shared_ptr<grpc::Channel> channel) : stub_(worker::NewStub(channel)){};
        bool doJob(string filePath, string jobType);
    private:
        unique_ptr<worker::Stub> stub_;
};

class WorkerInfo {
    public:
        WorkerInfo(string masterAddress, string workerAddress);
        WorkerClient* workerClient;
        string workerAddress;
        string status;
};

class MasterServiceImpl : public master::Service {
    public:
        grpc::Status Register(grpc::ServerContext* context, const RegisterRequest* req, RegisterResponse* rsp);
        void setMasterAddress(string port);
        vector <WorkerInfo> workerInfo;
        string masterAddress; 
};
class Master {
    public:
        Master(string port, string file, int num_mapTask, int num_reduceTask);
        void startServer();
        void startMapReduce(MasterServiceImpl* service);
        void splitFile(int chunkSize);
        void initTasks();
        WorkerInfo * getIdleWorker(MasterServiceImpl* service);
        Task* getIdleTask();
    private:
        string port; 
        string txtfile;
        int num_mapTask;
        int num_reduceTask;
        

        string shards_folder;
        vector <string> shards;
        vector<Task>mapTasks;
        vector<Task>reduceTasks;
};

#endif