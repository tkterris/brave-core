/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */
import {Router} from '../router.m.js';

(function() {
  'use strict';
  
/**
* @fileoverview
* 'settings-sync-subpage' is the settings page content
*/
Polymer({
  is: 'settings-p2p-keys-subpage',

  behaviors: [
    I18nBehavior
  ],

  properties: {
    /**
     * Array of sites to display in the widget.
     * @type {!Array<SiteException>}
     */
    keys: {
      type: Array,
      value() {
        return [];
      },
    },
    showAddp2pKeyDialog_: {
      type: Boolean,
      value: false,
    }
  },
  
  activeDialogAnchor_: null,
  /** @private {?SyncBrowserProxy} */
  
  browserProxy_: null,

  /** @override */
  created: function() {
    this.browserProxy_ = settings.BraveIPFSBrowserProxyImpl.getInstance();
  },

  /*++++++
  * @override */
  ready: function() {
    this.browserProxy_.launchIPFSService().then(
      this.onServiceLaunched_.bind(this));
  },
  
  onServiceLaunched_: function(success) {
    if (!success) {
      const router = Router.getInstance();
      router.navigateTo(router.getRoutes().BRAVE_IPFS);
      return;
    }
    this.updateKeys();
  },

  isDefaultKey_: function(name) {
    return name == 'self';
  },

  onAddKeyTap_: function(item) {
    this.showAddp2pKeyDialog_ = true
  },

  updateKeys: function() {
    this.browserProxy_.getIpnsKeysList().then(keys => {
      this.keys_ = JSON.parse(keys);
    });
  },

  onAddKeyDialogClosed_: function() {
    this.showAddp2pKeyDialog_ = false
    this.updateKeys();
  },

  onKeyDeleteTapped_: function(event) {
    let name_to_remove = event.model.item.name
    var message = this.i18n('ipfsDeleteKeyConfirmation', name_to_remove)
    if (!window.confirm(message))
      return
    this.browserProxy_.RemoveIpnsKey(name_to_remove).then(removed_name => {
      if (!removed_name)
        return;
      if (removed_name === name_to_remove) {
        this.updateKeys()
        return;
      }
    });
  }
});
})();
