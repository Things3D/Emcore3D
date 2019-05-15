//
//  T3DAnimationProperties.h
//
//  Created by Rodrigo Galvez on 11/28/18.
//  Copyright © 2018 Things3D. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "T3DDataStructs.h"
#import <GLKit/GLKit.h>

@class T3DObject;
/*!
@class T3DAnimationProperties

@brief Class to perform animations in any T3DObject.

@discussion Materials can be animated separately too (in beta).

@superclass NSObject
*/
@interface T3DAnimationProperties : NSObject

/*!
 * @brief  Property to set the starting position for the animation.
 * @discussion If no position is set then the current position of the model will be taken.
 * @param startPos GLKVector3 to define a 3d point in space.
 */
@property (nonatomic, assign) GLKVector3 startPos;
/*!
 * @brief  Property to set the target position for the animation.
 * @discussion If no position is set then the current position of the model will be taken.
 * @param targetPos GLKVector3 to define a 3d point in space.
 */
@property (nonatomic, assign) GLKVector3 targetPos;
/*!
 * @brief  Property to get the current position for the animation.
 * @param currentPos GLKVector3 to define a 3d point in space.
 */
@property (nonatomic, readonly) GLKVector3 currentPos;

/*!
 * @brief  Property to set the starting scale for the animation.
 * @discussion If no scale is set then the current scale of the model will be taken.
 * @param startScale GLKVector3 to define the width, height and depth scale transformations.
 */
@property (nonatomic, assign) GLKVector3 startScale;
/*!
 * @brief  Property to set the target scale for the animation.
 * @discussion If no scale is set then the current scale of the model will be taken.
 * @param targetScale GLKVector3 to define the width, height and depth scale transformations.
 */
@property (nonatomic, assign) GLKVector3 targetScale;
/*!
 * @brief  Property to get the current scale for the animation.
 * @param currentScale GLKVector3 to define the width, height and depth scale transformations.
 */
@property (nonatomic, readonly) GLKVector3 currentScale;

/*!
 * @brief  Property to set the starting rotation for the animation.
 * @discussion If no rotation is set then the current rotation of the model will be taken.
 * @param startRotation GLKVector3 to define axis for the rotation.
 */
@property (nonatomic, assign) GLKVector3 startRotation;
/*!
 * @brief  Property to set the target rotation for the animation.
 * @discussion If no rotation is set then the current rotation of the model will be taken.
 * @param targetRotation GLKVector3 to define axis for the rotation.
 */
@property (nonatomic, assign) GLKVector3 targetRotation;
/*!
 * @brief  Property to get the current rotation for the animation.
 * @param currentRotation GLKVector3 to define axis for the rotation.
 */
@property (nonatomic, readonly) GLKVector3 currentRotation;

/*!
 * @brief  Property to set the fixed up rotation for the animation.
 * @discussion When setting this value the normal rotation animation will be ignored and the model will rotate always around the up vector of the world.
 * @param fixedUpRotation Float to define the rotation for the up axis (full rotation is 360).
 */
@property (nonatomic, assign) float fixedUpRotation;
/*!
 * @brief  Property to make the object stay in the current position relative to the camera.
 * @discussion When you enable this option you can move around objects with the position of the camera, really useful with AR.
 * @param followCamera
 */
@property (nonatomic, assign) BOOL followCamera;
/*!
 * @brief  Property to set the distance from the camera when followCamera is active.
 * @discussion When you enable this option you can move around objects with the position of the camera, really useful with AR.
 * @param distanceFromCamera 1.0 = 1mt
 */
@property (nonatomic, assign) float distanceFromCamera;
/*!
 * @brief  Property to make the current object "face" always look at the camera.
 * @param billBoard
 */
@property (nonatomic, assign) BOOL billBoard;
/*!
 * @brief  Property to get the progress of the animation.
 * @param animProg Defined in values between 0.0 and 1.0
 */
@property (nonatomic, readonly) float progress;

/*!
 * @brief  Property to set the duration of the animation.
 * @param duration Defined in seconds 1.0 = 1sec
 */
