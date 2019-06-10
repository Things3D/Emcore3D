//
//  AR Face Mask.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 5/16/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "AR_Face_Mask.h"

@interface AR_Face_Mask () <T3DRenderControllerARDelegate>

@end

@implementation AR_Face_Mask

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self startAR];
    [self setOptions];
}

- (void)startAR{
    self.renderController.arDelegate = self;
    T3DARKitAvailability availability = [self.renderController startARKitWithConfiguration:T3DARConfigurationFaceTracking withCompletion:nil];
    [Manager checkARAvailability:availability presentInVC:self];
}

- (void)setOptions{
    Option *fireOption = [Option createOptionWithType:OptionTypeButton withName:@"Fire : OFF" withMainYESAction:^(Option *option) {
        T3DObject *object = [self.renderController getCurrentObjectSelected];
        NSString *materialName = [object.getMaterialNames firstObject];
        [object changeShader:T3DShaderTypeFire forMaterial:materialName];
    } andSecondaryNOAction:^(Option *option) {
        T3DObject *object = [self.renderController getCurrentObjectSelected];
        NSString *materialName = [object.getMaterialNames firstObject];
        [object changeShader:T3DShaderTypeBlinnPhong forMaterial:materialName];
    }];
    [self.theOptions addObject:fireOption];
}

#pragma mark - T3DRenderControllerARDelegate Method

- (void)T3DARKitDidDetectFace:(T3DAnchor *)faceAnchor{
    //You could add a texture to the face or add any kind of effect
    NSLog(@"Face detected with model identifier %@",faceAnchor.modelIdentifier);
    T3DGeometryObject *geometryObj = [[T3DGeometryObject alloc] initWithGeometry:T3DGeometryTypeFace];
    geometryObj.identifier = faceAnchor.modelIdentifier;
    [self.renderController addT3DObject:geometryObj];
}

@end
