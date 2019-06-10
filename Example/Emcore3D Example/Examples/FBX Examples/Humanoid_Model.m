//
//  Humanoid_Model.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 5/16/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "Humanoid_Model.h"

@interface Humanoid_Model ()

@end

@implementation Humanoid_Model

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self addFBXObject];
    [self setOptions];
}

- (void)addFBXObject{
    T3DObject *fbxObject = [T3DObject initWithModelRelativePath:@"Assets/FBX/Humanoid/" andLoadFromSource:T3DResourcePathMainBundle];
    fbxObject.identifier = @"Humanoid FBX";
    fbxObject.loadingBlock = ^(float progress, T3DObject *object){
        if (progress == 1.0){
            NSArray* animStacks = [object getAllAnimationStack];
            for (int x = 0 ; x < animStacks.count ; x++){
                T3DAnimationStack *animS = animStacks[x];
                Option *animateOption = [Option createOptionWithType:OptionTypeButton withName:animS.stackName withMainYESAction:^(Option *option) {
                    [object setAnimationStack:animS.stack];
                } andSecondaryNOAction:nil];
                [self.theOptions addObject:animateOption];
            }
        }
    };
    [self.renderController addT3DObject:fbxObject];
    self.renderController.lightActive = YES;
}

- (void)setOptions{
    Option *animateOption = [Option createOptionWithType:OptionTypeButton withName:@"Animating : NO" withMainYESAction:^(Option *option) {
        T3DObject *fbxObject = [self.renderController getCurrentObjectSelected];
        [fbxObject playFBXAnimation:option.active];
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:animateOption];
}

@end
