#include "tonlib_api.h"

#include "tl/tl_object_parse.h"
#include "tl/tl_object_store.h"
#include "td/utils/int_types.h"

#include "td/utils/common.h"
#include "td/utils/format.h"
#include "td/utils/logging.h"
#include "td/utils/tl_parsers.h"
#include "td/utils/tl_storers.h"

namespace ton {
namespace tonlib_api {

std::string to_string(const BaseObject &value) {
  td::TlStorerToString storer;
  value.store(storer, "");
  return storer.str();
}

accountAddress::accountAddress()
  : account_address_()
{}

accountAddress::accountAddress(std::string const &account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t accountAddress::ID;

void accountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accountAddress");
    s.store_field("account_address", account_address_);
    s.store_class_end();
  }
}

error::error()
  : code_()
  , message_()
{}

error::error(std::int32_t code_, std::string const &message_)
  : code_(code_)
  , message_(std::move(message_))
{}

const std::int32_t error::ID;

void error::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "error");
    s.store_field("code", code_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

ok::ok() {
}

const std::int32_t ok::ID;

void ok::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ok");
    s.store_class_end();
  }
}

privateKey::privateKey()
  : key_()
{}

privateKey::privateKey(std::string const &key_)
  : key_(std::move(key_))
{}

const std::int32_t privateKey::ID;

void privateKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privateKey");
    s.store_bytes_field("key", key_);
    s.store_class_end();
  }
}

publicKey::publicKey()
  : key_()
{}

publicKey::publicKey(std::string const &key_)
  : key_(std::move(key_))
{}

const std::int32_t publicKey::ID;

void publicKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicKey");
    s.store_bytes_field("key", key_);
    s.store_class_end();
  }
}

generic_accountStateRaw::generic_accountStateRaw()
  : account_state_()
{}

generic_accountStateRaw::generic_accountStateRaw(object_ptr<raw_accountState> &&account_state_)
  : account_state_(std::move(account_state_))
{}

const std::int32_t generic_accountStateRaw::ID;

void generic_accountStateRaw::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "generic_accountStateRaw");
    if (account_state_ == nullptr) { s.store_field("account_state", "null"); } else { account_state_->store(s, "account_state"); }
    s.store_class_end();
  }
}

generic_accountStateTestWallet::generic_accountStateTestWallet()
  : account_state_()
{}

generic_accountStateTestWallet::generic_accountStateTestWallet(object_ptr<testWallet_accountState> &&account_state_)
  : account_state_(std::move(account_state_))
{}

const std::int32_t generic_accountStateTestWallet::ID;

void generic_accountStateTestWallet::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "generic_accountStateTestWallet");
    if (account_state_ == nullptr) { s.store_field("account_state", "null"); } else { account_state_->store(s, "account_state"); }
    s.store_class_end();
  }
}

generic_accountStateTestGiver::generic_accountStateTestGiver()
  : account_state_()
{}

generic_accountStateTestGiver::generic_accountStateTestGiver(object_ptr<testGiver_accountState> &&account_state_)
  : account_state_(std::move(account_state_))
{}

const std::int32_t generic_accountStateTestGiver::ID;

void generic_accountStateTestGiver::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "generic_accountStateTestGiver");
    if (account_state_ == nullptr) { s.store_field("account_state", "null"); } else { account_state_->store(s, "account_state"); }
    s.store_class_end();
  }
}

generic_accountStateUninited::generic_accountStateUninited()
  : account_state_()
{}

generic_accountStateUninited::generic_accountStateUninited(object_ptr<uninited_accountState> &&account_state_)
  : account_state_(std::move(account_state_))
{}

const std::int32_t generic_accountStateUninited::ID;

void generic_accountStateUninited::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "generic_accountStateUninited");
    if (account_state_ == nullptr) { s.store_field("account_state", "null"); } else { account_state_->store(s, "account_state"); }
    s.store_class_end();
  }
}

generic_initialAccountStateRaw::generic_initialAccountStateRaw()
  : initital_account_state_()
{}

generic_initialAccountStateRaw::generic_initialAccountStateRaw(object_ptr<raw_initialAccountState> &&initital_account_state_)
  : initital_account_state_(std::move(initital_account_state_))
{}

const std::int32_t generic_initialAccountStateRaw::ID;

void generic_initialAccountStateRaw::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "generic_initialAccountStateRaw");
    if (initital_account_state_ == nullptr) { s.store_field("initital_account_state", "null"); } else { initital_account_state_->store(s, "initital_account_state"); }
    s.store_class_end();
  }
}

generic_initialAccountStateTestWallet::generic_initialAccountStateTestWallet()
  : initital_account_state_()
{}

generic_initialAccountStateTestWallet::generic_initialAccountStateTestWallet(object_ptr<testWallet_initialAccountState> &&initital_account_state_)
  : initital_account_state_(std::move(initital_account_state_))
{}

const std::int32_t generic_initialAccountStateTestWallet::ID;

void generic_initialAccountStateTestWallet::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "generic_initialAccountStateTestWallet");
    if (initital_account_state_ == nullptr) { s.store_field("initital_account_state", "null"); } else { initital_account_state_->store(s, "initital_account_state"); }
    s.store_class_end();
  }
}

