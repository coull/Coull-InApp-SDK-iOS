//
//  CULWebService.h
//  CoullSampler
//
//  Copyright (c) 2014 Coull Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    VASTEventTrackStart,
    VASTEventTrackFirstQuartile,
    VASTEventTrackMidpoint,
    VASTEventTrackThirdQuartile,
    VASTEventTrackFourthQuartile,
    VASTEventTrackComplete,
    VASTEventTrackClose,
    VASTEventTrackPause,
    VASTEventTrackResume
} VASTEvent;

@interface CoullWebService : NSObject

- (id)initWithTrackingEvents:(NSDictionary *)trackingEvents;
- (void)trackEvent:(VASTEvent)vastEvent;
- (void)sendVASTUrlsWithId:(NSArray *)vastUrls;
- (void)sendTrackingRequest:(NSURL *)trackingURL;

@end
