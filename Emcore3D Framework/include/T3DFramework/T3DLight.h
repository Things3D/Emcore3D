//
//  T3DLight.h
//
//  Created by Rodrigo Galvez on 2/9/16.
//  Copyright (c) 2016 Things3D. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>
#import "T3DDataStructs.h"


/*!
 @class T3DLight
 
 @brief Class to hold all the relevant information for a Light object in the 3D World.
 
 @discussion There can only be a total of 3 lights per scene.
 
 @superclass NSObject
 */
@interface T3DLight : NSObject

/*!
 * @brief Property to get/set the type of light.
 * @param lightType T3DLightType enumeration.
 */
@property (nonatomic, assign) T3DLightType lightType;
/*!
 * @brief Property to hold the identifier of this light.
 * @param identifier
 */
@property (nonatomic, strong) NSString *identifier;

/*!
 * @brief Property to enable/disable the light rotating around the object.
 * @discussion This property does not animate the light, its to specify the behaviour with the touch control.
 * @param rotateAroundCenterOfObject
 */
@property (nonatomic, assign) BOOL rotateAroundCenterOfObject;
/*!
 * @brief Property to enable/disable the light being set at the same position than the camera.
 * @param lightFollowsCamera
 */
@property (nonatomic, assign) BOOL lightFollowsCamera;
/*!
 * @brief Property to enable/disable the light on models.
 * @param affectsModels
 */
@property (nonatomic, assign) BOOL affectsModels;
/*!
 * @brief Property to set/get the light position.
 * @param lightPosition
 */
@property (nonatomic, assign) GLKVector3 lightPosition;
/*!
 * @brief Property to set/get the light direction.
 * @param lightLookAt
 */
@property (nonatomic, assign) GLKVector3 lightLookAt;
/*!
 * @brief Property to set/get the light intensities.
 * @discussion Intensities a.k.a the color of the light. Will constantly be adjusted so if you want to change color do it with originalIntensities.
 * @param intensities
 */
@property (nonatomic, assign) GLKVector3 intensities;
/*!
 * @brief Property to set/get the light intensities a.k.a the color of the light.
 * @param originalIntensities
 */
@property (nonatomic, assign) GLKVector3 originalIntensities;
/*!
 * @brief Property to set/get the light attenuation.
 * @discussion Used to calculate the distance from model to light when the light type is point or spot.
 * @param attenuation
 */
@property (nonatomic, assign) CGFloat attenuation;
/*!
 * @brief Property to set/get the light ambient coefficient.
 * @param ambientCoefficient
 */
@property (nonatomic, assign) CGFloat ambientCoefficient;
/*!
 * @brief Property to set/get the light cone angle.
 * @discussion Used to calculate how wide will the spotlight be, only useful for this kind of light.
 * @param coneAngle
 */
@property (nonatomic, assign) CGFloat coneAngle;
/*!
 * @brief Property to make the light direction always face forward.
 * @param lookAtCameraForwardDirection
 */
@property (nonatomic, assign) BOOL lookAtCameraForwardDirection;

/*!
 * @brief Method to get the light type as a string.
 * @param lightType
 * @return NSString
 */
+ (NSString*)getStringFromLightType:(T3DLightType)lightType;

/*!
 * @brief Method to set the light position at the current locale.
 * @param heading Double value representing the north, should be given by the user with help of core location.
 */
- (void)setLightPositionAtSunLocationWithUserHeading:(double)heading;

@end
