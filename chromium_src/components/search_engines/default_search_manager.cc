/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/search_engines/pref_names.h"

// clang-format off
#define LOADDEFAULTSEARCHENGINEFROMPREFS_BRAVE                                \
  } else if (pref_service_->GetBoolean(kDefaultSearchProviderByExtension)) {  \
    extension_default_search_ = std::move(turl_data);
// clang-format on

#include "../../../../components/search_engines/default_search_manager.cc"

#undef LOADDEFAULTSEARCHENGINEFROMPREFS_BRAVE
