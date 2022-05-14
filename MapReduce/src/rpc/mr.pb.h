// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mr.proto

#ifndef PROTOBUF_INCLUDED_mr_2eproto
#define PROTOBUF_INCLUDED_mr_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_mr_2eproto 

namespace protobuf_mr_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_mr_2eproto
class DoJobRequest;
class DoJobRequestDefaultTypeInternal;
extern DoJobRequestDefaultTypeInternal _DoJobRequest_default_instance_;
class DoJobResponse;
class DoJobResponseDefaultTypeInternal;
extern DoJobResponseDefaultTypeInternal _DoJobResponse_default_instance_;
class RegisterRequest;
class RegisterRequestDefaultTypeInternal;
extern RegisterRequestDefaultTypeInternal _RegisterRequest_default_instance_;
class RegisterResponse;
class RegisterResponseDefaultTypeInternal;
extern RegisterResponseDefaultTypeInternal _RegisterResponse_default_instance_;
namespace google {
namespace protobuf {
template<> ::DoJobRequest* Arena::CreateMaybeMessage<::DoJobRequest>(Arena*);
template<> ::DoJobResponse* Arena::CreateMaybeMessage<::DoJobResponse>(Arena*);
template<> ::RegisterRequest* Arena::CreateMaybeMessage<::RegisterRequest>(Arena*);
template<> ::RegisterResponse* Arena::CreateMaybeMessage<::RegisterResponse>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class RegisterRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:RegisterRequest) */ {
 public:
  RegisterRequest();
  virtual ~RegisterRequest();

  RegisterRequest(const RegisterRequest& from);

  inline RegisterRequest& operator=(const RegisterRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RegisterRequest(RegisterRequest&& from) noexcept
    : RegisterRequest() {
    *this = ::std::move(from);
  }

  inline RegisterRequest& operator=(RegisterRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RegisterRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RegisterRequest* internal_default_instance() {
    return reinterpret_cast<const RegisterRequest*>(
               &_RegisterRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(RegisterRequest* other);
  friend void swap(RegisterRequest& a, RegisterRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RegisterRequest* New() const final {
    return CreateMaybeMessage<RegisterRequest>(NULL);
  }

  RegisterRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RegisterRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RegisterRequest& from);
  void MergeFrom(const RegisterRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RegisterRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string address = 1;
  void clear_address();
  static const int kAddressFieldNumber = 1;
  const ::std::string& address() const;
  void set_address(const ::std::string& value);
  #if LANG_CXX11
  void set_address(::std::string&& value);
  #endif
  void set_address(const char* value);
  void set_address(const char* value, size_t size);
  ::std::string* mutable_address();
  ::std::string* release_address();
  void set_allocated_address(::std::string* address);

  // @@protoc_insertion_point(class_scope:RegisterRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr address_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_mr_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class RegisterResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:RegisterResponse) */ {
 public:
  RegisterResponse();
  virtual ~RegisterResponse();

  RegisterResponse(const RegisterResponse& from);

  inline RegisterResponse& operator=(const RegisterResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RegisterResponse(RegisterResponse&& from) noexcept
    : RegisterResponse() {
    *this = ::std::move(from);
  }

  inline RegisterResponse& operator=(RegisterResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RegisterResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RegisterResponse* internal_default_instance() {
    return reinterpret_cast<const RegisterResponse*>(
               &_RegisterResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(RegisterResponse* other);
  friend void swap(RegisterResponse& a, RegisterResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RegisterResponse* New() const final {
    return CreateMaybeMessage<RegisterResponse>(NULL);
  }

  RegisterResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RegisterResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RegisterResponse& from);
  void MergeFrom(const RegisterResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RegisterResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated string addresses = 1;
  int addresses_size() const;
  void clear_addresses();
  static const int kAddressesFieldNumber = 1;
  const ::std::string& addresses(int index) const;
  ::std::string* mutable_addresses(int index);
  void set_addresses(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_addresses(int index, ::std::string&& value);
  #endif
  void set_addresses(int index, const char* value);
  void set_addresses(int index, const char* value, size_t size);
  ::std::string* add_addresses();
  void add_addresses(const ::std::string& value);
  #if LANG_CXX11
  void add_addresses(::std::string&& value);
  #endif
  void add_addresses(const char* value);
  void add_addresses(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& addresses() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_addresses();

  // @@protoc_insertion_point(class_scope:RegisterResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::std::string> addresses_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_mr_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class DoJobRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:DoJobRequest) */ {
 public:
  DoJobRequest();
  virtual ~DoJobRequest();

  DoJobRequest(const DoJobRequest& from);

  inline DoJobRequest& operator=(const DoJobRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DoJobRequest(DoJobRequest&& from) noexcept
    : DoJobRequest() {
    *this = ::std::move(from);
  }

  inline DoJobRequest& operator=(DoJobRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DoJobRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DoJobRequest* internal_default_instance() {
    return reinterpret_cast<const DoJobRequest*>(
               &_DoJobRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(DoJobRequest* other);
  friend void swap(DoJobRequest& a, DoJobRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DoJobRequest* New() const final {
    return CreateMaybeMessage<DoJobRequest>(NULL);
  }

  DoJobRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<DoJobRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const DoJobRequest& from);
  void MergeFrom(const DoJobRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DoJobRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string filePath = 1;
  void clear_filepath();
  static const int kFilePathFieldNumber = 1;
  const ::std::string& filepath() const;
  void set_filepath(const ::std::string& value);
  #if LANG_CXX11
  void set_filepath(::std::string&& value);
  #endif
  void set_filepath(const char* value);
  void set_filepath(const char* value, size_t size);
  ::std::string* mutable_filepath();
  ::std::string* release_filepath();
  void set_allocated_filepath(::std::string* filepath);

  // string jobType = 2;
  void clear_jobtype();
  static const int kJobTypeFieldNumber = 2;
  const ::std::string& jobtype() const;
  void set_jobtype(const ::std::string& value);
  #if LANG_CXX11
  void set_jobtype(::std::string&& value);
  #endif
  void set_jobtype(const char* value);
  void set_jobtype(const char* value, size_t size);
  ::std::string* mutable_jobtype();
  ::std::string* release_jobtype();
  void set_allocated_jobtype(::std::string* jobtype);

  // @@protoc_insertion_point(class_scope:DoJobRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr filepath_;
  ::google::protobuf::internal::ArenaStringPtr jobtype_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_mr_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class DoJobResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:DoJobResponse) */ {
 public:
  DoJobResponse();
  virtual ~DoJobResponse();

  DoJobResponse(const DoJobResponse& from);

  inline DoJobResponse& operator=(const DoJobResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DoJobResponse(DoJobResponse&& from) noexcept
    : DoJobResponse() {
    *this = ::std::move(from);
  }

  inline DoJobResponse& operator=(DoJobResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DoJobResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DoJobResponse* internal_default_instance() {
    return reinterpret_cast<const DoJobResponse*>(
               &_DoJobResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(DoJobResponse* other);
  friend void swap(DoJobResponse& a, DoJobResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DoJobResponse* New() const final {
    return CreateMaybeMessage<DoJobResponse>(NULL);
  }

  DoJobResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<DoJobResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const DoJobResponse& from);
  void MergeFrom(const DoJobResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DoJobResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bool done = 1;
  void clear_done();
  static const int kDoneFieldNumber = 1;
  bool done() const;
  void set_done(bool value);

  // @@protoc_insertion_point(class_scope:DoJobResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool done_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_mr_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RegisterRequest

// string address = 1;
inline void RegisterRequest::clear_address() {
  address_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& RegisterRequest::address() const {
  // @@protoc_insertion_point(field_get:RegisterRequest.address)
  return address_.GetNoArena();
}
inline void RegisterRequest::set_address(const ::std::string& value) {
  
  address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:RegisterRequest.address)
}
#if LANG_CXX11
inline void RegisterRequest::set_address(::std::string&& value) {
  
  address_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:RegisterRequest.address)
}
#endif
inline void RegisterRequest::set_address(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:RegisterRequest.address)
}
inline void RegisterRequest::set_address(const char* value, size_t size) {
  
  address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:RegisterRequest.address)
}
inline ::std::string* RegisterRequest::mutable_address() {
  
  // @@protoc_insertion_point(field_mutable:RegisterRequest.address)
  return address_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RegisterRequest::release_address() {
  // @@protoc_insertion_point(field_release:RegisterRequest.address)
  
  return address_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RegisterRequest::set_allocated_address(::std::string* address) {
  if (address != NULL) {
    
  } else {
    
  }
  address_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), address);
  // @@protoc_insertion_point(field_set_allocated:RegisterRequest.address)
}

// -------------------------------------------------------------------

// RegisterResponse

// repeated string addresses = 1;
inline int RegisterResponse::addresses_size() const {
  return addresses_.size();
}
inline void RegisterResponse::clear_addresses() {
  addresses_.Clear();
}
inline const ::std::string& RegisterResponse::addresses(int index) const {
  // @@protoc_insertion_point(field_get:RegisterResponse.addresses)
  return addresses_.Get(index);
}
inline ::std::string* RegisterResponse::mutable_addresses(int index) {
  // @@protoc_insertion_point(field_mutable:RegisterResponse.addresses)
  return addresses_.Mutable(index);
}
inline void RegisterResponse::set_addresses(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:RegisterResponse.addresses)
  addresses_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void RegisterResponse::set_addresses(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:RegisterResponse.addresses)
  addresses_.Mutable(index)->assign(std::move(value));
}
#endif
inline void RegisterResponse::set_addresses(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  addresses_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:RegisterResponse.addresses)
}
inline void RegisterResponse::set_addresses(int index, const char* value, size_t size) {
  addresses_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:RegisterResponse.addresses)
}
inline ::std::string* RegisterResponse::add_addresses() {
  // @@protoc_insertion_point(field_add_mutable:RegisterResponse.addresses)
  return addresses_.Add();
}
inline void RegisterResponse::add_addresses(const ::std::string& value) {
  addresses_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:RegisterResponse.addresses)
}
#if LANG_CXX11
inline void RegisterResponse::add_addresses(::std::string&& value) {
  addresses_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:RegisterResponse.addresses)
}
#endif
inline void RegisterResponse::add_addresses(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  addresses_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:RegisterResponse.addresses)
}
inline void RegisterResponse::add_addresses(const char* value, size_t size) {
  addresses_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:RegisterResponse.addresses)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
RegisterResponse::addresses() const {
  // @@protoc_insertion_point(field_list:RegisterResponse.addresses)
  return addresses_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
RegisterResponse::mutable_addresses() {
  // @@protoc_insertion_point(field_mutable_list:RegisterResponse.addresses)
  return &addresses_;
}

// -------------------------------------------------------------------

// DoJobRequest

// string filePath = 1;
inline void DoJobRequest::clear_filepath() {
  filepath_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DoJobRequest::filepath() const {
  // @@protoc_insertion_point(field_get:DoJobRequest.filePath)
  return filepath_.GetNoArena();
}
inline void DoJobRequest::set_filepath(const ::std::string& value) {
  
  filepath_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DoJobRequest.filePath)
}
#if LANG_CXX11
inline void DoJobRequest::set_filepath(::std::string&& value) {
  
  filepath_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:DoJobRequest.filePath)
}
#endif
inline void DoJobRequest::set_filepath(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  filepath_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DoJobRequest.filePath)
}
inline void DoJobRequest::set_filepath(const char* value, size_t size) {
  
  filepath_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DoJobRequest.filePath)
}
inline ::std::string* DoJobRequest::mutable_filepath() {
  
  // @@protoc_insertion_point(field_mutable:DoJobRequest.filePath)
  return filepath_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DoJobRequest::release_filepath() {
  // @@protoc_insertion_point(field_release:DoJobRequest.filePath)
  
  return filepath_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DoJobRequest::set_allocated_filepath(::std::string* filepath) {
  if (filepath != NULL) {
    
  } else {
    
  }
  filepath_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), filepath);
  // @@protoc_insertion_point(field_set_allocated:DoJobRequest.filePath)
}

// string jobType = 2;
inline void DoJobRequest::clear_jobtype() {
  jobtype_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DoJobRequest::jobtype() const {
  // @@protoc_insertion_point(field_get:DoJobRequest.jobType)
  return jobtype_.GetNoArena();
}
inline void DoJobRequest::set_jobtype(const ::std::string& value) {
  
  jobtype_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DoJobRequest.jobType)
}
#if LANG_CXX11
inline void DoJobRequest::set_jobtype(::std::string&& value) {
  
  jobtype_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:DoJobRequest.jobType)
}
#endif
inline void DoJobRequest::set_jobtype(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  jobtype_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DoJobRequest.jobType)
}
inline void DoJobRequest::set_jobtype(const char* value, size_t size) {
  
  jobtype_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DoJobRequest.jobType)
}
inline ::std::string* DoJobRequest::mutable_jobtype() {
  
  // @@protoc_insertion_point(field_mutable:DoJobRequest.jobType)
  return jobtype_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DoJobRequest::release_jobtype() {
  // @@protoc_insertion_point(field_release:DoJobRequest.jobType)
  
  return jobtype_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DoJobRequest::set_allocated_jobtype(::std::string* jobtype) {
  if (jobtype != NULL) {
    
  } else {
    
  }
  jobtype_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), jobtype);
  // @@protoc_insertion_point(field_set_allocated:DoJobRequest.jobType)
}

// -------------------------------------------------------------------

// DoJobResponse

// bool done = 1;
inline void DoJobResponse::clear_done() {
  done_ = false;
}
inline bool DoJobResponse::done() const {
  // @@protoc_insertion_point(field_get:DoJobResponse.done)
  return done_;
}
inline void DoJobResponse::set_done(bool value) {
  
  done_ = value;
  // @@protoc_insertion_point(field_set:DoJobResponse.done)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_mr_2eproto