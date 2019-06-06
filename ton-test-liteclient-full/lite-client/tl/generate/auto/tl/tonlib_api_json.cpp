#include "auto/tl/tonlib_api_json.h"

#include "auto/tl/tonlib_api.h"
#include "auto/tl/tonlib_api.hpp"

#include "tl/tl_json.h"

#include "td/utils/base64.h"
#include "td/utils/common.h"
#include "td/utils/Slice.h"

#include <unordered_map>

namespace ton {
namespace tonlib_api{
  using namespace td;
Result<int32> tl_constructor_from_string(tonlib_api::generic_AccountState *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"generic.accountStateRaw", -1387096685},
    {"generic.accountStateTestWallet", -1041955397},
    {"generic.accountStateTestGiver", 1134654598},
    {"generic.accountStateUninited", -908702008}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error("Unknown class");
  }
  return it->second;
}
Result<int32> tl_constructor_from_string(tonlib_api::generic_InitialAccountState *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"generic.initialAccountStateRaw", -1178429153},
    {"generic.initialAccountStateTestWallet", 710924204}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error("Unknown class");
  }
  return it->second;
}
Result<int32> tl_constructor_from_string(tonlib_api::Object *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"accountAddress", 755613099},
    {"error", -1679978726},
    {"ok", -722616727},
    {"privateKey", 463297391},
    {"publicKey", 413487686},
    {"generic.accountStateRaw", -1387096685},
    {"generic.accountStateTestWallet", -1041955397},
    {"generic.accountStateTestGiver", 1134654598},
    {"generic.accountStateUninited", -908702008},
    {"generic.initialAccountStateRaw", -1178429153},
    {"generic.initialAccountStateTestWallet", 710924204},
    {"raw.accountState", 1488305217},
    {"raw.initialAccountState", 777456197},
    {"testGiver.accountState", 1599809521},
    {"testWallet.accountState", -606773112},
    {"testWallet.initialAccountState", 1635297222},
    {"uninited.accountState", -1992757598}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error("Unknown class");
  }
  return it->second;
}
Result<int32> tl_constructor_from_string(tonlib_api::Function *object, const std::string &str) {
  static const std::unordered_map<Slice, int32, SliceHash> m = {
    {"createKey", -1251993772},
    {"generic.getAccountState", -657000446},
    {"generic.sendGrams", -2092059315},
    {"getPublicKey", -1385790953},
    {"options.setConfig", 21225546},
    {"raw.getAccountAddress", -521283849},
    {"raw.getAccountState", 663706721},
    {"raw.sendMessage", 473889461},
    {"runTests", -2039925427},
    {"testGiver.getAccountAddress", -540100768},
    {"testGiver.getAccountState", 267738275},
    {"testGiver.sendGrams", -178493799},
    {"testWallet.getAccountAddress", -1557748223},
    {"testWallet.getAccountState", 654082364},
    {"testWallet.init", -2127143018},
    {"testWallet.sendGrams", -1564093443}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error("Unknown class");
  }
  return it->second;
}
Status from_json(tonlib_api::accountAddress &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "account_address", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.account_address_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::error &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "code", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.code_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "message", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.message_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::ok &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(tonlib_api::privateKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.key_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::publicKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.key_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::generic_accountStateRaw &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "account_state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.account_state_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::generic_accountStateTestWallet &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "account_state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.account_state_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::generic_accountStateTestGiver &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "account_state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.account_state_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::generic_accountStateUninited &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "account_state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.account_state_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::generic_initialAccountStateRaw &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "initital_account_state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.initital_account_state_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::generic_initialAccountStateTestWallet &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "initital_account_state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.initital_account_state_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::raw_accountState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "balance", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.balance_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "code", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.code_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::raw_initialAccountState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "code", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.code_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::testGiver_accountState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "balance", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.balance_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::testWallet_accountState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "balance", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.balance_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::testWallet_initialAccountState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "public_key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.public_key_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::uninited_accountState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "balance", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.balance_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::createKey &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(tonlib_api::generic_getAccountState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "account_address", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.account_address_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::generic_sendGrams &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "private_key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.private_key_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "source", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.source_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "destination", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.destination_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "amount", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.amount_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::getPublicKey &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "private_key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.private_key_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::options_setConfig &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "config", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.config_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::raw_getAccountAddress &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "initital_account_state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.initital_account_state_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::raw_getAccountState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "account_address", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.account_address_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::raw_sendMessage &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "destination", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.destination_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "initial_account_state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.initial_account_state_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "data", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json_bytes(to.data_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::runTests &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "dir", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.dir_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::testGiver_getAccountAddress &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(tonlib_api::testGiver_getAccountState &to, JsonObject &from) {
  return Status::OK();
}
Status from_json(tonlib_api::testGiver_sendGrams &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "destination", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.destination_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "amount", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.amount_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::testWallet_getAccountAddress &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "initital_account_state", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.initital_account_state_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::testWallet_getAccountState &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "account_address", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.account_address_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::testWallet_init &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "private_key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.private_key_, value));
    }
  }
  return Status::OK();
}
Status from_json(tonlib_api::testWallet_sendGrams &to, JsonObject &from) {
  {
    TRY_RESULT(value, get_json_object_field(from, "private_key", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.private_key_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "destination", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.destination_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "seqno", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.seqno_, value));
    }
  }
  {
    TRY_RESULT(value, get_json_object_field(from, "amount", JsonValue::Type::Null, true));
    if (value.type() != JsonValue::Type::Null) {
      TRY_STATUS(from_json(to.amount_, value));
    }
  }
  return Status::OK();
}
void to_json(JsonValueScope &jv, const tonlib_api::accountAddress &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "accountAddress");
  jo << ctie("account_address", ToJson(object.account_address_));
}
void to_json(JsonValueScope &jv, const tonlib_api::error &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "error");
  jo << ctie("code", ToJson(object.code_));
  jo << ctie("message", ToJson(object.message_));
}
void to_json(JsonValueScope &jv, const tonlib_api::ok &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "ok");
}
void to_json(JsonValueScope &jv, const tonlib_api::privateKey &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "privateKey");
  jo << ctie("key", ToJson(JsonBytes{object.key_}));
}
void to_json(JsonValueScope &jv, const tonlib_api::publicKey &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "publicKey");
  jo << ctie("key", ToJson(JsonBytes{object.key_}));
}
void to_json(JsonValueScope &jv, const tonlib_api::generic_AccountState &object) {
  tonlib_api::downcast_call(const_cast<tonlib_api::generic_AccountState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const tonlib_api::generic_accountStateRaw &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "generic.accountStateRaw");
  if (object.account_state_) {
    jo << ctie("account_state", ToJson(object.account_state_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::generic_accountStateTestWallet &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "generic.accountStateTestWallet");
  if (object.account_state_) {
    jo << ctie("account_state", ToJson(object.account_state_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::generic_accountStateTestGiver &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "generic.accountStateTestGiver");
  if (object.account_state_) {
    jo << ctie("account_state", ToJson(object.account_state_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::generic_accountStateUninited &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "generic.accountStateUninited");
  if (object.account_state_) {
    jo << ctie("account_state", ToJson(object.account_state_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::generic_InitialAccountState &object) {
  tonlib_api::downcast_call(const_cast<tonlib_api::generic_InitialAccountState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}
void to_json(JsonValueScope &jv, const tonlib_api::generic_initialAccountStateRaw &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "generic.initialAccountStateRaw");
  if (object.initital_account_state_) {
    jo << ctie("initital_account_state", ToJson(object.initital_account_state_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::generic_initialAccountStateTestWallet &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "generic.initialAccountStateTestWallet");
  if (object.initital_account_state_) {
    jo << ctie("initital_account_state", ToJson(object.initital_account_state_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::raw_accountState &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "raw.accountState");
  jo << ctie("balance", ToJson(JsonInt64{object.balance_}));
  jo << ctie("code", ToJson(JsonBytes{object.code_}));
  jo << ctie("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const tonlib_api::raw_initialAccountState &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "raw.initialAccountState");
  jo << ctie("code", ToJson(JsonBytes{object.code_}));
  jo << ctie("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const tonlib_api::testGiver_accountState &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "testGiver.accountState");
  jo << ctie("balance", ToJson(JsonInt64{object.balance_}));
  jo << ctie("seqno", ToJson(object.seqno_));
}
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_accountState &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "testWallet.accountState");
  jo << ctie("balance", ToJson(JsonInt64{object.balance_}));
  jo << ctie("seqno", ToJson(object.seqno_));
}
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_initialAccountState &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "testWallet.initialAccountState");
  if (object.public_key_) {
    jo << ctie("public_key", ToJson(object.public_key_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::uninited_accountState &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "uninited.accountState");
  jo << ctie("balance", ToJson(JsonInt64{object.balance_}));
}
void to_json(JsonValueScope &jv, const tonlib_api::createKey &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "createKey");
}
void to_json(JsonValueScope &jv, const tonlib_api::generic_getAccountState &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "generic.getAccountState");
  if (object.account_address_) {
    jo << ctie("account_address", ToJson(object.account_address_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::generic_sendGrams &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "generic.sendGrams");
  if (object.private_key_) {
    jo << ctie("private_key", ToJson(object.private_key_));
  }
  if (object.source_) {
    jo << ctie("source", ToJson(object.source_));
  }
  if (object.destination_) {
    jo << ctie("destination", ToJson(object.destination_));
  }
  jo << ctie("amount", ToJson(JsonInt64{object.amount_}));
}
void to_json(JsonValueScope &jv, const tonlib_api::getPublicKey &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "getPublicKey");
  if (object.private_key_) {
    jo << ctie("private_key", ToJson(object.private_key_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::options_setConfig &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "options.setConfig");
  jo << ctie("config", ToJson(object.config_));
}
void to_json(JsonValueScope &jv, const tonlib_api::raw_getAccountAddress &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "raw.getAccountAddress");
  if (object.initital_account_state_) {
    jo << ctie("initital_account_state", ToJson(object.initital_account_state_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::raw_getAccountState &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "raw.getAccountState");
  if (object.account_address_) {
    jo << ctie("account_address", ToJson(object.account_address_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::raw_sendMessage &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "raw.sendMessage");
  if (object.destination_) {
    jo << ctie("destination", ToJson(object.destination_));
  }
  jo << ctie("initial_account_state", ToJson(JsonBytes{object.initial_account_state_}));
  jo << ctie("data", ToJson(JsonBytes{object.data_}));
}
void to_json(JsonValueScope &jv, const tonlib_api::runTests &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "runTests");
  jo << ctie("dir", ToJson(object.dir_));
}
void to_json(JsonValueScope &jv, const tonlib_api::testGiver_getAccountAddress &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "testGiver.getAccountAddress");
}
void to_json(JsonValueScope &jv, const tonlib_api::testGiver_getAccountState &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "testGiver.getAccountState");
}
void to_json(JsonValueScope &jv, const tonlib_api::testGiver_sendGrams &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "testGiver.sendGrams");
  if (object.destination_) {
    jo << ctie("destination", ToJson(object.destination_));
  }
  jo << ctie("seqno", ToJson(object.seqno_));
  jo << ctie("amount", ToJson(JsonInt64{object.amount_}));
}
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_getAccountAddress &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "testWallet.getAccountAddress");
  if (object.initital_account_state_) {
    jo << ctie("initital_account_state", ToJson(object.initital_account_state_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_getAccountState &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "testWallet.getAccountState");
  if (object.account_address_) {
    jo << ctie("account_address", ToJson(object.account_address_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_init &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "testWallet.init");
  if (object.private_key_) {
    jo << ctie("private_key", ToJson(object.private_key_));
  }
}
void to_json(JsonValueScope &jv, const tonlib_api::testWallet_sendGrams &object) {
  auto jo = jv.enter_object();
  jo << ctie("@type", "testWallet.sendGrams");
  if (object.private_key_) {
    jo << ctie("private_key", ToJson(object.private_key_));
  }
  if (object.destination_) {
    jo << ctie("destination", ToJson(object.destination_));
  }
  jo << ctie("seqno", ToJson(object.seqno_));
  jo << ctie("amount", ToJson(JsonInt64{object.amount_}));
}
}  // namespace tonlib_api
}  // namespace ton
