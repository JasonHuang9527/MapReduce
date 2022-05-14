#include <string>
#include "master.h"

int main(int argc, char** argv) {
    Master ms("localhost:5000","kjv12.txt");
    ms.splitFile(4096);
    ms.startServer();
}