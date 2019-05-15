//
//  T3DObject.h
//
//  Created by Rodrigo Galvez on 4/16/14.
//  Copyright (c) 2014 Things3D. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>
#import "T3DDataStructs.h"
#import "T3DModelPathInfo.h"
#import "T3DAnimationStack.h"
#import <CoreLocation/CoreLocation.h>
#import "T3DAnimationProperties.h"
#import "T3DMaterialTrigger.h"
#import "T3DMaterialProps.h"

/*!
 @class T3DVertex
 
 @brief Class that hold a 3 vertex accesibility methods.
 
 @superclass T3DObject
 */
@interface T3DVertex : NSObject

/*!
 * @brief  Property to hold the x value of the vector.
 */
@property (nonatomic, assign) float X;
/*!
 * @brief  Property to hold the y value of the vector.
 */
@property (nonatomic, assign) float Y;
/*!
 * @brief  Property to hold the z value of the vector.
 */
@property (nonatomic, assign) float Z;

/*!
 * @brief  Method to set the vector values with a GLKVector3.
 */
- (void)setValuesFrom:(GLKVector3)values;
/*!
 * @brief  Method to get the vector values as GLKVector3.
 * @return GLKVector3
 */
- (GLKVector3)getValuesAsGLKVector3;

@end

@class T3DObject;
/*!
 * @brief Definition for the T3DObjectDelegate
 */
@protocol T3DObjectDelegate <NSObject>
@optional
- (void)T3DObjectIntersectsWithObject:(T3DObject*)object;
@end

/*!
 @class T3DObject
 
 @brief Parent Class for each 3D model.
 
 @discussion This class should be instantiated for every 3D model except for the Geometry Object, that should be instantiated directly.
 
 @superclass NSObject
 */
@interface T3DObject : NSObject

/*!
 * @typedef  Definition for the block that will be reporting the loading progress of a 3D model.
 */
typedef void (^objectLoadingBlock)(float progress,T3DObject* object);

/*!
 * @brief  Property to make media play when the camera is facing the model and pause it when not looking at it.
 */
@property (nonatomic, assign) BOOL playOrPauseMediaWhenCameraFaceModel;
/*!
 * @brief  Property to inform if the camera is looking at the model.
 */
@property (nonatomic, assign) BOOL cameraisLookingAtModel;

/*!
 * @brief  Property to specify if this model have a circle shape.
 */
@property (nonatomic, assign) BOOL isCircle;
/*!
 * @brief  Property to enable/disable debug mode for the physics bounding box (only visible when 3D world is visible).
 */
@property (nonatomic, assign) BOOL debugBoundingBox;

/*!
 * @brief  Property to pause an FBX animation.
 */
@property (nonatomic, assign) BOOL paused;

/*!
 * @brief  Property to inform the type of 3D Object.
 */
@property (nonatomic, assign) T3DObjectType objectType;
/*!
 * @brief  Property that holds the unified object scale (this scale will be applied to the 3 scale values).
 */
@property (nonatomic, assign) float objectScale;
/*!
 * @brief  Property that holds the object scale in a range of 0.0 to 1.0.
 */
@property (nonatomic, assign) float objectScaleABS;

/*!
 * @brief  Property that holds the original object width when it was loaded.
 */
@property (nonatomic, assign) float realObjectWidth;
/*!
 * @brief  Property that holds the original object depth when it was loaded.
 */
@property (nonatomic, assign) float realObjectDepth;
/*!
 * @brief  Property that holds the original object height when it was loaded.
 */
@property (nonatomic, assign) float realObjectHeight;

/*!
 * @brief  Property that specify if the model should be scaled after loading (set to yes when not in AR).
 */
@property (nonatomic, assign) BOOL autoScale;

/*!
 * @brief  Property that holds the current object position in the 3D world.
 */
@property (nonatomic, strong) T3DVertex *objectPos;
/*!
 * @brief  Property that holds the current object rotation.
 */
@property (nonatomic, strong) T3DVertex *objectRotation;
/*!
 * @brief  Property that holds the current object center position in the 3D world.
 */
@property (nonatomic, strong) T3DVertex *objectCenterPos;
/*!
 * @brief  Property that holds the texture offset (you can adjust texture coordinates with this).
 */
@property (nonatomic, strong) T3DVertex *objectTextOffset;
/*!
 * @brief  Property that holds the current object scale for the 3 axis.
 */
@property (nonatomic, strong) T3DVertex *object3DScale;
/*!
 * @brief  Property that holds a reference to the animation properties.
 */
@property (nonatomic, strong) T3DAnimationProperties *animProperties;

