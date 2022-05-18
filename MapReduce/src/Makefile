HOST_SYSTEM = $(shell uname | cut -f 1 -d_)
SYSTEM ?= $(HOST_SYSTEM)

CXX = g++

CPPFLAGS += `pkg-config --cflags protobuf grpc`

CXXFLAGS += -std=c++17

ifeq ($(SYSTEM),Darwin)
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -pthread\
		   -lstdc++fs\
           -lgrpc++_reflection\
           -ldl
		   
else
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -pthread\
		   -lstdc++fs\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl
endif

PROTOC = protoc
GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`

PROTOS_PATH = /home/MapReduce/src/rpc
GRPC_OUT_PATH = /home/MapReduce/src/rpc

vpath %.proto $(PROTOS_PATH)
vpath %.grpc.pb.cc $(GRPC_OUT_PATH)
vpath %.pb.cc $(GRPC_OUT_PATH)

all: runMaster runWorker

runMaster: /home/MapReduce/src/rpc/mr.pb.o /home/MapReduce/src/rpc/mr.grpc.pb.o runMaster.o master.o utils.o
	$(CXX) $^ $(LDFLAGS) -o $@

runWorker: /home/MapReduce/src/rpc/mr.pb.o /home/MapReduce/src/rpc/mr.grpc.pb.o runWorker.o worker.o utils.o
	$(CXX) $^ $(LDFLAGS) -o $@



.PRECIOUS: %.grpc.pb.cc
%.grpc.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=$(GRPC_OUT_PATH) --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<

.PRECIOUS: %.pb.cc
%.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=$(GRPC_OUT_PATH) $<

clean:
	rm -f ./shards/*.txt
	rm -f *.o runWorker runMaster
	rm -f $(GRPC_OUT_PATH)/*.o $(GRPC_OUT_PATH)/*.pb.cc $(GRPC_OUT_PATH)/*.pb.h