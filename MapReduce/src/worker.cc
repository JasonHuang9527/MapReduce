#include "worker.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "utils.h"


grpc::Status WorkerServiceImpl::DoJob(grpc::ServerContext* context, const DoJobRequest* req, DoJobResponse* rsp) {
    // handle req
    auto file_path = req->filepath();
    auto job_type = req->jobtype();
    cout << "Worker get DoJob request: "<<file_path <<" "<< job_type <<std::endl;
    if (job_type == "Map") {

    } else if (job_type == "Reduce") {

    } else {

    }
    
    // handle rsp
    rsp->set_done("Done");

    // return status
    return grpc::Status::OK;
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
}

void Worker::startServer() {
    MasterClient MC(grpc::CreateChannel(this->masterAddress, grpc::InsecureChannelCredentials()));
    bool reply = MC.Register(this->port);
    cout << "MC received: " << reply << std::endl;
};

void Worker::doMap(string file_path){
    cout << "doMap:" << file_path <<endl;
    return ;
}

void Worker::doReduce(string file_path){
    cout << "doReduce:" << file_path <<endl;
    return ;
}