//
//  Manager.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 5/16/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "Manager.h"

@implementation Manager

+ (instancetype)preferences
{
    static dispatch_once_t pred;
    static Manager *shared = nil;
    dispatch_once(&pred, ^{
        shared = [[Manager alloc] init];
    });
    return shared;
}

-(instancetype)init{
    self = [super init];
    if (self) {
        self.licenseKey = @"a1b1758f2f";
    }
    return self;
}

+ (void)checkARAvailability:(T3DARKitAvailability)availability presentInVC:(UIViewController*)vc{
    NSString *warning = nil;
    switch (availability) {
        case T3DARKitAvailabilityNone:
            warning = @"This dievice is not capable of using ARKit";
            break;
        case T3DARKitAvailabilityFaceTrackingNotAvailable:
            warning = @"Face Tracking is not supported on this device";
            break;
        case T3DARKitAvailabilityImageTrackingNotAvailable:
            warning = @"Image Tracking configuration available ONLY from iOS 12 onwards.";
            break;
        case T3DARKitAvailabilityLimitedToRotationOnly:
            warning = @"ARKit enabled, but Tracking will be limited, this device only supports 3 degrees of Freedom (3DOF)";
            break;
        case T3DARKitAvailabilityFullSupport:
        default:
            //Full Support, nothing to do here
            break;
    }

    if (warning != nil) {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"ARKit Availability" message:warning preferredStyle:UIAlertControllerStyleAlert];
        [alert addAction:[UIAlertAction actionWithTitle:@"Got it!" style:UIAlertActionStyleDefault handler:nil]];
        [vc presentViewController:alert animated:YES completion:nil];
    }
    
}

@end
