/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

package org.chromium.chrome.browser.privacy.settings;

import org.chromium.components.browser_ui.settings.SettingsUtils;
import org.chromium.chrome.R;
import org.chromium.chrome.browser.settings.BravePreferenceFragment;
import android.os.Bundle;

public class BraveBlockTrackersAndAdsPreferences extends BravePreferenceFragment {
	@Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getActivity().setTitle(R.string.brave_ui_brave_rewards);
        SettingsUtils.addPreferencesFromResource(this, R.xml.brave_trackers_ads);
    }

    // @Override
    // public void onActivityCreated(Bundle savedInstanceState) {
    //     super.onActivityCreated(savedInstanceState);
    // }

    // @Override
    // public void onStart() {
    //     super.onStart();
    // }

    // @Override
    // public void onStop() {
    //     super.onStop();
    // }
}