raw_accountState::raw_accountState()
  : balance_()
  , code_()
  , data_()
{}

raw_accountState::raw_accountState(std::int64_t balance_, std::string const &code_, std::string const &data_)
  : balance_(balance_)
  , code_(std::move(code_))
  , data_(std::move(data_))
{}

const std::int32_t raw_accountState::ID;

void raw_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "raw_accountState");
    s.store_field("balance", balance_);
    s.store_bytes_field("code", code_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

raw_initialAccountState::raw_initialAccountState()
  : code_()
  , data_()
{}

raw_initialAccountState::raw_initialAccountState(std::string const &code_, std::string const &data_)
  : code_(std::move(code_))
  , data_(std::move(data_))
{}

const std::int32_t raw_initialAccountState::ID;

void raw_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "raw_initialAccountState");
    s.store_bytes_field("code", code_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

testGiver_accountState::testGiver_accountState()
  : balance_()
  , seqno_()
{}

testGiver_accountState::testGiver_accountState(std::int64_t balance_, std::int32_t seqno_)
  : balance_(balance_)
  , seqno_(seqno_)
{}

const std::int32_t testGiver_accountState::ID;

void testGiver_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testGiver_accountState");
    s.store_field("balance", balance_);
    s.store_field("seqno", seqno_);
    s.store_class_end();
  }
}

testWallet_accountState::testWallet_accountState()
  : balance_()
  , seqno_()
{}

testWallet_accountState::testWallet_accountState(std::int64_t balance_, std::int32_t seqno_)
  : balance_(balance_)
  , seqno_(seqno_)
{}

const std::int32_t testWallet_accountState::ID;

void testWallet_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testWallet_accountState");
    s.store_field("balance", balance_);
    s.store_field("seqno", seqno_);
    s.store_class_end();
  }
}

testWallet_initialAccountState::testWallet_initialAccountState()
  : public_key_()
{}

testWallet_initialAccountState::testWallet_initialAccountState(object_ptr<publicKey> &&public_key_)
  : public_key_(std::move(public_key_))
{}

const std::int32_t testWallet_initialAccountState::ID;

void testWallet_initialAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testWallet_initialAccountState");
    if (public_key_ == nullptr) { s.store_field("public_key", "null"); } else { public_key_->store(s, "public_key"); }
    s.store_class_end();
  }
}

uninited_accountState::uninited_accountState()
  : balance_()
{}

uninited_accountState::uninited_accountState(std::int64_t balance_)
  : balance_(balance_)
{}

const std::int32_t uninited_accountState::ID;

void uninited_accountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "uninited_accountState");
    s.store_field("balance", balance_);
    s.store_class_end();
  }
}

createKey::createKey() {
}

const std::int32_t createKey::ID;

void createKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createKey");
    s.store_class_end();
  }
}

generic_getAccountState::generic_getAccountState()
  : account_address_()
{}

generic_getAccountState::generic_getAccountState(object_ptr<accountAddress> &&account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t generic_getAccountState::ID;

void generic_getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "generic_getAccountState");
    if (account_address_ == nullptr) { s.store_field("account_address", "null"); } else { account_address_->store(s, "account_address"); }
    s.store_class_end();
  }
}

generic_sendGrams::generic_sendGrams()
  : private_key_()
  , source_()
  , destination_()
  , amount_()
{}

generic_sendGrams::generic_sendGrams(object_ptr<privateKey> &&private_key_, object_ptr<accountAddress> &&source_, object_ptr<accountAddress> &&destination_, std::int64_t amount_)
  : private_key_(std::move(private_key_))
  , source_(std::move(source_))
  , destination_(std::move(destination_))
  , amount_(amount_)
{}

const std::int32_t generic_sendGrams::ID;

void generic_sendGrams::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "generic_sendGrams");
    if (private_key_ == nullptr) { s.store_field("private_key", "null"); } else { private_key_->store(s, "private_key"); }
    if (source_ == nullptr) { s.store_field("source", "null"); } else { source_->store(s, "source"); }
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

getPublicKey::getPublicKey()
  : private_key_()
{}

getPublicKey::getPublicKey(object_ptr<privateKey> &&private_key_)
  : private_key_(std::move(private_key_))
{}

const std::int32_t getPublicKey::ID;

void getPublicKey::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPublicKey");
    if (private_key_ == nullptr) { s.store_field("private_key", "null"); } else { private_key_->store(s, "private_key"); }
    s.store_class_end();
  }
}

options_setConfig::options_setConfig()
  : config_()
{}

options_setConfig::options_setConfig(std::string const &config_)
  : config_(std::move(config_))
{}

const std::int32_t options_setConfig::ID;

void options_setConfig::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "options_setConfig");
    s.store_field("config", config_);
    s.store_class_end();
  }
}

raw_getAccountAddress::raw_getAccountAddress()
  : initital_account_state_()
{}

raw_getAccountAddress::raw_getAccountAddress(object_ptr<raw_initialAccountState> &&initital_account_state_)
  : initital_account_state_(std::move(initital_account_state_))
{}

