//
//  Haunted_House_VR.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 6/10/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "Haunted_House_VR.h"

@interface Haunted_House_VR () {
    float loadingProgress;
}

@end

@implementation Haunted_House_VR

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self startAR];
}

- (void)startAR{
    T3DARKitAvailability availability = [self.renderController startARKitWithConfiguration:T3DARConfigurationWorldTracking withCompletion:^{
        [self loadModel];
    }];
    [Manager checkARAvailability:availability presentInVC:self];
}

- (void)loadModel{
    T3DObject *objObject = [T3DObject initWithModelRelativePath:@"Assets/OBJ/HauntedHouse/" andLoadFromSource:T3DResourcePathMainBundle];
    objObject.loadingBlock = ^(float progress, T3DObject *object) {
        self->loadingProgress = progress;
        if (progress == 1.0) {
            [self.renderController changeRenderType:T3DRenderTypeVR];
            object.objectRotation.X = -90.0;
            object.objectRotation.Z = 90.0;
            [object changeObjectHeight:2.7];
            object.objectPos.X = -2.0;
            object.objectPos.Y = -0.1;
            object.objectPos.Z = -2.0;
            object.isRenderable = YES;
        }
    };
    objObject.identifier = @"Haunted House Obj";
    [self.renderController addT3DObject:objObject];
    self.renderController.lightActive = YES;
    if ([self.renderController isARKitEnabled]) {
        objObject.isRenderable = NO;
    }
}

@end
