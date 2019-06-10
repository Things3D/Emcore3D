//
//  Option.h
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 6/7/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM (NSInteger, OptionType){
    OptionTypeButton,
    OptionTypeSwitch,
    OptionTypeSlider,
    OptionTypeLabel,
    OptionTypeSeparator
};

@interface Option : NSObject

typedef void (^optionBlock)(Option *option);

@property (nonatomic,strong) NSString *name;
@property (nonatomic,strong) optionBlock triggerAction;
@property (nonatomic,assign) OptionType optionType;

@property (nonatomic, assign) BOOL active;
@property (nonatomic, assign) CGFloat value;
@property (nonatomic, assign) CGFloat minValue;
@property (nonatomic, assign) CGFloat maxValue;
@property (nonatomic, assign) BOOL underlineTextLabel;
@property (nonatomic, assign) NSTextAlignment optionTextAlignment;

- (float)getOptionHeight;
+ (float)getConstantHeight;

- (void)setOptionInParentView:(UIView*)parent withFrame:(CGRect)frame;
+ (Option*)createOptionWithType:(OptionType)type withName:(NSString*)name withMainYESAction:(void(^)(Option* option))mainAction andSecondaryNOAction:(void(^)(Option* option))secondaryAction;

@end