const std::int32_t raw_getAccountAddress::ID;

void raw_getAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "raw_getAccountAddress");
    if (initital_account_state_ == nullptr) { s.store_field("initital_account_state", "null"); } else { initital_account_state_->store(s, "initital_account_state"); }
    s.store_class_end();
  }
}

raw_getAccountState::raw_getAccountState()
  : account_address_()
{}

raw_getAccountState::raw_getAccountState(object_ptr<accountAddress> &&account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t raw_getAccountState::ID;

void raw_getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "raw_getAccountState");
    if (account_address_ == nullptr) { s.store_field("account_address", "null"); } else { account_address_->store(s, "account_address"); }
    s.store_class_end();
  }
}

raw_sendMessage::raw_sendMessage()
  : destination_()
  , initial_account_state_()
  , data_()
{}

raw_sendMessage::raw_sendMessage(object_ptr<accountAddress> &&destination_, std::string const &initial_account_state_, std::string const &data_)
  : destination_(std::move(destination_))
  , initial_account_state_(std::move(initial_account_state_))
  , data_(std::move(data_))
{}

const std::int32_t raw_sendMessage::ID;

void raw_sendMessage::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "raw_sendMessage");
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_bytes_field("initial_account_state", initial_account_state_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

runTests::runTests()
  : dir_()
{}

runTests::runTests(std::string const &dir_)
  : dir_(std::move(dir_))
{}

const std::int32_t runTests::ID;

void runTests::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "runTests");
    s.store_field("dir", dir_);
    s.store_class_end();
  }
}

testGiver_getAccountAddress::testGiver_getAccountAddress() {
}

const std::int32_t testGiver_getAccountAddress::ID;

void testGiver_getAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testGiver_getAccountAddress");
    s.store_class_end();
  }
}

testGiver_getAccountState::testGiver_getAccountState() {
}

const std::int32_t testGiver_getAccountState::ID;

void testGiver_getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testGiver_getAccountState");
    s.store_class_end();
  }
}

testGiver_sendGrams::testGiver_sendGrams()
  : destination_()
  , seqno_()
  , amount_()
{}

testGiver_sendGrams::testGiver_sendGrams(object_ptr<accountAddress> &&destination_, std::int32_t seqno_, std::int64_t amount_)
  : destination_(std::move(destination_))
  , seqno_(seqno_)
  , amount_(amount_)
{}

const std::int32_t testGiver_sendGrams::ID;

void testGiver_sendGrams::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testGiver_sendGrams");
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_field("seqno", seqno_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

testWallet_getAccountAddress::testWallet_getAccountAddress()
  : initital_account_state_()
{}

testWallet_getAccountAddress::testWallet_getAccountAddress(object_ptr<testWallet_initialAccountState> &&initital_account_state_)
  : initital_account_state_(std::move(initital_account_state_))
{}

const std::int32_t testWallet_getAccountAddress::ID;

void testWallet_getAccountAddress::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testWallet_getAccountAddress");
    if (initital_account_state_ == nullptr) { s.store_field("initital_account_state", "null"); } else { initital_account_state_->store(s, "initital_account_state"); }
    s.store_class_end();
  }
}

testWallet_getAccountState::testWallet_getAccountState()
  : account_address_()
{}

testWallet_getAccountState::testWallet_getAccountState(object_ptr<accountAddress> &&account_address_)
  : account_address_(std::move(account_address_))
{}

const std::int32_t testWallet_getAccountState::ID;

void testWallet_getAccountState::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testWallet_getAccountState");
    if (account_address_ == nullptr) { s.store_field("account_address", "null"); } else { account_address_->store(s, "account_address"); }
    s.store_class_end();
  }
}

testWallet_init::testWallet_init()
  : private_key_()
{}

testWallet_init::testWallet_init(object_ptr<privateKey> &&private_key_)
  : private_key_(std::move(private_key_))
{}

const std::int32_t testWallet_init::ID;

void testWallet_init::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testWallet_init");
    if (private_key_ == nullptr) { s.store_field("private_key", "null"); } else { private_key_->store(s, "private_key"); }
    s.store_class_end();
  }
}

testWallet_sendGrams::testWallet_sendGrams()
  : private_key_()
  , destination_()
  , seqno_()
  , amount_()
{}

testWallet_sendGrams::testWallet_sendGrams(object_ptr<privateKey> &&private_key_, object_ptr<accountAddress> &&destination_, std::int32_t seqno_, std::int64_t amount_)
  : private_key_(std::move(private_key_))
  , destination_(std::move(destination_))
  , seqno_(seqno_)
  , amount_(amount_)
{}

const std::int32_t testWallet_sendGrams::ID;

void testWallet_sendGrams::store(td::TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testWallet_sendGrams");
    if (private_key_ == nullptr) { s.store_field("private_key", "null"); } else { private_key_->store(s, "private_key"); }
    if (destination_ == nullptr) { s.store_field("destination", "null"); } else { destination_->store(s, "destination"); }
    s.store_field("seqno", seqno_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}
}  // namespace tonlib_api
}  // namespace ton
