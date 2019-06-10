//
//  T3DDataStructs.h
//
//  Created by Rodrigo Galvez on 10/26/15.
//  Copyright © 2015 Things3D. All rights reserved.
//

#ifndef T3DDataStructs_h
#define T3DDataStructs_h

#import <GLKit/GLKit.h>

#define T3DARPlaneIdentifier @"bcjie82495FSHVIWRHIr239rfhweFJEItuf23FMeciu9210"

#pragma mark - Type struct

/*!
 @Typedef T3DLine
 */
typedef struct {
    GLKVector3 point0;//is also center or starting point
    GLKVector3 point1;
    GLKVector3 forwardDir;
}T3DLine;

/*!
 @Typedef T3DObjectCoords
 */
typedef struct {
    float x;
    float y;
    float z;
    float w;
}T3DObjectCoords;

#pragma mark - Enumerations

/*!
 @Typedef T3DMediaState
 */
typedef enum {
    T3DMediaState_REACHED_END,
    T3DMediaState_PAUSED,
    T3DMediaState_STOPPED,
    T3DMediaState_PLAYING,
    T3DMediaState_READY,
    T3DMediaState_PLAYING_FULLSCREEN,
    T3DMediaState_NOT_READY,
    T3DMediaState_ERROR
} T3DMediaState;

/*!
 @Typedef T3DRenderType
 */
typedef enum {
    T3DRenderTypeNormal,
    T3DRenderTypeVR
}T3DRenderType;

/*!
 @Typedef T3DCameraSource
 */
typedef enum {
    T3DCameraSourceBack,
    T3DCameraSourceFront
}T3DCameraSource;

/*!
 @Typedef T3DMaterialMediaType
 */
typedef enum {
    T3DMaterialMediaTypeNone,
    T3DMaterialMediaTypeAudioWave,
    T3DMaterialMediaTypeAudio,
    T3DMaterialMediaTypeVideoPlayer,
    T3DMaterialMediaTypeReplaceImageTexture,
    T3DMaterialMediaTypeTextImageTexture
} T3DMaterialMediaType;

/*!
 @Typedef T3DMediaSyncState
 */
typedef enum {
    SYNC_DEFAULT,
    SYNC_READY,
    SYNC_AHEAD,
    SYNC_BEHIND
} T3DMediaSyncState;

/*!
 @Typedef T3DMediaAspectType
 */
typedef enum {
    T3DMediaAspectTypeFill,
    T3DMediaAspectTypeFit,
    T3DMediaAspectTypeScaleToFill,
    T3DMediaAspectTypeScaleObject
}T3DMediaAspectType;

/*!
 @Typedef T3DSceneObjectType
 */
typedef enum {
    T3DSceneObjectTypeCamera,
    T3DSceneObjectTypeModel,
    T3DSceneObjectTypeLight,
    T3DSceneObjectTypeCustom,
    T3DSceneObjectTypeTextureOffset,
    T3DSceneObjectTypeBubble
}T3DSceneObjectType;

/*!
 @Typedef T3DControlType
 */
typedef enum {
    T3DControlTypeTouch,
    T3DControlTypeGyro,
    T3DControlTypeVirtualStick,
    T3DControlTypeBlueTStick,
    T3DControlTypeTracking,
    T3DControlTypeThrow,
    T3DControlTypeTrackingThrow
}T3DControlType;

/*!
 @Typedef T3DObjectRotationAxis
 */
typedef enum {
    T3DObjectRotationAxisX,
    T3DObjectRotationAxisY,
    T3DObjectRotationAxisZ
}T3DObjectRotationAxis;

/*!
 @Typedef T3DFBXMaterialProperty
 */
typedef enum {
    T3DFBXMaterialPropertyDiffuse,
    T3DFBXMaterialPropertyDiffuseFactor,
    T3DFBXMaterialPropertyEmissive,
    T3DFBXMaterialPropertyEmissiveFactor,
    T3DFBXMaterialPropertyAmbient,
    T3DFBXMaterialPropertyAmbientFactor,
    T3DFBXMaterialPropertySpecular,
    T3DFBXMaterialPropertySpecularFactor,
    T3DFBXMaterialPropertyShininess,
    T3DFBXMaterialPropertyBump,
    T3DFBXMaterialPropertyNormalMap,
    T3DFBXMaterialPropertyTransparentColor,
    T3DFBXMaterialPropertyTransparencyFactor,
    T3DFBXMaterialPropertyReflection,
    T3DFBXMaterialPropertyReflectionFactor
}T3DFBXMaterialProperty;

/*!
 @Typedef T3DMaterialMap
 */
