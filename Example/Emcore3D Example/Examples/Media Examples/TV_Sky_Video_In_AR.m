//
//  TV_Sky_Video_In_AR.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 5/17/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "TV_Sky_Video_In_AR.h"

@interface TV_Sky_Video_In_AR ()<T3DControlDelegate, T3DRenderControllerARDelegate>{
    BOOL displayModelAtDetectedLocation;
    float loadingProgress;
}

@end

@implementation TV_Sky_Video_In_AR

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
    Option *playVideoOption = [Option createOptionWithType:OptionTypeButton withName:@"Video playing : NO" withMainYESAction:^(Option *option) {
        T3DObject *object = [self.renderController getCurrentObjectSelected];
        if (option.active) {
            [object playMediaForMaterial:nil];
        }else{
            [object pauseMediaForMaterial:nil];
        }
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:playVideoOption];
    Option *loadVideoOption = [Option createOptionWithType:OptionTypeButton withName:@"Load Video" withMainYESAction:^(Option *option) {
        T3DObject *object = [self.renderController getCurrentObjectSelected];
        [object startVideoFromUserLibraryForMaterial:@"blinn5SG" withFilter:T3DMediaFilterNone withAspectType:T3DMediaAspectTypeScaleObject autoPlay:YES numberOfLoops:0 andMediaEndCallBack:nil];
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:loadVideoOption];
}

- (void)loadModel{
    T3DObject *objObject = [T3DObject initWithModelRelativePath:@"Assets/OBJ/ARMediaCenterQuad/" andLoadFromSource:T3DResourcePathMainBundle];
    objObject.loadingBlock = ^(float progress, T3DObject *object) {
        self->loadingProgress = progress;
        if (progress == 1.0) {
            [object changeObjectHeight:0.5];
            NSString *videoPath = [[NSBundle mainBundle] pathForResource:@"BlueSky" ofType:@"mp4" inDirectory:@"Assets/Media/Video/BlueSky/"];
            [object startVideoDataStreamWithFilePath:videoPath forMaterial:@"blinn5SG" withFilter:T3DMediaFilterNone withAspectType:T3DMediaAspectTypeScaleObject autoPlay:NO numberOfLoops:0 withHTTPHeadersIfRemoteURL:nil andMediaEndCallBack:nil];
        }
    };
    objObject.identifier = @"TV Obj";
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
