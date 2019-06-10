//
//  OptionsView.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 6/7/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "OptionsView.h"

@interface OptionsView (){
    OptionsViewPlace theViewPlace;
    CGRect viewFrame;
    CGRect closeFrame;
    BOOL animating;
    Option *hideMenu;
}

@end

@implementation OptionsView

+ (OptionsView*)addToView:(UIView*)parentView atPlace:(OptionsViewPlace)viewPlace{
    OptionsView *ov = [[OptionsView alloc] initInPlace:viewPlace];
    ov.backgroundColor = [UIColor colorWithRed:0.3 green:0.3 blue:0.3 alpha:0.5];
    ov.layer.cornerRadius =5.0;
    [parentView addSubview:ov];
    return ov;
}

- (instancetype)initInPlace:(OptionsViewPlace)viewPlace{
    self = [super init];
    if (self){
        theViewPlace = viewPlace;
    }
    return self;
}

- (void)showWithOptions:(NSArray*)options{
    float statusBarHeight = [UIApplication sharedApplication].statusBarFrame.size.height;
    float screenWidth = [UIScreen mainScreen].bounds.size.width;
    float screenHeight = [UIScreen mainScreen].bounds.size.height;
    float viewWidth = [UIScreen mainScreen].bounds.size.width / 3.0;
    float arrayHeight = [self getHeightFromOptions:options];
    float maxHeight = screenHeight - (statusBarHeight * 3);
    float optionsHeight = options == nil ? self.frame.size.height : arrayHeight > maxHeight ? maxHeight : arrayHeight;
    
    if (theViewPlace == RTOptionsViewPlaceRight) {
        viewFrame = CGRectMake(screenWidth - viewWidth, statusBarHeight, viewWidth, optionsHeight);
        closeFrame = CGRectMake(screenWidth, statusBarHeight, viewWidth, optionsHeight);
    } else {
        closeFrame = CGRectMake(-viewWidth, statusBarHeight, viewWidth, optionsHeight);
        viewFrame = CGRectMake(0, statusBarHeight, viewWidth, optionsHeight);
    }
    
    [self.layer removeAllAnimations];
    [self removeSubviews];
    self.frame = closeFrame;
    _visible = YES;
    [UIView animateWithDuration:1.0 animations:^{
        self.frame = self->viewFrame;
    }];
    [self addOptions:options];
}

- (void)addOptions:(NSArray*)options{
    float viewWidth = self.frame.size.width;
    float lastHeight = 0.0;
    float fullHeight = [self getHeightFromOptions:options];
    float maxFrameSize = self.frame.size.height;
    UIView *parentView = self;
    UIScrollView *scrollView = nil;
    if (fullHeight > maxFrameSize) {
        scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, viewWidth, maxFrameSize)];
        [parentView addSubview:scrollView];
        parentView = scrollView;
    }
    for (int y = 0;y < options.count; y++) {
        Option *tmpOption = options[y];
        CGRect frame = CGRectMake(0,lastHeight, viewWidth, [Option getConstantHeight]);
        [tmpOption setOptionInParentView:parentView withFrame:frame];
        lastHeight += [tmpOption getOptionHeight];
    }
    hideMenu = [Option createOptionWithType:OptionTypeButton withName:@"Close Menu" withMainYESAction:^(Option *option) {
        [self hide];
    } andSecondaryNOAction:nil];
    CGRect frame = CGRectMake(0,lastHeight, viewWidth, [Option getConstantHeight]);
    [hideMenu setOptionInParentView:parentView withFrame:frame];
    lastHeight += [Option getConstantHeight];
    scrollView.contentSize = CGSizeMake(viewWidth, lastHeight);
}

- (void)hide{
    [UIView animateWithDuration:1.0 animations:^{
        self.frame = self->closeFrame;
    } completion:^(BOOL finished) {
        if (finished) {
            [self removeSubviews];
            self->_visible = NO;
        }
    }];
}

- (void)removeSubviews{
    for (UIView *view in self.subviews) {
        [view removeFromSuperview];
    }
}

- (float)getHeightFromOptions:(NSArray*)options{
    float lastHeight = 0.0;
    for (int y = 0;y < options.count; y++) {
        Option *tmpOption = options[y];
        lastHeight += [tmpOption getOptionHeight];
    }
    lastHeight += [Option getConstantHeight];
    return lastHeight;
}

@end