typedef enum {
    T3DMaterialMapDiffuse,
    T3DMaterialMapEmissive,
    T3DMaterialMapAmbient,
    T3DMaterialMapSpecular,
    T3DMaterialMapNormal,
    T3DMaterialMapAlpha
}T3DMaterialMap;

/*!
 @Typedef T3DObjectAnimation
 */
typedef enum {
    T3DObjectAnimationNone,
    T3DObjectAnimationRotate,
    T3DObjectAnimationRotateMagnitude,
    T3DObjectAnimationScaleUpAndlift,
    T3DObjectAnimationScaleUpWidth,
    T3DObjectAnimationScale200AndCenter,
    T3DObjectAnimationFromObjectToUserPos
}T3DObjectAnimation;

/*!
 * @brief T3DResourcePath
 */
typedef enum{
    T3DResourcePathNone,
    T3DResourcePathMainBundle,
    T3DResourcePathDocumentsDirectory,
    T3DResourcePathTempDirectory
}T3DResourcePath;

/*!
 @Typedef T3DObjectEffectType
 */
typedef enum {
    T3DObjectEffectTypeNone,
    T3DObjectEffectTypeBubble,
    T3DObjectEffectTypeBubbleMoving,
    T3DObjectEffectTypeRipple,
    T3DObjectEffectTypeGodRay,
    T3DObjectEffectTypeOutlineEmpty,
    T3DObjectEffectTypeOutlineFill,
    T3DObjectEffectTypeGlow,
    T3DObjectEffectTypePulsingGlow,
    T3DObjectEffectTypeBlur,
    T3DObjectEffectTypeBlurHorizontal,
    T3DObjectEffectTypeBlurVertical,
}T3DObjectEffectType;

/*!
 @Typedef T3DObjectPivot
 */
typedef enum {
    T3DObjectPivotCenter,
    T3DObjectPivotBottom,
    T3DObjectPivotTop,
    T3DObjectPivotLeft,
    T3DObjectPivotRight
}T3DObjectPivot;

/*!
 @Typedef T3DGeometryType
 */
typedef enum {
    T3DGeometryTypePlane,
    T3DGeometryTypeVerticalPlane,
    T3DGeometryTypeCube,
    T3DGeometryTypeCircle,
    T3DGeometryTypeFace,
    T3DGeometryTypeNone,
    T3DGeometryTypeARShutter
}T3DGeometryType;

/*!
 @Typedef T3DWorldUpCoord
 */
typedef enum {
    T3DWorldUpCoordZ,
    T3DWorldUpCoordY,
    T3DWorldUpCoordX
}T3DWorldUpCoord;

/*!
 @Typedef T3DVRCameraType
 */
typedef enum {
    T3DVRCameraTypeNone,
    T3DVRCameraTypeLeft,
    T3DVRCameraTypeRight
}T3DVRCameraType;

/*!
 @Typedef T3DControlOption
 */
typedef enum {
    T3DControlOptionDisableScale,
    T3DControlOptionDisableTranslation,
    T3DControlOptionDisableRotation
}T3DControlOption;

/*!
 @Typedef T3DShadowType
 */
typedef enum {
    T3DShadowNone,
    T3DShadowMap,
    T3DShadowMapOthoProj,
    T3DShadowProjectedGeometry
}T3DShadowType;

/*!
 @Typedef T3DCompassDirection
 */
typedef enum {
    T3DCompassDirectionNorth,
    T3DCompassDirectionNorthEast,
    T3DCompassDirectionNorthWest,
    T3DCompassDirectionEast,
    T3DCompassDirectionWest,
    T3DCompassDirectionSouthEast,
    T3DCompassDirectionSouthWest,
    T3DCompassDirectionSouth
}T3DCompassDirection;

/*!
 @Typedef T3DARConfiguration
 */
typedef enum {
    T3DARConfigurationWorldTracking,
    T3DARConfigurationImageTracking,
    T3DARConfigurationFaceTracking,
    T3DARConfigurationOnlyRotationTracking
}T3DARConfiguration;

/*!
 @Typedef T3DARKitAvailability
 */
typedef enum {
    T3DARKitAvailabilityNone,
    T3DARKitAvailabilityLimitedToRotationOnly,
    T3DARKitAvailabilityFullSupport,
    T3DARKitAvailabilityFaceTrackingNotAvailable,
    T3DARKitAvailabilityImageTrackingNotAvailable
}T3DARKitAvailability;

/*!
 @Typedef T3DShaderType
 */
