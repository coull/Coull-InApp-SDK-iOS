//
//  CULMacroHelper.h
//  VidlinkrSDK
//
//  Created by Coull on 02/03/2015.
//  Copyright (c) 2015 Coull. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>
#import <AdSupport/AdSupport.h>
#import <sys/utsname.h>
#import <CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreLocation/CoreLocation.h>

@interface CoullMacroHelper : NSObject <CLLocationManagerDelegate>

- (id)init;

- (NSString*)stringForMacro:(NSString*)macro;

@property (nonatomic, strong) NSMutableDictionary *macroDictionary;

@property (nonatomic, strong) NSString *currentTime;
@property (nonatomic, strong) NSString *randomString;
@property (nonatomic, strong) NSString *userAgent;
@property (nonatomic, strong) NSString *localIPAddress;
@property (nonatomic, strong) NSString *advertisingID;
@property (nonatomic, strong) NSString *adTrackingEnabled;

@property (nonatomic, strong) NSString *deviceOS;
@property (nonatomic, strong) NSString *deviceOSVersion;
@property (nonatomic, strong) NSString *deviceMake;
@property (nonatomic, strong) NSString *deviceModelName;

@property (nonatomic, strong) NSString *appName;
@property (nonatomic, strong) NSString *appVersion;
@property (nonatomic, strong) NSString *networkCarrier;

@property (nonatomic, strong) NSString *latitude;
@property (nonatomic, strong) NSString *longitude;
@property (nonatomic, strong) NSString *locationAccuracy;

@property (nonatomic, strong) NSString *city;
@property (nonatomic, strong) NSString *region;
@property (nonatomic, strong) NSString *country;

@property (nonatomic, strong) NSString *coullClientRef;

@end
