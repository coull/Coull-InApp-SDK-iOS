//
//  CoullManager.h
//  CoullSDK
//
//  Created by Coull on 27/02/2015.
//  Copyright (c) 2015 Coull. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "AdContainer.h"
#import "CoullMacroHelper.h"
#import "CoullWebService.h"
#import "CoullOverlayView.h"
#import "CoullInlineView.h"
#import "SKMRAIDInterstitial.h"
#import "SKMRAIDServiceDelegate.h"

@protocol CoullSDKDelegate;

//The main manager class for the CoullSDK

@interface CoullManager : NSObject <CoullInlineViewDelegate, CoullOverlayViewDelegate, SKMRAIDInterstitialDelegate, SKMRAIDServiceDelegate>

@property (nonatomic, assign) id <CoullSDKDelegate> delegate;
@property (nonatomic, strong) NSString *publisherId; //The required unique Publisher ID. Provided by Coull
@property (nonatomic, assign) NSInteger overlayDelay;//The time in seconds before an overlay ad shows (15 secs by default)
@property (nonatomic, assign) BOOL overlayWillShow;
@property (nonatomic, assign) BOOL overlayisShowing;
@property (nonatomic, assign) BOOL inlineIsShowing;
@property (nonatomic, assign) BOOL interstitialIsShowing;

- (id)initWithDelegate:(id)obj publisherId:(NSString*)pid;//the main init method
- (void)createInlineAdForContainingView:(AdContainer *)containingView withAdTag:(NSString*)adTag;//pass in an AdContainer to create a preroll ad
- (void)createInterstitialAd:(NSString*)adTag;
//in both cases above, pass in nil for the AdTag if you want to use Coull's default AdTag.
- (void)createOverlayAdForContainingView:(AdContainer *)containingView;//pass in an AdContainer to create an overlay
- (void)stopAd;

/*
 These properties and methods are used internally by Coull
 */

@property (nonatomic, assign) NSInteger zoneId;
@property (nonatomic, assign) NSInteger siteId;
@property (nonatomic, assign) float size_x;
@property (nonatomic, assign) float size_y;
@property (nonatomic, assign) BOOL isFullScreen;
@property (nonatomic, assign) CGRect originalAdFrame;
@property (nonatomic, strong) UIView *adContainer;
@property (nonatomic, strong) NSString *inlineClickThrough;
@property (nonatomic, strong) NSString *overlayClickThrough;

- (void)sendImpressions;
- (void)sendErrors;
- (void)sendVastTrackingEvent:(VASTEvent)event;
- (void)updateAdPlayedState:(NSInteger)quartile;
- (void)resetTracking;
+ (CoullManager *)getInstance;

@end

@protocol CoullSDKDelegate <NSObject>
@optional

// Ad information is provided through the following callbacks

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


@end

