#pragma once

#include "td/utils/buffer.h"
#include "td/utils/Status.h"
#include "td/utils/SharedSlice.h"
#include "td/utils/port/IPAddress.h"
#include "keys/keys.hpp"
#include "ton/ton-types.h"

class LiteClient;

class Tokenizer {
 public:
  Tokenizer(td::BufferSlice data);

  void skipspc();
  bool endl();
  td::Status check_endl() {
    if (!endl()) {
      return td::Status::Error("extra data after query");
    } else {
      return td::Status::OK();
    }
  }

  td::Result<td::Slice> get_raw_token();
  td::Result<td::Slice> peek_raw_token();

  template <typename T>
  inline td::Result<T> get_token() {
    TRY_RESULT(S, get_raw_token());
    return td::to_integer_safe<T>(S);
  }
  template <typename T>
  inline td::Result<std::vector<T>> get_token_vector();

 private:
  td::BufferSlice data_;
  td::Slice remaining_;
};

template <>
inline td::Result<td::Slice> Tokenizer::get_token() {
  return get_raw_token();
}

template <>
inline td::Result<std::string> Tokenizer::get_token() {
  TRY_RESULT(S, get_raw_token());
  return S.str();
}

template <>
inline td::Result<td::BufferSlice> Tokenizer::get_token() {
  TRY_RESULT(S, get_raw_token());
  TRY_RESULT(F, td::hex_decode(S));
  return td::BufferSlice{F};
}

template <>
inline td::Result<td::SharedSlice> Tokenizer::get_token() {
  TRY_RESULT(S, get_raw_token());
  TRY_RESULT(F, td::hex_decode(S));
  return td::SharedSlice{F};
}

template <>
inline td::Result<ton::PublicKeyHash> Tokenizer::get_token() {
  TRY_RESULT(S, get_raw_token());
  TRY_RESULT(F, td::hex_decode(S));
  if (F.size() == 32) {
    return ton::PublicKeyHash{td::Slice{F}};
  } else {
    return td::Status::Error("cannot parse keyhash: bad length");
  }
}

template <>
inline td::Result<td::IPAddress> Tokenizer::get_token() {
  TRY_RESULT(S, get_raw_token());
  td::IPAddress addr;
  TRY_STATUS(addr.init_host_port(S.str()));
  return addr;
}

template <>
inline td::Result<ton::BlockIdExt> Tokenizer::get_token();

template <typename T>
inline td::Result<std::vector<T>> Tokenizer::get_token_vector() {
  TRY_RESULT(word, get_token<std::string>());
  if (word != "[") {
    return td::Status::Error("'[' expected");
  }

  std::vector<T> res;
  while (true) {
    TRY_RESULT(w, peek_raw_token());

    if (w == "]") {
      get_raw_token();
      return res;
    }
    TRY_RESULT(val, get_token<T>());
    res.push_back(std::move(val));
  }
}

class QueryRunner {
 public:
  virtual ~QueryRunner() = default;
  virtual std::string name() const = 0;
  virtual std::string help() const = 0;
  virtual td::Status run(td::actor::ActorId<LiteClient> client, Tokenizer tokenizer) const = 0;
};

template <class T>
class QueryRunnerImpl : public QueryRunner {
 public:
  std::string name() const override {
    return T::get_name();
  }
  std::string help() const override {
    return T::get_help();
  }
  td::Status run(td::actor::ActorId<LiteClient> client, Tokenizer tokenizer) const override {
    td::actor::create_actor<T>(PSTRING() << "query " << name(), std::move(client), std::move(tokenizer)).release();
    return td::Status::OK();
  }
  QueryRunnerImpl() {
  }
};
