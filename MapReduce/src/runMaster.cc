#include <string>
#include "master.h"
#include <thread>

using namespace std;

int main(int argc, char** argv) {
    Master ms(argv[1],"kjv12.txt", 20, 20);
    ms.startMasterService();
}