@property (nonatomic, assign) float duration;

/*!
 * @brief  Property to know if the animation is active.
 * @param animating
 */
@property (nonatomic, readonly) BOOL animating;
/*!
 * @brief  Property to set if the animation will be repeated after ending.
 * @param loop
 */
@property (nonatomic, assign) BOOL loop;
/*!
 * @brief  Property to set the number of times the animation will be repeated.
 * @param loopNumber If -1 is set then it will be repeated forever.
 */
@property (nonatomic, assign) int loopNumber;
/*!
 * @brief  Property to set if the animation will be mirrowed once it ends.
 * @param pingPong
 */
@property (nonatomic, assign) BOOL pingPong;
/*!
 * @brief  Property to set if the animation values will become the new parameters for the object or if they will be discarded.
 * @param overwriteOriginalValues By default is set to YES
 */
@property (nonatomic, assign) BOOL overwriteOriginalValues;

/*!
 * @brief  Method to instantiate a new Animation.
 * @param theObject The object that will perform the animation.
 * @return instancetype
 */
- (instancetype)initWithObject:(T3DObject*)theObject;
/*!
 * @brief  Method to instantiate a new Animation.
 * @param matName The name of the material in which the animation be will performed.
 * @param theObject The parent object of the material.
 * @return instancetype
 */
- (instancetype)initWithMaterial:(NSString*)matName inObject:(T3DObject*)theObject;

/*!
 * @brief  Method to start the animation.
 * @param duration The duration in seconds (1.0 = 1sec).
 * @param progressBlock The block that will be called once the animation is finished.
 */
- (void)startObjectAnimationWithDuration:(float)duration andCompletionHandler:(void(^)(float animProgress))progressBlock;

/*!
 * @brief  Method to stop the animation.
 * @discussion If overwriteOriginalValues is set to YES then the values at which the animation was stopped will be applied to the object.
 */
- (void)stopCurrentAnimation;

/*!
 * @brief  Method to set the Starting scale based in the original values of the object.
 * @param scale GLKVector3 to define the offset of the original scale.
 */
- (void)setStartScaleFromOriginal:(GLKVector3)scale;
/*!
 * @brief  Method to set the Target scale based in the original values of the object.
 * @param scale GLKVector3 to define the offset of the original scale.
 */
- (void)setTargetScaleFromOriginal:(GLKVector3)scale;
/*!
 * @brief  Method to set the Starting position based in the original values of the object.
 * @param translation GLKVector3 to define the offset of the original position.
 */
- (void)setStartPositionFromOriginal:(GLKVector3)translation;
/*!
 * @brief  Method to set the Target position based in the original values of the object.
 * @param translation GLKVector3 to define the offset of the original position.
 */
- (void)setTargetPositionFromOriginal:(GLKVector3)translation;
/*!
 * @brief  Method to set the Starting rotation based in the original values of the object.
 * @param rotation GLKVector3 to define the offset of the original rotation.
 */
- (void)setStartRotationFromOriginal:(GLKVector3)rotation;
/*!
 * @brief  Method to set the Target rotation based in the original values of the object.
 * @param rotation GLKVector3 to define the offset of the original rotation.
 */
- (void)setTargetRotationFromOriginal:(GLKVector3)rotation;

/*!
 * @brief  Method to set the starting values for the scale animation based on the original scale of the object by a power factor.
 * @param scale
 */
- (void)setUniformStartScaleFromOriginal:(float)scale;
/*!
 * @brief  Method to set the target values for the scale animation based on the original scale of the object by a power factor.
 * @param scale
 */
- (void)setUniformTargetScaleFromOriginal:(float)scale;

/*!
 * @brief  Method to create a prefilled custom animation.
 * @param animType The T3DObjectAnimation enumeration type that will be baked.
 * @param theObject The T3DObject in which the animation will be applied.
 * @return T3DAnimationProperties
 */
+ (T3DAnimationProperties*)bakeAnimationForType:(T3DObjectAnimation)animType withObject:(T3DObject*)theObject;

@end