/*!
 * @brief  Property that specifies where is the pivot when rotating the model (default is center)
 */
@property (nonatomic, assign) T3DObjectPivot rotationPivot;
/*!
 * @brief  Property that returns the current radius of the model.
 */
@property (nonatomic, assign) float radius;
/*!
 * @brief  Property to specify a cull face mode (default is none).
 */
@property (nonatomic, assign) T3DCullFace cullFace;
/*!
 * @brief  Property to specify a debug render option.
 */
@property (nonatomic, assign) T3DDebugRenderOption debugRenderOption;

/*!
 * @brief  Property to enable/disable the rendering of this model (default YES).
 */
@property (nonatomic, assign) BOOL isRenderable;
/*!
 * @brief  Property to enable/disable ray cast testing in this model.
 */
@property (nonatomic, assign) BOOL isRayCastCollitionEnabled;
/*!
 * @brief  Property to enable/disable shadow casting.
 */
@property (assign, nonatomic) BOOL castShadow;
/*!
 * @brief  Property to enable/disable double faced normals.
 */
@property (assign, nonatomic) BOOL doubleFacedNormals;

/*!
 * @brief  Property to make the object follow the camera position.
 */
@property (assign, nonatomic) BOOL followsCamera;
/*!
 * @brief  Property to set the distance when the model is following the camera.
 */
@property (assign, nonatomic) float distanceFromCamera;

/*!
 * @brief  Property to set the object identifier.
 */
@property (nonatomic, strong) NSString *identifier;

/*!
 * @brief  Property to enable/disable a scale limit.
 */
@property (nonatomic, assign) BOOL limitScale;

/*!
 * @brief  Property to set a loading block.
 */
@property (nonatomic, strong) objectLoadingBlock loadingBlock;
/*!
 * @brief  Property to set a block that will inform how close the camera is to looking at the model center.
 */
@property (nonatomic, strong) void (^objectCenteredByCameraBlock)(float closeToCenter);
/*!
 * @brief  Property to set a block that will inform an FBX animation progress.
 */
@property (nonatomic, strong) void (^objectAnimationProgress)(float overallProgress);
/*!
 * @brief  Property to set a block that will be called when the media is needed to be loaded.
 */
@property (nonatomic, strong) void (^objectMediaLoad)(T3DObject* object);
/*!
 * @brief  Property to set the T3DObjectDelegate.
 */
@property (nonatomic, weak) id <T3DObjectDelegate> objectDelegate;


/*!
 * @brief  Method to create a new instance of a T3DObject.
 * @param modelPathInfo The T3DModelPathInfo instance with all the information needed to load a 3d model.
 * @return instancetype
 */
+ (instancetype)initWithModelPathObject:(T3DModelPathInfo*)modelPathInfo;

/*!
 * @brief  Method to play the media associated with the given material.
 * @param matName The name of the material.
 */
- (void)playMediaForMaterial:(NSString*)matName;
/*!
 * @brief  Method to pause the media associated with the given material.
 * @param matName The name of the material.
 */
- (void)pauseMediaForMaterial:(NSString*)matName;

/*!
 * @brief  Method to stop the media associated with the given material.
 * @param matName The name of the material.
 */
- (void)stopMediaForMaterial:(NSString*)matName;

/*!
 * @brief  Method to set the media volume associated with the given material.
 * @param volume should be a value between 0.0 and 1.0.
 * @param matName The name of the material.
 */
- (void)setMediaVolume:(float)volume forMaterial:(NSString*)matName;

/*!
 * @brief  Method to pause/unpause the media associated with the given material.
 * @param matName The name of the material.
 */
- (void) pauseOrUnpauseForMaterial:(NSString*)matName;

/*!
 * @brief  Method to get the current media aspect ratio if the object was set to scale to it.
 * @return CGPoint
 */
- (CGPoint)getMediaAspectRatio;

/*!
 * @brief  Method to get the reset the media aspect ratio to 1.0.
 */
- (void)resetMediaAspectRatio;
/*!
 * @brief Method to set the position of the model based on a given location relative to the user location.
 * @param location The location where the model should be place.
 * @param currentLocation The current location of the device.
 * @param heading The current compass direction of the device.
 * @param Radius The max distance at which the model will be placed.
 * @param faceCam Specify if the model should rotate to face the camera like when it was loaded.
 */
- (void)setPostionForLocation:(CLLocation*)location withCurrentLocation:(CLLocation*)currentLocation withUserHeading:(double)heading withMaxDistanceRadius:(float)Radius faceCamera:(BOOL)faceCam;
/*!
 * @brief Method to set the position of the model based on a compass direction.
 * @param compassDirection The cardinal position at which the model will be placed.
 * @param Radius The max distance at which the model will be placed.
 * @param faceCam Specify if the model should rotate to face the camera like when it was loaded.
 */
