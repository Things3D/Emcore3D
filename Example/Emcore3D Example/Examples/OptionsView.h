//
//  OptionsView.h
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 6/7/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Option.h"

typedef NS_ENUM (NSInteger, OptionsViewPlace){
    RTOptionsViewPlaceRight,
    RTOptionsViewPlaceLeft
};

NS_ASSUME_NONNULL_BEGIN

@interface OptionsView : UIView

@property (nonatomic, readonly) BOOL visible;

+ (OptionsView*)addToView:(UIView*)parentView atPlace:(OptionsViewPlace)viewPlace;

- (void)showWithOptions:(NSArray*)options;
- (void)hide;

@end

NS_ASSUME_NONNULL_END