typedef enum {
    T3DShaderTypeBlinnPhong,
    T3DShaderTypePhong,
    T3DShaderTypeShadow,
    T3DShaderTypeDepth,
    T3DShaderTypeLine,
    T3DShaderTypeCircle,
    T3DShaderTypeToon,
    T3DShaderTypeYellowGradient,
    T3DShaderTypeClay,
    T3DShaderTypeJelly,
    T3DShaderTypeYellowGradientEuroBlinn,
    T3DShaderTypeEffect,
    T3DShaderTypePoint,
    T3DShaderTypeARShutter,
    T3DShaderTypeTextCoords,
    T3DShaderTypeInvertColors,
    T3DShaderTypeSepia,
    T3DShaderTypeBlackAndWhite,
    T3DShaderTypeCamera,
    T3DShaderTypeCameraSepia,
    T3DShaderTypeCameraInvertColors,
    T3DShaderTypeCameraBlackAndWhite,
    T3DShaderTypeEffectOutline,
    T3DShaderTypeEffectNone,
    T3DShaderTypeEffectBlur,
    T3DShaderTypeFire,
    T3DShaderTypeTransparent,
    T3DShaderTypeOriginalRGB,
    T3DShaderTypeBarrel,
    T3DShaderTypeRipple,
    T3DShaderTypeNormals,
    T3DShaderTypeWireFrame
}T3DShaderType;

/*!
 @Typedef T3DPostRenderingEffectType
 */
typedef enum {
    T3DPostRenderingEffectTypeNone,
    T3DPostRenderingEffectTypeBarrel,
    T3DPostRenderingEffectTypeRipple
}T3DPostRenderingEffectType;

/*!
 @Typedef T3DGraphicsAPIType
 */
typedef enum {
    T3DGraphicsAPITypeOpenGL,
    T3DGraphicsAPITypeMetal
}T3DGraphicsAPIType;

/*!
 @Typedef T3DMediaFilter
 */
typedef enum {
    T3DMediaFilterNone,
    T3DMediaFilterInvertColors,
    T3DMediaFilterSepia,
    T3DMediaFilterBlackAndWhite,
    T3DMediaFilterFire,
    T3DMediaFilterTransparent,
    T3DMediaFilterSameAsParentObj
}T3DMediaFilter;

/*!
 @Typedef T3DCullFace
 */
typedef enum {
    T3DCullFaceNone,
    T3DCullFaceBack,
    T3DCullFaceFront
}T3DCullFace;

/*!
 @Typedef T3DDebugRenderOption
 */
typedef enum {
    T3DDebugRenderOptionNone,
    T3DDebugRenderOptionOnlyDiffuse,
    T3DDebugRenderOptionOnlyAmbient,
    T3DDebugRenderOptionOnlySpecular,
    T3DDebugRenderOptionOnlyTransparentMaterials,
    T3DDebugRenderOptionOnlyOpaqueMaterials,
    T3DDebugRenderOptionOnlyMaterialsWithMedia,
    T3DDebugRenderOptionOnlyMaterialsWithoutMedia,
    T3DDebugRenderOptionOnlyMaterialsWithVideoMedia,
    T3DDebugRenderOptionOnlyMaterialsWithAudioMedia,
    T3DDebugRenderOptionOnlyMaterialsWithImageMedia
}T3DDebugRenderOption;

/*!
 @Typedef T3DAttributeType
 */
typedef enum {
    T3DAttributeTypePosition,
    T3DAttributeTypeTexel,
    T3DAttributeTypeNormals,
    T3DAttributeTypeTangentNormals,
    T3DAttributeTypeBarycentric
}T3DAttributeType;

/*!
 @Typedef T3DLightType
 */
typedef enum  {
    T3DLightTypeDirectional,
    T3DLightTypePointLight,
    T3DLightTypeSpotLight,
    T3DLightTypeNone
}T3DLightType;

/*!
 @Typedef T3D2DDirection
 */
typedef enum {
    T3D2DDirectionVertical,
    T3D2DDirectionHorizontal
}T3D2DDirection;

/*!
 @Typedef T3DAxis
 */
typedef enum  {
    T3DAxisX,
    T3DAxisY,
    T3DAxisZ
}T3DAxis;

/*!
 @Typedef T3DTrackingState
 */
typedef enum  {
    T3DTrackingStateNotAvailable,
    T3DTrackingStateLimited,
    T3DTrackingStateNormal
}T3DTrackingState;

/*!
 @Typedef T3DTrackingStateReason
 */
typedef enum  {
    T3DTrackingStateReasonReasonNone,
    T3DTrackingStateReasonInitializing,
    T3DTrackingStateReasonExcessiveMotion,
    T3DTrackingStateReasonInsufficientFeatures,
    T3DTrackingStateReasonRelocalizing,
    T3DTrackingStateReasonLowLight
}T3DTrackingStateReason;

