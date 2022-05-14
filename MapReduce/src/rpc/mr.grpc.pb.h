// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: mr.proto
#ifndef GRPC_mr_2eproto__INCLUDED
#define GRPC_mr_2eproto__INCLUDED

#include "mr.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

class worker final {
 public:
  static constexpr char const* service_full_name() {
    return "worker";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status DoJob(::grpc::ClientContext* context, const ::DoJobRequest& request, ::DoJobResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::DoJobResponse>> AsyncDoJob(::grpc::ClientContext* context, const ::DoJobRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::DoJobResponse>>(AsyncDoJobRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::DoJobResponse>> PrepareAsyncDoJob(::grpc::ClientContext* context, const ::DoJobRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::DoJobResponse>>(PrepareAsyncDoJobRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void DoJob(::grpc::ClientContext* context, const ::DoJobRequest* request, ::DoJobResponse* response, std::function<void(::grpc::Status)>) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::DoJobResponse>* AsyncDoJobRaw(::grpc::ClientContext* context, const ::DoJobRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::DoJobResponse>* PrepareAsyncDoJobRaw(::grpc::ClientContext* context, const ::DoJobRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status DoJob(::grpc::ClientContext* context, const ::DoJobRequest& request, ::DoJobResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::DoJobResponse>> AsyncDoJob(::grpc::ClientContext* context, const ::DoJobRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::DoJobResponse>>(AsyncDoJobRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::DoJobResponse>> PrepareAsyncDoJob(::grpc::ClientContext* context, const ::DoJobRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::DoJobResponse>>(PrepareAsyncDoJobRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void DoJob(::grpc::ClientContext* context, const ::DoJobRequest* request, ::DoJobResponse* response, std::function<void(::grpc::Status)>) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::DoJobResponse>* AsyncDoJobRaw(::grpc::ClientContext* context, const ::DoJobRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::DoJobResponse>* PrepareAsyncDoJobRaw(::grpc::ClientContext* context, const ::DoJobRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_DoJob_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status DoJob(::grpc::ServerContext* context, const ::DoJobRequest* request, ::DoJobResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_DoJob : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_DoJob() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_DoJob() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DoJob(::grpc::ServerContext* context, const ::DoJobRequest* request, ::DoJobResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDoJob(::grpc::ServerContext* context, ::DoJobRequest* request, ::grpc::ServerAsyncResponseWriter< ::DoJobResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_DoJob<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_DoJob : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_DoJob() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_DoJob() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DoJob(::grpc::ServerContext* context, const ::DoJobRequest* request, ::DoJobResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_DoJob : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_DoJob() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_DoJob() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DoJob(::grpc::ServerContext* context, const ::DoJobRequest* request, ::DoJobResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDoJob(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_DoJob : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_DoJob() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::DoJobRequest, ::DoJobResponse>(std::bind(&WithStreamedUnaryMethod_DoJob<BaseClass>::StreamedDoJob, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_DoJob() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status DoJob(::grpc::ServerContext* context, const ::DoJobRequest* request, ::DoJobResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedDoJob(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::DoJobRequest,::DoJobResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_DoJob<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_DoJob<Service > StreamedService;
};

class master final {
 public:
  static constexpr char const* service_full_name() {
    return "master";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Register(::grpc::ClientContext* context, const ::RegisterRequest& request, ::RegisterResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::RegisterResponse>> AsyncRegister(::grpc::ClientContext* context, const ::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::RegisterResponse>>(AsyncRegisterRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::RegisterResponse>> PrepareAsyncRegister(::grpc::ClientContext* context, const ::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::RegisterResponse>>(PrepareAsyncRegisterRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void Register(::grpc::ClientContext* context, const ::RegisterRequest* request, ::RegisterResponse* response, std::function<void(::grpc::Status)>) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::RegisterResponse>* AsyncRegisterRaw(::grpc::ClientContext* context, const ::RegisterRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::RegisterResponse>* PrepareAsyncRegisterRaw(::grpc::ClientContext* context, const ::RegisterRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Register(::grpc::ClientContext* context, const ::RegisterRequest& request, ::RegisterResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::RegisterResponse>> AsyncRegister(::grpc::ClientContext* context, const ::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::RegisterResponse>>(AsyncRegisterRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::RegisterResponse>> PrepareAsyncRegister(::grpc::ClientContext* context, const ::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::RegisterResponse>>(PrepareAsyncRegisterRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Register(::grpc::ClientContext* context, const ::RegisterRequest* request, ::RegisterResponse* response, std::function<void(::grpc::Status)>) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::RegisterResponse>* AsyncRegisterRaw(::grpc::ClientContext* context, const ::RegisterRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::RegisterResponse>* PrepareAsyncRegisterRaw(::grpc::ClientContext* context, const ::RegisterRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Register_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Register(::grpc::ServerContext* context, const ::RegisterRequest* request, ::RegisterResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Register : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Register() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Register() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Register(::grpc::ServerContext* context, const ::RegisterRequest* request, ::RegisterResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRegister(::grpc::ServerContext* context, ::RegisterRequest* request, ::grpc::ServerAsyncResponseWriter< ::RegisterResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Register<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_Register : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Register() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Register() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Register(::grpc::ServerContext* context, const ::RegisterRequest* request, ::RegisterResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Register : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Register() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Register() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Register(::grpc::ServerContext* context, const ::RegisterRequest* request, ::RegisterResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRegister(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Register : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Register() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::RegisterRequest, ::RegisterResponse>(std::bind(&WithStreamedUnaryMethod_Register<BaseClass>::StreamedRegister, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Register() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Register(::grpc::ServerContext* context, const ::RegisterRequest* request, ::RegisterResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedRegister(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::RegisterRequest,::RegisterResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Register<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Register<Service > StreamedService;
};


#endif  // GRPC_mr_2eproto__INCLUDED
