#ifndef _WORKER_H_
#define _WORKER_H_

#include <string>
#include "rpc/mr.grpc.pb.h"
#include <grpcpp/grpcpp.h>
using namespace std;


class WorkerServiceImpl : public worker::Service {
    grpc::Status DoJob(grpc::ServerContext* context, const DoJobRequest* req, DoJobResponse* rsp);  
};

class MasterClient{
    public:
        MasterClient(shared_ptr<grpc::Channel> channel) : stub_(master::NewStub(channel)) {};
        bool Register(std::string address);
    private:
        unique_ptr<master::Stub> stub_;
};
class Worker {
    public:
        Worker(string port,string masterAddress);
        void startServer();
        void doMap();
        void doReduce();
    private:
        string port; 
        string masterAddress;
};

#endif