- (void)setPostionFromCompassDirection:(T3DCompassDirection)compassDirection withDistanceRadius:(float)Radius faceCamera:(BOOL)faceCam;

/*!
 * @brief Method to set the position of an object based on another object position.
 * @param object The reference to the center object.
 * @param compass Direction The position relative to the center object.
 * @param rotAxis Specify if the object will be placed horizontally or vertically.
 */
- (void)setPostionRotatingAroundObject:(T3DObject*)object withCompassDirection:(T3DCompassDirection)compassDirection atRotationAxis:(T3D2DDirection)rotAxis;

/*!
 * @brief Method to get all the material names as an array of NSString.
 * @return NSArray
 */
- (NSArray*)getMaterialNames;
/*!
 * @brief Method to get all the material information as an array of T3DMaterialProps.
 * @return NSArray
 */
- (NSArray*)getMaterialsInfo;
/*!
 * @brief Method to get all the information for a material.
 * @param matIdentifier The name of the material.
 * @return T3DMaterialProps
 */
- (T3DMaterialProps*)getMaterialInfoForIdentifier:(NSString*)matIdentifier;
/*!
 * @brief Method to enable/disable rendering for a material.
 * @param enable Flag to enable/disable.
 * @param matName The name of the material.
 */
- (void)enableRender:(BOOL)enable forMaterial:(NSString*)matName;
/*!
 * @brief Method to know the rendering flag for a material.
 * @param matName The name of the material.
 * @return BOOL
 */
- (BOOL)isRenderEnabledForMaterial:(NSString*)matName;
/*!
 * @brief Method to enable/disable ray cast testing for a material.
 * @param enable Flag to enable/disable.
 * @param matName The name of the material.
 */
- (void)enableRayCastDetection:(BOOL)enable forMaterial:(NSString*)matName;
/*!
 * @brief Method to enable/disable the media for a material.
 * @param activate Flag to enable/disable.
 * @param matName The name of the material.
 */
- (void)activateMaterialMedia:(BOOL)activate forMaterial:(NSString*)matName;
/*!
 * @brief Method to know if media is active for a material.
 * @param matName The name of the material.
 * @return BOOL
 */
- (BOOL)isMaterialMediaActiveForMaterial:(NSString*)matName;
/*!
 * @brief Method to change the media filter for a material.
 * @param mediaFilter The T3DMediaFilter enum type to change.
 * @param matName The name of the material.
 */
- (void)changeMediaFilter:(T3DMediaFilter)mediaFilter forMaterial:(NSString*)matName;
/*!
 * @brief Method to change the shader for a material.
 * @param shaderType The T3DShader enum type to change.
 * @param matName The name of the material.
 */
- (void)changeShader:(T3DShaderType)shaderType forMaterial:(NSString*)matName;
/*!
 * @brief Method to change the media aspect type for a material.
 * @param aspectType The T3DMediaAspectType enum type to change.
 * @param matName The name of the material.
 */
- (void)changeMediaAspectType:(T3DMediaAspectType)aspectType forMaterial:(NSString*)matName;
/*!
 * @brief Method to get the media filter type currently applied to a material.
 * @param matName The name of the material.
 * @return T3DMediaFilter
 */
- (T3DMediaFilter)getCurrentMediaFilterForMaterial:(NSString*)matName;
/*!
 * @brief Method to get the media state type for a material.
 * @param matName The name of the material.
 * @return T3DMediaState
 */
- (T3DMediaState)getMediaStateForMaterial:(NSString*)matName;
/*!
 * @brief Method to remove any media associated to a material.
 * @param matName The name of the material.
 */
- (void)removeMediaForMaterial:(NSString*)matName;
/*!
 * @brief Method to get the scale for a material.
 * @param matName The name of the material.
 * @return float
 */
- (float)getScaleForMaterial:(NSString*)matName;

/*!
 * @brief Method to create a new trigger event for a material.
 * @param triggerType The type of event trigger to be added.
 * @param radius The radius of effect for the trigger.
 * @param matName The name of the material.
 * @param facingCamera Specify if the event will be triggered only when the object is facing the camera.
 * @param triggerBlock Specify the action that will be performed when the event is triggered.
 * @return T3DMaterialTrigger
 */
