//
//  T3DAnchor.h
//
//  Created by Rodrigo Galvez on 5/10/19.
//  Copyright © 2019 Things3D. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "T3DDataStructs.h"

/*!
 @class T3DAnchor
 
 @brief Class to hold all the relevant information for an anchor to the 3D World.
 
 @discussion This class is only used with ARKit.
 
 @superclass NSObject
 */
@interface T3DAnchor : NSObject

/*!
 * @brief  Property to know what type of anchor it was created from.
 * @param anchorType T3DAnchorType enumeration.
 */
@property (nonatomic, assign) T3DAnchorType anchorType;
/*!
 * @brief  Property to know the anchor identifier.
 * @param anchorIdentifier
 */
@property (nonatomic, strong) NSString *anchorIdentifier;
/*!
 * @brief  Property to get the model identifier to which this anchor is binded.
 * @param modelIdentifier
 */
@property (nonatomic, strong) NSString *modelIdentifier;
/*!
 * @brief  Property to get the position of the anchor.
 * @param position
 */
@property (nonatomic, assign) GLKVector3 position;
/*!
 * @brief  Property to get the size of the anchor.
 * @param size
 */
@property (nonatomic, assign) GLKVector3 size;
/*!
 * @brief  Property to get the center of the anchor.
 * @param center
 */
@property (nonatomic, assign) GLKVector3 center;
/*!
 * @brief  Property to get the faceBlendShapes if it is of type T3DAnchorTypeFace.
 * @param faceBlendShapes
 */
@property (nonatomic, strong) NSDictionary *faceBlendShapes;

@end
