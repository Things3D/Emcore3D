//
//  Joker_In_AR.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 5/17/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "Joker_In_AR.h"

@interface Joker_In_AR ()<T3DControlDelegate, T3DRenderControllerARDelegate>{
    BOOL displayModelAtDetectedLocation;
    float loadingProgress;
}

@end

@implementation Joker_In_AR

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    self.renderController.arDelegate = self;
    self.renderController.controlDelegate = self;
    [self startAR];
    [self setOptions];
}

- (void)startAR{
    self.renderController.arDelegate = self;
    T3DARKitAvailability availability = [self.renderController startARKitWithConfiguration:T3DARConfigurationWorldTracking withCompletion:^{
        [self loadModel];
    }];
    [Manager checkARAvailability:availability presentInVC:self];
    if (availability == T3DARKitAvailabilityNone) {
        [self loadModel];
    }
}

- (void)setOptions{
    Option *scan4PlanesOption = [Option createOptionWithType:OptionTypeButton withName:@"Scan for planes" withMainYESAction:^(Option *option) {
        T3DObject *object = [self.renderController getCurrentObjectSelected];
        if (![self.renderController checkSurfaceDetectorStatus]) {
            [self.renderController addARSurfaceDetectorWithSearchingImage:nil andDetectedImage:nil];
            object.isRenderable = NO;
        }
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:scan4PlanesOption];
}

- (void)loadModel{
    T3DObject *objObject = [T3DObject initWithModelRelativePath:@"Assets/OBJ/Joker/" andLoadFromSource:T3DResourcePathMainBundle];
    objObject.loadingBlock = ^(float progress, T3DObject *object) {
        self->loadingProgress = progress;
        if (progress == 1.0) {
            [object changeObjectHeight:0.5];
        }
    };
    objObject.identifier = @"Joker Obj";
    [self.renderController addT3DObject:objObject];
    self.renderController.lightActive = YES;
    if ([self.renderController isARKitEnabled]) {
        [self.renderController addARSurfaceDetectorWithSearchingImage:nil andDetectedImage:nil];
        objObject.isRenderable = NO;
    }
}

#pragma mark - T3DObjectDelegate Methods

- (void)T3DObjectControlTapDetected{
    T3DObject *object = [self.renderController getCurrentObjectSelected];
    if (!object.isValidObject) {
        [self displayMessage:[object validationError] withTitle:@"Error" inVC:self];
        return;
    }
    if (!object.isLoadingComplete) {
        [self displayMessage:[NSString stringWithFormat:@"Loading at %.02f",loadingProgress] withTitle:@"Model is still loading" inVC:self];
        return;
    }
    if ([self.renderController checkSurfaceDetectorStatus]) {
        displayModelAtDetectedLocation = YES;
    }
}

#pragma mark - T3DRenderControllerARDelegate Methods

- (void)T3DARKitHitTestPoint:(GLKVector3)hitPoint withObject:(NSString *)objectIdentifier{
    //NSLog(@"Hit point detected with object : %@ at point : %@",objectIdentifier, NSStringFromGLKVector3(hitPoint));
    if (displayModelAtDetectedLocation) {
        [self.renderController removeARSurfaceDetector];
        T3DObject *object = [self.renderController getCurrentObjectSelected];
        object.isRenderable = YES;
        [object attachToFloorPosition:hitPoint];
        displayModelAtDetectedLocation = NO;
    }
}

@end