- (T3DMaterialTrigger*)addTriggerWithType:(T3DTrigger)triggerType withRadius:(float)radius forMaterial:(NSString*)matName activeOnlyWhenFacingCamera:(BOOL)facingCamera withCompletion:(void(^)(T3DMaterialTrigger *trigger))triggerBlock;
/*!
 * @brief Method to remove a trigger event for a material.
 * @param triggerType The type of trigger to be removed.
 * @param matName The name of the material.
 */
- (void)removeTriggerWithType:(T3DTrigger)triggerType forMaterial:(NSString*)matName;

/*!
 * @brief Method to get the position of a material with a forward offset.
 * @param matName The name of the material.
 * @param offset The position forward offset.
 * @return GLKVector3
 */
- (GLKVector3)getPositionForMaterial:(NSString*)matName WithForwardOffset:(float)offset;

/*!
 * @brief Method to check if the model has been loaded.
 * @return BOOL
 */
- (BOOL)isLoadingComplete;
/*!
 * @brief Method to add more actions to the loading block.
 * @param loadingBlock The new action to be added.
 */
- (void)addToLoadingBlock:(void(^)(float progress,T3DObject* object))loadingBlock;

/*!
 * @brief Method to load and start a video playback on a material.
 * @param filePath The path to the video file.
 * @param materialName The name of the material.
 * @param mediaFilter The filter that will be applied to the video.
 * @param aspectType The content aspect ratio type that will be applied to the video.
 * @param autoPlay Specify if the video should play immediatly after loading.
 * @param loops The number of times the video should play.
 * @param httpHeaders The headers to be added if the video path is a remote one.
 * @param mediaEndblock The action that will be performed after the video ended.
 */
- (void)startVideoDataStreamWithFilePath:(NSString*)filePath forMaterial:(NSString*)materialName withFilter:(T3DMediaFilter)mediaFilter withAspectType:(T3DMediaAspectType)aspectType autoPlay:(BOOL)autoPlay numberOfLoops:(int)loops withHTTPHeadersIfRemoteURL:(NSDictionary*)httpHeaders andMediaEndCallBack:(void(^)(void))mediaEndblock;
/*!
 * @brief Method to load and start a video from the user library back on a material (images will be filtered).
 * @param materialName The name of the material.
 * @param mediaFilter The filter that will be applied to the video.
 * @param aspectType The content aspect ratio type that will be applied to the video.
 * @param autoPlay Specify if the video should play immediatly after loading.
 * @param loops The number of times the video should play.
 * @param mediaEndblock The action that will be performed after the video ended.
 */
- (void)startVideoFromUserLibraryForMaterial:(NSString*)materialName withFilter:(T3DMediaFilter)mediaFilter withAspectType:(T3DMediaAspectType)aspectType autoPlay:(BOOL)autoPlay numberOfLoops:(int)loops andMediaEndCallBack:(void(^)(void))mediaEndblock;
/*!
 * @brief Method to load and start any media (video or image) from the user library back on a material.
 * @param materialName The name of the material.
 * @param mediaFilter The filter that will be applied to the media.
 * @param aspectType The content aspect ratio type that will be applied to the media.
 * @param autoPlay Specify if the video should play immediatly after loading (only if it is a video).
 * @param loops The number of times the video should play (only if it is a video).
 * @param mediaEndblock The action that will be performed after the video ended (only if it is a video).
 */
- (void)selectMediaFromUsersLibraryToMaterial:(NSString*)materialName withFilter:(T3DMediaFilter)mediaFilter withAspectType:(T3DMediaAspectType)aspectType autoPlay:(BOOL)autoPlay numberOfLoops:(int)loops andMediaEndCallBack:(void(^)(void))mediaEndblock;

/*!
 * @brief Method to get the current media type associated to a material.
 * @param materialName The name of the material.
 * @return T3DMaterialMediaType
 */
- (T3DMaterialMediaType)getMediaTypeForMaterial:(NSString*)materialName;

/*!
 * @brief Method to get the current animation stack for a FBX model.
 * @return T3DAnimationStack
 */
- (T3DAnimationStack*)getCurrentAnimationStack;
/*!
 * @brief Method to get all the animation stacks of a FBX model as an Array.
 * @return NSArray
 */
- (NSArray*)getAllAnimationStack;
/*!
 * @brief Method to set the animation stacks of a FBX model.
 * @param stack The number of the stack
 */
- (void)setAnimationStack:(int)stack;
/*!
 * @brief Method to play the animation of a FBX model.
 * @param play
 */
- (void)playFBXAnimation:(BOOL)play;
/*!
 * @brief Method to know if an animation is being played on a FBX model.
 * @return bool
 */
- (bool)isFBXAnimationPlaying;

