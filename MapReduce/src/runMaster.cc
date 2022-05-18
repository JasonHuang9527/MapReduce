#include <string>
#include "master.h"
#include <thread>

using namespace std;

int main(int argc, char** argv) {
    Master ms(argv[1],argv[2], 10, 10);
    ms.startServer();

}