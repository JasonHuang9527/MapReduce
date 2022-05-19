#include "worker.h"

using namespace std;

int main(int argc, char**argv) {
     Worker wk(argv[1],argv[2]);
     wk.startWorkerService();
}