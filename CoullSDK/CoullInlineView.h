//
//  CoullInlineView.h
//  VidlinkrSDK
//
//  Created by Coull on 10/03/2015.
//  Copyright (c) 2015 Coull. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

//Inline Ad Delegate methods

@protocol CoullInlineViewDelegate <NSObject>

- (void)coullInlineAdFailed:(id)coullInlineView;
- (void)coullInlineAdWasClicked:(id)coullInlineView;
- (void)coullInlineAdFinished:(id)coullInlineView;
- (void)coullInlineAdStopped:(id)coullInlineView;

@end

#import "CoullManager.h"

@interface CoullInlineView : UIView

- (id)initWithDelegate:(id)obj publisherId:(NSString*)pid;
- (void)startAdWithURL:(NSURL*)url;
- (void)stopAd;
- (void)adFinished;
- (void)adFailed;
- (void)enterFullScreen;
- (void)exitFullScreen;

@property (nonatomic, strong) NSString *publisherId;
@property (nonatomic, assign) id <CoullInlineViewDelegate> delegate;
@property (nonatomic, strong) NSURL *clickThroughURL;

@end