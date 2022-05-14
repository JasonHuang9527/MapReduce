#include "rpc/mr.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class MasterClient{
    public:
        MasterClient(std::shared_ptr<grpc::Channel> channel) : stub_(master::NewStub(channel)) {}
        bool Register(std::string address) {

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
                std::cout << status.error_code() << ": " << status.error_message() << std::endl;
                return false;
            }
        }
    private:
        std::unique_ptr<master::Stub> stub_;
};

int main(int argc, char**argv) {
    std::string serverAddress = "localhost:5000";
    std::string tmp(argv[1]);
    std::string workerAddress = "localhost:" + tmp;

    MasterClient MC(grpc::CreateChannel(serverAddress, grpc::InsecureChannelCredentials()));
    bool reply = MC.Register(workerAddress);
    std::cout << "MC received: " << reply << std::endl;
}