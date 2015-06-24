//
//  CoullOverlayView.h
//  VidlinkrSDK
//
//  Created by Coull on 27/02/2015.
//  Copyright (c) 2015 Coull Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

//The CoullOverlayViewDelegate method declarations

@protocol CoullOverlayViewDelegate <UIWebViewDelegate>

- (void)coullOverlayAdFinished;
- (void)coullOverlayAdStopped;

- (void)webViewDidStartLoad:(UIWebView *)webView;
- (void)webViewDidFinishLoad:(UIWebView *)webView;
- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;

@end

#import "CoullManager.h"

@interface CoullOverlayView : UIWebView

- (id)initWithDelegate:(id)obj publisherId:(NSString*)pid withFrame:(CGRect)covFrame;
- (void)addCloseButton;
- (void)startAdWithHTML:(NSString*)html;
- (void)stopAd;
- (void)adFinished;
- (void)enterFullScreen:(BOOL)fromInit;
- (void)exitFullScreen;
- (void)changeOrientation;

@property (nonatomic, strong) NSString *publisherId;
@property (nonatomic, assign) NSUInteger siteID;
@property (nonatomic, assign) NSUInteger zoneID;
@property (nonatomic, assign) CGRect originalFrame;
@property (nonatomic, assign) CGRect originalBtnFrame;
@property (nonatomic, assign) id <CoullOverlayViewDelegate> delegate;

@end