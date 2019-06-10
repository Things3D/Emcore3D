//
//  Filters_and_Effects.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 6/7/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "Object_Shaders_And_Camera_Filter.h"

@interface Object_Shaders_And_Camera_Filter (){
    float loadingProgress;
}

@end

@implementation Object_Shaders_And_Camera_Filter

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self.renderController startCameraBackground];
    [self loadModel];
    [self setOptions];
}

- (void)setOptions{
    Option *label = [Option createOptionWithType:OptionTypeLabel withName:@"Shaders :" withMainYESAction:nil andSecondaryNOAction:nil];
    [self.theOptions addObject:label];
    Option *blinnPhongOption = [Option createOptionWithType:OptionTypeButton withName:@"Blinn Phong" withMainYESAction:^(Option *option) {
        self.renderController.shaderType = T3DShaderTypeBlinnPhong;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:blinnPhongOption];
    Option *toonOption = [Option createOptionWithType:OptionTypeButton withName:@"Toon" withMainYESAction:^(Option *option) {
        self.renderController.shaderType = T3DShaderTypeToon;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:toonOption];
    Option *invertOption = [Option createOptionWithType:OptionTypeButton withName:@"Invert Color" withMainYESAction:^(Option *option) {
        self.renderController.shaderType = T3DShaderTypeInvertColors;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:invertOption];
    Option *sepiaOption = [Option createOptionWithType:OptionTypeButton withName:@"Sepia" withMainYESAction:^(Option *option) {
        self.renderController.shaderType = T3DShaderTypeSepia;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:sepiaOption];
    Option *bwOption = [Option createOptionWithType:OptionTypeButton withName:@"Black&White" withMainYESAction:^(Option *option) {
        self.renderController.shaderType = T3DShaderTypeBlackAndWhite;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:bwOption];
    Option *textCoordsOption = [Option createOptionWithType:OptionTypeButton withName:@"Text Coords" withMainYESAction:^(Option *option) {
        self.renderController.shaderType = T3DShaderTypeTextCoords;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:textCoordsOption];
    Option *normalOption = [Option createOptionWithType:OptionTypeButton withName:@"Normals" withMainYESAction:^(Option *option) {
        self.renderController.shaderType = T3DShaderTypeNormals;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:normalOption];
    Option *labelTwo = [Option createOptionWithType:OptionTypeLabel withName:@"Camera filters :" withMainYESAction:nil andSecondaryNOAction:nil];
    [self.theOptions addObject:labelTwo];
    Option *cameraOption = [Option createOptionWithType:OptionTypeButton withName:@"Original" withMainYESAction:^(Option *option) {
        self.renderController.cameraFilter = T3DShaderTypeCamera;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:cameraOption];
    Option *cameraInvertOption = [Option createOptionWithType:OptionTypeButton withName:@"Invert Color" withMainYESAction:^(Option *option) {
        self.renderController.cameraFilter = T3DShaderTypeCameraInvertColors;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:cameraInvertOption];
    Option *cameraSepiaOption = [Option createOptionWithType:OptionTypeButton withName:@"Sepia" withMainYESAction:^(Option *option) {
        self.renderController.cameraFilter = T3DShaderTypeCameraSepia;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:cameraSepiaOption];
    Option *cameraBWOption = [Option createOptionWithType:OptionTypeButton withName:@"Black&White" withMainYESAction:^(Option *option) {
        self.renderController.cameraFilter = T3DShaderTypeCameraBlackAndWhite;
    } andSecondaryNOAction:nil];
    [self.theOptions addObject:cameraBWOption];
}

- (void)loadModel{
    T3DObject *objObject = [T3DObject initWithModelRelativePath:@"Assets/OBJ/Robomonster/" andLoadFromSource:T3DResourcePathMainBundle];
    objObject.identifier = @"Robomonster Obj";
    [self.renderController addT3DObject:objObject];
    self.renderController.lightActive = YES;
}

@end
