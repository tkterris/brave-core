/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_LEDGER_SRC_BAT_LEDGER_INTERNAL_ENDPOINT_GEMINI_GET_ACCOUNT_GET_ACCOUNT_GEMINI_H_
#define BRAVE_VENDOR_BAT_NATIVE_LEDGER_SRC_BAT_LEDGER_INTERNAL_ENDPOINT_GEMINI_GET_ACCOUNT_GET_ACCOUNT_GEMINI_H_

#include <string>

#include "bat/ledger/ledger.h"

// GET https://gemini.jp/api/link/v1/account/inventory
//
// Success code:
// HTTP_OK (200)
//
// Error codes:
// HTTP_UNAUTHORIZED (401)
//
// Response body:
// {
//   "account_hash": "0123456789",
//   "inventory": [
//     {
//       "currency_code": "JPY",
//       "amount": 1024078,
//       "available": 508000
//     },
//     {
//       "currency_code": "BTC",
//       "amount": 10.24,
//       "available": 4.12
//     },
//     {
//       "currency_code": "ETH",
//       "amount": 10.24,
//       "available": 4.12
//     }
//   ]
// }

namespace ledger {
class LedgerImpl;

namespace endpoint {
namespace gemini {

using PostAccountCallback =
    std::function<void(const type::Result result,
                       const std::string address, 
                       const std::string linking_info,
                       const std::string user_name)>;

class PostAccount {
 public:
  explicit PostAccount(LedgerImpl* ledger);
  ~PostAccount();

  void Request(const std::string& token, PostAccountCallback callback);

 private:
  std::string GetUrl();

  type::Result CheckStatusCode(const int status_code);

  type::Result ParseBody(const std::string& body, 
                         std::string* address,
                         std::string* linking_info,
                         std::string* user_name);

  void OnRequest(const type::UrlResponse& response,
                 PostAccountCallback callback);

  LedgerImpl* ledger_;  // NOT OWNED
};

}  // namespace gemini
}  // namespace endpoint
}  // namespace ledger

#endif  // BRAVE_VENDOR_BAT_NATIVE_LEDGER_SRC_BAT_LEDGER_INTERNAL_ENDPOINT_GEMINI_GET_ACCOUNT_GET_ACCOUNT_GEMINI_H_
