#include "master.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <experimental/filesystem>

#include "rpc/mr.grpc.pb.h"
#include <grpcpp/grpcpp.h>

template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << "|" << *ii;
    }
    os << "]";
    return os;
}

class MasterServiceImpl : public master::Service {
    grpc::Status Register(grpc::ServerContext* context, const RegisterRequest* req, RegisterResponse* rsp) {
        // handle req
        std::cout << "Master get Register request: "<<req->address() <<std::endl;
        workerPorts.push_back(req->address());

        // handle rsp
        for(auto port: workerPorts) {
            rsp->add_addresses(port);
        }

        // return status
        return grpc::Status::OK;
    };
    public:
        vector <string> workerPorts;

};

Master::Master(string port, string file) {
    this->port = port;
    this->ori_file = file;
    this->shards_folder = "./shards"
}

void Master::startServer() {
    MasterServiceImpl service;
    grpc::ServerBuilder builder;

    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(this->port, grpc::InsecureServerCredentials());

    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);

    // Finally assemble the server.
    unique_ptr<grpc::Server> server(builder.BuildAndStart());
    cout << "Server Listening on port: " << this->port << endl;

    // Wait for the server to shutdown.
    server -> Wait();
}


void processLine(string s, char delimiter, vector<string> &tokens ) {
    string token;
    stringstream ss(s);
    while(getline(ss,token,delimiter)) {
        if(token.length()>0) {
            tokens.push_back(token);
        }
    }
}

void deleteDirectoryContents(const string& dir_path)
{
    for (const auto& entry : experimental::filesystem::directory_iterator(dir_path)) 
        experimental::filesystem::remove_all(entry.path());
}


void Master::splitFile(int chunkSize = 1024) {
    cout << "Split: "<<this->file_path <<endl;

    deleteDirectoryContents(this->shards_folder);


    int idx_shard = 0;
    string shard_path = folder + "/" + to_string(idx_shard) +".txt";

    ofstream shard;
    shard.open(shard_path);

    ifstream file(this->file_path, std::ios::in);
    int currentSize = 0;
    vector<string> tokens;
    for( string line; getline( file, line ); )
    {
        processLine(line, ' ', tokens);
        while(tokens.size()){
            string token = tokens.back();
            tokens.pop_back();
            shard << token <<endl;
            currentSize += 1;
            if(currentSize == chunkSize) {
                idx_shard += 1;
                shard.close();
                shard_path = folder + "/" + to_string(idx_shard) +".txt";
                shard.open(shard_path);
                currentSize = 0;
            }
        }
    }
    shard.close();
    cout << "Number of shards:" << idx_shard <<endl;
}