/*!
 @Typedef T3DBlendType
 */
typedef enum  {
    T3DBlendTypeNone,
    T3DBlendTypeFunction,
    T3DBlendTypeFunctionSeparate
}T3DBlendType;

/*!
 @Typedef T3DBlendFunction
 */
typedef enum  {
    T3DBlendFunctionZERO,
    T3DBlendFunctionONE,
    T3DBlendFunctionSRC_COLOR,
    T3DBlendFunctionONE_MINUS_SRC_COLOR,
    T3DBlendFunctionSRC_ALPHA,
    T3DBlendFunctionONE_MINUS_SRC_ALPHA,
    T3DBlendFunctionDST_ALPHA,
    T3DBlendFunctionONE_MINUS_DST_ALPHA,
    T3DBlendFunctionDST_COLOR,
    T3DBlendFunctionONE_MINUS_DST_COLOR,
    T3DBlendFunctionSRC_ALPHA_SATURATE,
    T3DBlendFunctionBLEND_COLOR
}T3DBlendFunction;

/*!
 @Typedef T3DTextCoords
 */
typedef enum  {
    T3DTextCoordsDefault,
    T3DTextCoordsTopLeftCW,
    T3DTextCoordsTopRightCW,
    T3DTextCoordsBottomLeftCW,
    T3DTextCoordsBottomRightCW,
    T3DTextCoordsTopLeftCCW,
    T3DTextCoordsTopRightCCW,
    T3DTextCoordsBottomLeftCCW,
    T3DTextCoordsBottomRightCCW
}T3DTextCoords;

/*!
 @Typedef T3DTrigger
 */
typedef enum  {
    T3DTriggerProximityEntry,
    T3DTriggerProximityExit,
    T3DTriggerProximityContinuous,
    T3DTriggerTouch,
    T3DTriggerTimed
}T3DTrigger;

/*!
 @Typedef T3DAnchorType
 */
typedef enum {
    T3DAnchorTypePlane,
    T3DAnchorTypeImage,
    T3DAnchorTypeFace,
    T3DAnchorTypeObject,
    T3DAnchorTypeNone
}T3DAnchorType;

/*!
 @Typedef T3DObjectType
 */
typedef enum {
    T3DObjectTypeImage,
    T3DObjectTypeVideo,
    T3DObjectTypeAudio,
    T3DObjectTypeMD2Model,
    T3DObjectTypeOBJModel,
    T3DObjectTypeFBXModel,
    T3DObjectTypeGeometry
}T3DObjectType;

/*!
 @Typedef T3DObjectMediaType
 */
typedef enum {
    T3DObjectMediaTypeNone,
    T3DObjectMediaTypeImage,
    T3DObjectMediaTypeVideo,
    T3DObjectMediaTypeAudio,
    T3DObjectMediaTypeText
}T3DObjectMediaType;


#pragma mark - Protocols
/*!
 * @brief Definition for the T3DControlDelegate
 */
@protocol T3DControlDelegate <NSObject>
@optional
/*!
 * @brief Method called when a touch tap event is triggered.
 */
- (void)T3DObjectControlTapDetected;
/*!
 * @brief Method called when a touch double tap event is triggered.
 */
- (void)T3DObjectControlDoubleTapDetected;
/*!
 * @brief Method called when the type of scene object to be controlled changed.
 * @discussion When the type of control is custom or if ARKit is enabled, the double tap event will trigger some changes.
 */
- (void)T3DSceneObjectControlTypeChanged:(T3DSceneObjectType)controlType;
/*!
 * @brief Method called with the test results of a raycast perform on an object.
 * @discussion This will only be triggered when ray cast detection has been enabled on a T3DObject.
 * @param objectIdentifier The idenfier for the object.
 * @param interesection Flag to inform if there was an intersection.
 */
- (void)T3DObjectControlRayCastTestWithObject:(NSString*)objectIdentifier result:(BOOL)interesection;
/*!
 * @brief Method called with the test results of a raycast perform on a material.
 * @discussion This will only be triggered when ray cast detection for a material has been enabled on a T3DObject.
 * @param materialName The name of the material.
 * @param objectIdentifier The idenfier for the object.
 * @param interesection Flag to inform if there was an intersection.
 */
- (void)T3DObjectControlRayCastTestForMaterial:(NSString*)materialName forObject:(NSString*)objectIdentifier result:(BOOL)interesection;
@end

#endif /* T3DDataStructs_h */
