#ifndef _MASTER_H_
#define _MASTER_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Master {
    public:
        Master(string port, string file);
        void startServer();
        void splitFile(int chunkSize);
    private:
        string port; 
        string txtfile;
        vector <string> shards;
};

#endif