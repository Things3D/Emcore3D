//
//  T3DMaterialTrigger.h
//
//  Created by Rodrigo Galvez on 2/19/19.
//  Copyright © 2019 Things3D. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "T3DDataStructs.h"

NS_ASSUME_NONNULL_BEGIN
@class T3DObject;
/*!
 @class T3DMaterialTrigger
 
 @brief Class to handle all the trigger types for materials.
 
 @discussion Multiple triggers can be applied to a material, but only one for each type.
 
 @superclass NSObject
 */
@interface T3DMaterialTrigger : NSObject

/*!
 * @brief  Definition of the block that will be invoqued when the conditions for this trigger are met.
 * @param trigger This instance will be returned in the callback to adjust the logic according to its properties.
 */
typedef void (^triggerBlock)(T3DMaterialTrigger *trigger);

/*!
 * @brief  Property for the radius of effect for this trigger.
 * @param radius This should be specified in meters 1.0 = 1mt.
 */
@property (nonatomic, assign) float radius;
/*!
 * @brief  Property that will be set to YES when the camera enters the radius.
 * @param didEnter
 */
@property (nonatomic, assign) BOOL didEnter;
/*!
 * @brief  Property that holds the distance between the exterior raidus and the camera.
 * @param proximity
 */
@property (nonatomic, assign) float proximity;
/*!
 * @brief  Property that holds the distance between the center of the material and the camera.
 * @param proximityToInnerRadius
 */
@property (nonatomic, assign) float proximityToInnerRadius;
/*!
 * @brief  Property that holds the full radius (raidus + material current size).
 * @param fullRadius
 */
@property (nonatomic, assign) float fullRadius;
/*!
 * @brief  Property that holds the center position of the material.
 * @param center
 */
@property (nonatomic, assign) GLKVector3 center;
/*!
 * @brief  Property that holds the current type of trigger.
 * @param triggerType
 */
@property (nonatomic, assign) T3DTrigger triggerType;
/*!
 * @brief  Property that holds the block that will be called when the conditions for this trigger are met.
 * @param actionBlock
 */
@property (nonatomic, strong) triggerBlock actionBlock;
/*!
 * @brief  Property that holds a reference to the parent material name.
 * @param parentMaterialName
 */
@property (nonatomic, strong) NSString *parentMaterialName;
/*!
 * @brief  Property that specify if the trigger applies only when the camera is facing the material.
 * @param onlyWhenLookingAtMaterial
 */
@property (nonatomic, assign) BOOL onlyWhenLookingAtMaterial;
/*!
 * @brief  Property that informs if the camera is looking at the parent material.
 * @param isLookingAtMaterial
 */
@property (nonatomic, assign) BOOL isLookingAtMaterial;
/*!
 * @brief  Property that holds a flag that can be set by the user.
 * @param accesibilityFlag
 */
@property (nonatomic, assign) BOOL accesibilityFlag;
/*!
 * @brief  Property that holds a counter that can be set by the user.
 * @param accesibilityCounter
 */
@property (nonatomic, assign) int accesibilityCounter;
/*!
 * @brief  Property that holds the number of times the conditions for this trigger have been met.
 * @param triggerCounter
 */
@property (nonatomic, assign) int triggerCounter;
/*!
 * @brief  Property that holds the target time (Trigger type timed).
 * @param targetTime
 */
@property (nonatomic, assign) float targetTime;
/*!
 * @brief  Property that holds the current time that has passed (will be reset when the target time is met).
 * @param parentObject
 */
@property (nonatomic, assign) float currentTime;
/*!
 * @brief  Property that holds the current progress as a percentage value (0.0~1.0).
 * @param timeProgress
 */
@property (nonatomic, assign) float timeProgress;
/*!
 * @brief  Property that holds a boolean value informing if the trigger has reached the target time.
 * @param timeReached
 */
@property (nonatomic, assign) BOOL timeReached;

/*!
 * @brief  Property that holds a reference to the parent object.
 * @param parentObject
 */
@property (nonatomic, weak) T3DObject *parentObject;

/*!
 * @brief  Method to get the Trigger Type enumaration as a string.
 * @param triggerType The T3DTrigger enumeration.
 * @return NSString
 */
- (NSString*)triggerTypeStringFromTriggerType:(T3DTrigger)triggerType;

@end

NS_ASSUME_NONNULL_END
