/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_BRAVE_WEBTORRENT_BRAVE_WEBTORRENT_NAVIGATION_THROTTLE_H_
#define BRAVE_BROWSER_BRAVE_WEBTORRENT_BRAVE_WEBTORRENT_NAVIGATION_THROTTLE_H_

#include "base/macros.h"
#include "base/timer/timer.h"
#include "content/public/browser/navigation_throttle.h"
#include "extensions/browser/extension_registry.h"
#include "extensions/browser/extension_registry_observer.h"

namespace content {
class NavigationHandle;
}

namespace extensions {

// This class enables the WebTorrent component when a .torrent
// or magnet file is loaded.
class BraveWebTorrentNavigationThrottle : public content::NavigationThrottle,
                                          public ExtensionRegistryObserver {
 public:
  explicit BraveWebTorrentNavigationThrottle(
      content::NavigationHandle* navigation_handle);
  ~BraveWebTorrentNavigationThrottle() override;

  // content::NavigationThrottle implementation:
  ThrottleCheckResult WillStartRequest() override;
  ThrottleCheckResult WillProcessResponse() override;
  const char* GetNameForLogging() override;

  static bool MaybeLoadWebtorrent(content::BrowserContext* context,
                                  const GURL& url);

 private:
  ThrottleCheckResult CommonWillProcessRequestResponse();
  void ResumeThrottle();

  // ExtensionRegistryObserver:
  void OnExtensionReady(content::BrowserContext* browser_context,
                        const extensions::Extension* extension) override;
  ScopedObserver<ExtensionRegistry, ExtensionRegistryObserver>
      extension_registry_observer_;
  bool resume_pending_;
  base::OneShotTimer timer_;
  DISALLOW_COPY_AND_ASSIGN(BraveWebTorrentNavigationThrottle);
};

}  // namespace extensions

#endif  // BRAVE_BROWSER_BRAVE_WEBTORRENT_BRAVE_WEBTORRENT_NAVIGATION_THROTTLE_H_