/*!
 * @brief Method to set the velocity for the animation of a FBX model.
 * @param animVel Value between 0.0 and 1.0
 */
- (void)setFBXAnimationVelocity:(float)animVel;
/*!
 * @brief Method to get the current stack time duration of a FBX model.
 * @return float
 */
- (float)getCurrentAnimStackDuation;
/*!
 * @brief Method to get the current animation progress of a FBX model.
 * @return float
 */
- (float)getCurrentAnimStackProgress;

/*!
 * @brief Method to load an image to a material.
 * @param filePath The path to the image file.
 * @param materialName The name of the material.
 * @param mediaFilter The filter that will be applied to the image.
 * @param aspectType The content aspect ratio type that will be applied to the image.
 */
- (void)setImageWithFilePath:(NSString*)filePath onMaterial:(NSString*)materialName withFilter:(T3DMediaFilter)mediaFilter withAspectType:(T3DMediaAspectType)aspectType;
/*!
 * @brief Method to load an image to a material.
 * @param image The UIImage to load.
 * @param materialName The name of the material.
 * @param mediaFilter The filter that will be applied to the image.
 * @param aspectType The content aspect ratio type that will be applied to the image.
 */
- (void)setImage:(UIImage*)image onMaterial:(NSString*)materialName withFilter:(T3DMediaFilter)mediaFilter withAspectType:(T3DMediaAspectType)aspectType;
/*!
 * @brief Method to create and load an image with the text given to a material.
 * @param matName The name of the material.
 * @param mediaFilter The filter that will be applied to the image.
 * @param text The text that will appear.
 * @param attributes The attributes of the text.
 */
- (void)replaceTextureInMaterialName:(NSString*)matName withFilter:(T3DMediaFilter)mediaFilter withText:(NSString*)text withAttributes:(NSDictionary *)attributes;
/*!
 * @brief Method to load an image from the user library back on a material (videos will be filtered).
 * @param materialName The name of the material.
 * @param mediaFilter The filter that will be applied to the image.
 * @param aspectType The content aspect ratio type that will be applied to the image.
 */
- (void)setImageFromUserLibraryOnMaterial:(NSString*)materialName withFilter:(T3DMediaFilter)mediaFilter withAspectType:(T3DMediaAspectType)aspectType;

/*!
 * @brief Method to load an audio file on a material.
 * @param filePath The path to the audio file.
 * @param materialName The name of the material.
 * @param autoPlay Specify if the audio should play immediatly after loading.
 * @param loops The number of times the audio should play.
 */
- (void) startAudioWithFilePath:(NSString*)filePath forMaterial:(NSString*)materialName autoPlay:(BOOL)autoPlay numberOfLoops:(int)loops;

/*!
 * @brief Method to know if the object loaded is valid.
 * @return BOOL
 */
- (BOOL)isValidObject;
/*!
 * @brief Method to know the cause of a validation error.
 * @return NSString
 */
- (NSString*)validationError;

/*!
 * @brief Method to know AR is active.
 * @return BOOL
 */
- (BOOL)isAREnabled;
/*!
 * @brief Method to place the object position based on another.
 * @param plane The object (usually a plane) where you want to place the object.
 * @param scaleToPlaneSize Specify if the object scale should be modified.
 */
- (void)placeOnPlane:(T3DObject*)plane scaleToPlaneSize:(BOOL)scale;
/*!
 * @brief Method to change the object height.
 * @param height The height in meters (1.0 = 1mt).
 */
- (void)changeObjectHeight:(float)height;
/*!
 * @brief Method to get current object width.
 * @return float
 */
- (float)currentWidth;
/*!
 * @brief Method to get current object height.
 * @return float
 */
- (float)currentHeight;
/*!
 * @brief Method to get current object depth.
 * @return float
 */
- (float)currentDepth;
/*!
 * @brief Method to set the floor position for this object.
 * @param floorPos The position of the floor
 */
- (void)attachToFloorPosition:(GLKVector3)floorPos;

/*!
 * @brief Method to start a post rendering effect.
 * @param effectType The type of effect to be applied.
 * @param vel The velocity of effect (if not static).
 * @param progressBlock The progress of the effect (if not static).
 */
- (void)startObjectEffectWithType:(T3DObjectEffectType)effectType withVelocity:(float)vel andCompletionHandler:(void(^)(float animProgress))progressBlock;
/*!
 * @brief Method to stop the current post rendering effect.
 */
- (void)stopCurrentEffect;
/*!
 * @brief Method to know if a post rendering effect is active.
 * @return BOOL
 */
- (BOOL)isEffectActive;

@end
