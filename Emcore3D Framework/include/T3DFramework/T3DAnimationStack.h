//
//  T3DAnimationStack.h
//
//  Created by Rodrigo Galvez on 10/2/16.
//  Copyright (c) 2016 Things3D. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class T3DAnimationStack
 
 @brief Class with all the information of a FBX animation.
 
 @discussion Any instance of this class should not be modified and is purely informative.
 
 @superclass NSObject
 */
@interface T3DAnimationStack : NSObject

/*!
 * @brief  Property with the stack number for this animation.
 * @param stack
 */
@property (nonatomic, assign) int stack;
/*!
 * @brief  Property with the stack name for this animation.
 * @param stack
 */
@property (nonatomic, strong) NSString *stackName;
/*!
 * @brief  Property with the start time for this animation.
 * @param stack
 */
@property (nonatomic, assign) long mStart;
/*!
 * @brief  Property with the end time for this animation.
 * @param stack
 */
@property (nonatomic, assign) long mStop;
/*!
 * @brief  Property with the current time for this animation.
 * @param stack
 */
@property (nonatomic, assign) long mCurrentTime;


@end
