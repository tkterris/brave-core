/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_ADS_BRAVE_TODAY_ADS_BRAVE_TODAY_AD_FREQUENCY_CAPPING_H_
#define BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_ADS_BRAVE_TODAY_ADS_BRAVE_TODAY_AD_FREQUENCY_CAPPING_H_

#include "bat/ads/internal/ad_events/ad_event_info.h"

namespace ads {

struct AdInfo;

namespace brave_today_ads {

class FrequencyCapping {
 public:
  explicit FrequencyCapping(const AdEventList& ad_events);

  ~FrequencyCapping();

  FrequencyCapping(const FrequencyCapping&) = delete;
  FrequencyCapping& operator=(const FrequencyCapping&) = delete;

  bool IsAdAllowed();

  bool ShouldExcludeAd(const AdInfo& ad);

 private:
  AdEventList ad_events_;
};

}  // namespace brave_today_ads
}  // namespace ads

#endif  // BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_ADS_BRAVE_TODAY_ADS_BRAVE_TODAY_AD_FREQUENCY_CAPPING_H_
