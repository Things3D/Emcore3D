//
//  T3DMaterialProps.h
//
//  Created by Rodrigo Galvez on 5/13/19.
//  Copyright © 2019 Things3D. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class T3DMaterialProps
 
 @brief Class with all the properties for a material.
 
 @discussion With this class you can change and monitor all the states of a material.
 
 @superclass NSObject
 */
@interface T3DMaterialProps : NSObject

/*!
 * @brief  Property that holds the name of the material.
 * @param name
 */
@property (nonatomic, strong) NSString *name;
/*!
 * @brief  Property that holds the name of the main texture (diffuse).
 * @param textureName
 */
@property (nonatomic, strong) NSString *textureName;
/*!
 * @brief  Property that holds the size of the main texture (diffuse).
 * @param textureSize
 */
@property (nonatomic, assign) CGSize textureSize;
/*!
 * @brief  Property that specify if the material can be rendered or not.
 * @param renderable By default set to YES
 */
@property (nonatomic, assign) BOOL renderable;
/*!
 * @brief  Property that specify if the material has transparency.
 * @param hasTransparency
 */
@property (nonatomic, assign) BOOL hasTransparency;
/*!
 * @brief  Property that specify if the main texture can be tiled.
 * @param tiledTextureSupported
 */
@property (nonatomic, assign) BOOL tiledTextureSupported;
/*!
 * @brief  Property to turn on/off the media attached to it (if any).
 * @param matMediaActive
 */
@property (nonatomic, assign) BOOL matMediaActive;
/*!
 * @brief  Property to to inform if there is a texture.
 * @param hasTexture
 */
@property (nonatomic, assign) BOOL hasTexture;
/*!
 * @brief  Property to inform if there is any media attached to this material.
 * @param hasMedia
 */
@property (nonatomic, assign) BOOL hasMedia;
/*!
 * @brief  Property that holds the center position in world space of the material.
 * @param center
 */
@property (nonatomic, assign) GLKVector3 center;
/*!
 * @brief  Property that holds the ambient color values.
 * @param ambient
 */
@property (nonatomic, assign) GLKVector3 ambient;
/*!
 * @brief  Property that holds the diffuse color values.
 * @param diffuse
 */
@property (nonatomic, assign) GLKVector3 diffuse;
/*!
 * @brief  Property that holds the specular color values.
 * @param specular
 */
@property (nonatomic, assign) GLKVector3 specular;
/*!
 * @brief  Property that holds the emissive color values.
 * @param emissive
 */
@property (nonatomic, assign) GLKVector3 emissive;
/*!
 * @brief  Property that holds the dissolve (transparency) factor.
 * @param dissolve
 */
@property (nonatomic, assign) float dissolve;
/*!
 * @brief  Property that holds the specularFactor factor.
 * @param specularFactor
 */
@property (nonatomic, assign) float specularFactor;
/*!
 * @brief  Property that holds the bumpMultiplier factor for normal mapping.
 * @param bumpMultiplier
 */
@property (nonatomic, assign) float bumpMultiplier;
/*!
 * @brief  Property that informs the current media type for this material.
 * @param materialMedia
 */
@property (nonatomic, assign) T3DMaterialMediaType materialMedia;
/*!
 * @brief  Property with the path to the media.
 * @param materialMediaString
 */
@property (nonatomic, strong) NSString *materialMediaString;
/*!
 * @brief  Property to inform the state of the media.
 * @param mediaState
 */
@property (nonatomic, assign) T3DMediaState mediaState;
/*!
 * @brief  Property to inform the state of the media as a string.
 * @param mediaStateString
 */
@property (nonatomic, strong) NSString *mediaStateString;
/*!
 * @brief  Property that holds the type of shader currently applied to the material.
 * @param shaderType
 */
@property (nonatomic, assign) T3DShaderType shaderType;
/*!
 * @brief  Property that holds the name of the current type of shader as a string.
 * @param shaderTypeString
 */
@property (nonatomic, strong) NSString *shaderTypeString;

/*!
 * @brief  Property that holds the offset position.
 * @param materialPositionOffset
 */
@property (nonatomic, assign) GLKVector3 materialPositionOffset;
/*!
 * @brief  Property that holds the offset scale.
 * @param materialScaleOffset
 */
@property (nonatomic, assign) GLKVector3 materialScaleOffset;
/*!
 * @brief  Property that holds the offset rotation.
 * @param materialRotationOffset
 */
@property (nonatomic, assign) GLKVector3 materialRotationOffset;
/*!
 * @brief  Property that holds the offset rotation magnitude (rotation only in the Up vector).
 * @param materialMagnitudeRotationOffset
 */
@property (nonatomic, assign) GLKVector3 materialMagnitudeRotationOffset;

/*!
 * @brief  Property that disable the ambient texture.
 * @param disableAmbientMap
 */
@property (nonatomic, assign) BOOL disableAmbientMap;
/*!
 * @brief  Property that disable the diffuse texture.
 * @param disableDiffuseMap
 */
@property (nonatomic, assign) BOOL disableDiffuseMap;
/*!
 * @brief  Property that disable the specular texture.
 * @param disableSpecularMap
 */
@property (nonatomic, assign) BOOL disableSpecularMap;
/*!
 * @brief  Property that disable the emissive texture.
 * @param disableEmissiveMap
 */
@property (nonatomic, assign) BOOL disableEmissiveMap;
/*!
 * @brief  Property that disable the normal texture.
 * @param disableNormalMap
 */
@property (nonatomic, assign) BOOL disableNormalMap;

/*!
 * @brief  Method to start playing the current media (if any).
 */
- (void)playMedia;
/*!
 * @brief  Method to pause the current media (if any).
 */
- (void)pauseMedia;
/*!
  * @brief  Method to stop playing the current media (if any).
  */
- (void)stopMedia;
/*!
 * @brief  Method to toggle between playing and pausing the media (if any).
 */
- (void)pauseOrUnpauseMedia;
/*!
 * @brief  Method to remove the current media (if any).
 */
- (void)removeMedia;

@end
