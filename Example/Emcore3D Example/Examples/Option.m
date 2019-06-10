//
//  Option.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 6/7/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "Option.h"

typedef void (^optionBlockLoad)(int param);

@interface Option (){
    UIButton *button;
    UISlider *slider;
    UILabel *label;
}

@end

@implementation Option

- (instancetype)init{
    self = [super init];
    if (self) {
        self.value = 0.5;
        self.minValue = 0.0;
        self.maxValue = 1.0;
        self.underlineTextLabel = NO;
    }
    return self;
}

-(void)setName:(NSString *)name{
    switch (self.optionType) {
        case OptionTypeButton:
            [button setTitle:name forState:UIControlStateNormal];
            break;
        case OptionTypeSlider:
            label.text = [NSString stringWithFormat:@"%@ - (%.02f)",_name,self.value];
            break;
        case OptionTypeSwitch:
            
            break;
        case OptionTypeLabel:
            
            break;
        default:
            break;
    }
    _name = name;
}

+ (float)getConstantHeight{
    return 30.0;
}

-(float)getOptionHeight{
    float height = 30.0;
    switch (self.optionType) {
        case OptionTypeSlider:
            height += height;
            break;
        case OptionTypeLabel:
        case OptionTypeSwitch:
        case OptionTypeButton:
        default:
            break;
    }
    return height;
}

- (void)performAction{
    if (self.triggerAction) self.triggerAction(self);
}

- (void)sliderChanged:(UISlider*)slider{
    self.value = slider.value;
    if (self.triggerAction) self.triggerAction(self);
}

- (void)setOptionInParentView:(UIView*)parent withFrame:(CGRect)frame{
    switch (self.optionType) {
        case OptionTypeButton:{
            button = [UIButton buttonWithType:UIButtonTypeSystem];
            button.frame = frame;
            [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
            button.titleLabel.textAlignment = self.optionTextAlignment;
            button.titleLabel.font = [UIFont systemFontOfSize:15.0];
            [button setTitle:self.name forState:UIControlStateNormal];
            [button addTarget:self action:@selector(performAction) forControlEvents:UIControlEventTouchUpInside];
            [parent addSubview:button];
        }
            break;
        case OptionTypeSlider:
            label = [[UILabel alloc] initWithFrame:frame];
            label.textColor = [UIColor whiteColor];
            label.font = [UIFont systemFontOfSize:15.0];
            label.textAlignment = self.optionTextAlignment;
            label.text = [NSString stringWithFormat:@"%@ (%.02f)",_name,self.value];
            slider = [[UISlider alloc] initWithFrame:CGRectMake(frame.origin.x, frame.origin.y + frame.size.height, frame.size.width, frame.size.height)];
            [slider addTarget:self action:@selector(sliderChanged:) forControlEvents:UIControlEventValueChanged];
            slider.minimumValue = self.minValue;
            slider.maximumValue = self.maxValue;
            slider.value = self.value;
            [parent addSubview:label];
            [parent addSubview:slider];
            break;
        case OptionTypeSwitch:
            
            break;
        case OptionTypeLabel:
            label = [[UILabel alloc] initWithFrame:frame];
            label.text = _name;
            label.numberOfLines = 2;
            label.adjustsFontSizeToFitWidth = YES;
            label.font = [UIFont systemFontOfSize:15.0];
            label.textAlignment = self.optionTextAlignment;
            label.textColor = [UIColor whiteColor];
            [parent addSubview:label];
            break;
        default:
            break;
    }
    
    if (_underlineTextLabel) [self undelineLabelText:_name];
    
}

- (void)undelineLabelText:(NSString*)text{
    NSDictionary *underlineAttribute = @{NSUnderlineStyleAttributeName: @(NSUnderlineStyleSingle)};
    label.attributedText = [[NSAttributedString alloc] initWithString:text
                                                           attributes:underlineAttribute];
    
}

+ (Option*)createOptionWithType:(OptionType)type withName:(NSString*)name withMainYESAction:(void(^)(Option* option))mainAction andSecondaryNOAction:(void(^)(Option* option))secondaryAction{
    Option *newOption = [[Option alloc] init];
    newOption.optionType = type;
    newOption.name = name;
    switch (type) {
        case OptionTypeSlider:
            newOption.optionTextAlignment = NSTextAlignmentRight;
            break;
        default:
            newOption.optionTextAlignment = NSTextAlignmentCenter;
            break;
    }
    if ([newOption.name rangeOfString:@": ON"].location != NSNotFound || [newOption.name rangeOfString:@": YES"].location != NSNotFound) {
        newOption.active = YES;
    }else{
        newOption.active = NO;
    }
    newOption.triggerAction = ^(Option *option) {
        option.active = !option.active;
        if (secondaryAction != nil) {
            if (option.active) {
                if (mainAction) mainAction(option);
            }else{
                secondaryAction(option);
            }
        }else{
            if (mainAction) mainAction(option);
        }
        if ([option.name rangeOfString:@": ON"].location != NSNotFound) {
            option.name = [option.name stringByReplacingOccurrencesOfString:@": ON" withString:@": OFF"];
        }else if ([option.name rangeOfString:@": YES"].location != NSNotFound) {
            option.name = [option.name stringByReplacingOccurrencesOfString:@": YES" withString:@": NO"];
        }else if ([option.name rangeOfString:@": NO"].location != NSNotFound) {
            option.name = [option.name stringByReplacingOccurrencesOfString:@": NO" withString:@": YES"];
        }else{
            option.name = [option.name stringByReplacingOccurrencesOfString:@": OFF" withString:@": ON"];
        }
    };
    return newOption;
}

@end
