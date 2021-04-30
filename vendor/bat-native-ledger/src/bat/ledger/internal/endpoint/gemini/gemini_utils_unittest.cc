/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ledger/internal/endpoint/gemini/gemini_utils.h"
#include "bat/ledger/global_constants.h"
#include "bat/ledger/ledger.h"
#include "testing/gtest/include/gtest/gtest.h"

// npm run test -- brave_unit_tests --filter=GeminiUtilsTest.*

namespace ledger {
namespace endpoint {
namespace gemini {

class GeminiUtilsTest : public testing::Test {};

const kGeminiApiUrl = "https://api.gemini.com";
const kGeminiSandboxApiUrl = "https://api.sandbox.gemini.com";

const kGeminiOauthUrl = "https://exchange.gemini.com";
const kGeminiSandboxOauthUrl = "https://exchange.sandbox.gemini.com";

TEST(GeminiUtilsTest, GetApiServerUrlDevelopment) {
  ledger::_environment = type::Environment::DEVELOPMENT;
  const std::string url = GetApiServerUrl("/test");
  ASSERT_EQ(url, kGeminiSandboxApiUrl + "/test");
}

TEST(GeminiUtilsTest, GetApiServerUrlStaging) {
  ledger::_environment = type::Environment::STAGING;
  const std::string url = GetApiServerUrl("/test");
  ASSERT_EQ(url, kGeminiSandboxApiUrl + "/test");
}

TEST(GeminiUtilsTest, GetApiServerUrlProduction) {
  ledger::_environment = type::Environment::PRODUCTION;
  const std::string url = GetApiServerUrl("/test");
  ASSERT_EQ(url, kGeminiApiUrl + "/test");
}

TEST(GeminiUtilsTest, GetOauthServerUrlDevelopment) {
  ledger::_environment = type::Environment::DEVELOPMENT;
  const std::string url = GetOauthServerUrl("/test");
  ASSERT_EQ(url, kGeminiSandboxOauthUrl + "/test");
}

TEST(GeminiUtilsTest, GetOauthServerUrlStaging) {
  ledger::_environment = type::Environment::STAGING;
  const std::string url = GetOauthServerUrl("/test");
  ASSERT_EQ(url, kGeminiSandboxOauthUrl + "/test");
}

TEST(GeminiUtilsTest, GetOauthServerUrlProduction) {
  ledger::_environment = type::Environment::PRODUCTION;
  const std::string url = GetOauthServerUrl("/test");
  ASSERT_EQ(url, kGeminiOauthUrl + "/test");
}

}  // namespace gemini
}  // namespace endpoint
}  // namespace ledger
