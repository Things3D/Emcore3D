//
//  T3DGeometryObject.h
//
//  Created by Rodrigo Galvez on 8/15/17.
//  Copyright © 2017 Things3D. All rights reserved.
//

#import "T3DObject.h"

/*!
 @class T3DGeometryObject
 
 @brief Class with all the information necessary to render a Geometry shape.
 
 @discussion This class is heavily integrated with ARKit to manage the plane and face logic provided.
 
 @superclass T3DObject
 */
@interface T3DGeometryObject : T3DObject

/*!
 * @brief  Method to init with the geometry type specified.
 * @param geometryType T3DGeometryType enumeration (plane, cube, circle, etc).
 * @return instancetype
 */
- (instancetype)initWithGeometry:(T3DGeometryType)geometryType;

/*!
 * @brief  Property to get the current geometry type for this object.
 * @param geometryType T3DGeometryType enumeration (plane, cube, circle, etc).
 */
@property (nonatomic, readonly) T3DGeometryType geometryType;

/*!
 * @brief  Property to set the color for the geometry.
 * @param color GLKVector4 with the color in rgba format.
 */
@property (nonatomic, assign) GLKVector4 color;
/*!
 * @brief  Property with the geometry dimension.
 * @param dimensions GLKVector3 for the width, height and depth.
 */
@property (nonatomic, assign) GLKVector3 dimensions;
/*!
 * @brief  Property to get the position of the geometry object when an ARAnchor is attached to it.
 * @return GLKVector3.
 */
- (GLKVector3)getPositionOfPlaneAnchorFromCamera;

@end
