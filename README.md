## Coull In-App SDK

### Installation

The Coull In-App SDK consists of a static library and a number of header files. To install the Coull In-App SDK add the `libCoullsdk.a` to your project along with the following files, all of which are included in the Coull folder in the SDK download.

* CoullMacroHelper.h
* CoullWebService.h
* CoullOverlayView.h
* CoullInlineView.h
* AdContainer.h
* SKMRAIDInterstitial.h
* SKMRAIDServiceDelegate.h
* CoullManager.h
* Close.png
* Close@2x.png

The SDK also requires the `libxml2.2.dylib` and the `CoreLocation` framework.

In your target's build phases make sure that the libCoullSDK.a, the libxml2.2.dyib and the Core Location framwork are all included in **Link Binary With Libraries.** 


###Ad Creation

The Coull SDK allows you to add pre-roll, overlay and interstitial Ads to your apps. 

**To create an Ad, place an AdContainer _on top_ of your preferred video player. **

`The AdContainer is a custom UIView subclass`. You can add it programatically or by choosing it in the storyboard. Make the AdContainer the same size as the video player. 

import the SDK header in your View Controller (or App Delegate)

	#import "CoullSDK/CoullManager.h"


`initialize the SDK` - pubID provided by Coull. For test purposes you can pass `nil`

	self.sdkManager = [[CoullManager alloc] initWithDelegate:self publisherId:pubID];

Now use one of the three init calls. There's one for each Ad type:

`create a preroll ad` - This call allows you to pass in your own Ad Tag rather than using Coull's. Use _nil_ to use Coull's Ad Tags.

	[self.sdkManager createInlineAdForContainingView:AdContainer  withAdTag:(NSString*)adTag];


`create an overlay ad`

	[self.sdkManager createOverlayAdForContainingView:AdContainer];


`create an interstitial ad` - This call also allows you to pass in your own Ad Tag rather than using Coull's. The interestitial Ad doesn't require you to pass in the AdContainer as it will create and manage its own full screen Ad container.

	[self.sdkManager createInterstitialAd:(NSString*)adTag];
	
	
###Checking Ads in Progress

The Coull In-App SDK is designed to work with one Ad at a time. Before trying to create a new Ad you should check whether an Ad is already showing, or about to be shown. The SDK has three properties for this purpose:

- @property (nonatomic, assign) BOOL overlayWillShow;
- @property (nonatomic, assign) BOOL inlineIsShowing;
- @property (nonatomic, assign) BOOL interstitialIsShowing;

If an Ad is showing, or in the case of overlays, about to show after a delay, you should wait before calling a new one. In the event that you want to call Ads in sequence, e.g. a pre-roll followed by an overlay, call the pre-roll first and use the relevant delegate method to call the overlay when the pre-roll completes. See the SDK example app for an example of this behaviour.

	
	
###SDK Delegate Methods

The Coull In-App SDK has a number of callbacks that you can monitor and act upon. These include whether Ads were received, clicked, failed, finished or were stopped.

The following SDK delegate methods are available:

- (void)createdOverlayAd;
- (void)createdInlineAd;
- (void)createdInterstitialAd;
- (void)clickedOverlayAd:(NSURL *)url;
- (void)clickedInlineAd:(NSURL *)url;
- (void)clickedInterstitialAd:(NSURL *)url;
- (void)inlineAdFinished;
- (void)overlayAdFinished;
- (void)interstitialAdFinished;
- (void)inlineAdStopped;
- (void)overlayAdStopped;
- (void)interstitialAdStopped;
- (void)inlineAdFailed;
- (void)overlayAdFailed;
- (void)interstitialAdFailed;

Check the ViewController.m in the Coull SDK example app to see examples of the callbacks being used. In particular it is worth noting the way in which the user's video play/pause state is managed in response to the different ad types.


###Keeping the SDK posted

As the SDK operates independently of any video that you may have running it is important that you keep the SDK notified if one of several events occurs:

the user's video finishes

	[[NSNotificationCenter defaultCenter] postNotificationName:@"VideoPlayerDidFinish" object:nil userInfo:nil];
	
the user's video player enters full screen playback

	[[NSNotificationCenter defaultCenter] postNotificationName:@"VideoPlayerDidEnterFullScreen" object:nil userInfo:nil];

the user's video player exits full screen playback

	[[NSNotificationCenter defaultCenter] postNotificationName:@"VideoPlayerDidExitFullScreen" object:nil userInfo:nil];
	
###Stopping an Ad
If you want to stop an overlay, pre-roll or interstitial Ad for some reason you can call the `stopAd()` method on the SDK.

###Changing the Overlay Delay
The overlays are designed to show 15 seconds after being called. You can change this delay by setting the `overlayDelay` property in the SDK.
	
###Declaring Use of the IDFA

The Coull In-App SDK makes use of the user's unique advertising IDFA where permission has been given by the user. You should declare this use of the IDFA in any app that you submit to iTunes Connect.
	
###Example App

A example app <https://github.com/coull/Coull-InApp-SDK-Example-iOS> showing typical use of the SDK is also available. The app has a very simple UI with elements that you can copy and use in your own apps.

### License

Copyright (c) 2015, Coull Ltd All rights reserved. Provided under BSD-3 license as follows:

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

Neither the name of Coull nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

-------------------------------------------------
