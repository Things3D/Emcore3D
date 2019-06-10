//
//  Manager.h
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 5/16/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "T3DRenderController.h"

NS_ASSUME_NONNULL_BEGIN

@interface Manager : NSObject

+ (instancetype)preferences;
+ (void)checkARAvailability:(T3DARKitAvailability)availability presentInVC:(UIViewController*)vc;

@property (assign, nonatomic) T3DGraphicsAPIType graphicsAPI;
@property (strong, nonatomic) NSString *licenseKey;

@end

NS_ASSUME_NONNULL_END
