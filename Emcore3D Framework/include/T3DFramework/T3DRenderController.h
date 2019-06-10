//
//  T3DRenderController.h
//
//  Created by Rodrigo Galvez on 3/17/16.
//  Copyright (c) 2016 Things3D. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ARKit/ARKit.h>
#import "T3DLight.h"
#import "T3DAnchor.h"
#import "T3DDataStructs.h"
#import "T3DGeometryObject.h"

/*!
 * @protocol T3DRenderControllerDelegate
 * @brief  Definition for the T3DRenderControllerDelegate.
 */
@protocol T3DRenderControllerDelegate <NSObject>
@optional
/*!
 * @brief  Method that will be called each second returning the fps.
 * @param frames The number of frames rendered the last second.
 */
- (void)framesPerSecond:(int)frames;
/*!
 * @brief  Method that will be called when an Image was recognized by a MTL model provided.
 * @param results The results of the recognized image, depending on the model it can have multiple results with a confidence percentage.
 */
- (void)T3DDidRecognizeImageWithResults:(NSDictionary*)results;
@end

/*!
 * @protocol T3DRenderControllerARDelegate
 * @brief  Definition for the T3DRenderControllerARDelegate.
 */
@protocol T3DRenderControllerARDelegate <NSObject>
@optional
- (void)T3DARKitDidChangeTrackingState:(T3DTrackingState)state WithTrackingStateReason:(T3DTrackingStateReason)reason;
/*!
 * @brief  Method that will be called when a plane is detected, you are responsable to add a T3DGeometry object or any other to the scene.
 * @discussion if you want the framework to manage the position of an object based on the plane position detected in AR you need to return the object identifier.
 * @return NSString The Identifier of the object that will be attached to the plane detected.
 */
- (NSString*)T3DARKitDidDetectPlane;
/*!
 * @brief  Method that will be called when an image plane is detected, you are responsable to add a T3DGeometry object or any other to the scene.
 * @discussion If you want to attach an object to this anchor just set its identifier the same as the anchor.
 * @param imageAnchor The anchor with all the information about the image (size, position, etc).
 */
- (void)T3DARKitDidDetectImagePlane:(T3DAnchor*)imageAnchor;
/*!
 * @brief  Method that will be called when a face is detected, you are responsable to add a T3DGeometry object or any other to the scene.
 * @discussion If you want to attach an object to this anchor just set its identifier the same as the anchor.
 * @param faceAnchor The anchor with all the information about the image (size, position, etc).
 */
- (void)T3DARKitDidDetectFace:(T3DAnchor*)faceAnchor;
/*!
 * @brief  Method that will be called when an object is detected, you are responsable to add a T3DGeometry object or any other to the scene.
 * @discussion If you want to attach an object to this anchor just set its identifier the same as the anchor.
 * @param objectRefAnchor The anchor with all the information about the image (size, position, etc).
 */
- (void)T3DARKitDidDetectObjectReference:(T3DAnchor*)objectRefAnchor;
/*!
 * @brief  Method that will be called when a plane is deleted, you are responsable to remove the object attached to this plane (if any).
 * @discussion ARKit delete planes when they are merged or updated.
 * @param identifier The identifier for the deleted plane.
 */
- (void)T3DARKitDidDeletePlaneForModelIdentifier:(NSString*)identifier;
/*!
 * @brief  Method that will be called when a hit test result is succesful.
 * @discussion ARKit delete planes when they are merged or updated.
 * @param hitPoint The hitpoint coordinates in 3D space.
 * @param objectIdentifier The identifier for the object that was hit.
 */
- (void)T3DARKitHitTestPoint:(GLKVector3)hitPoint withObject:(NSString*)objectIdentifier;
//ARKit app was sent to background, so ARKit needs to reset the session
/*!
 * @brief  Method that will be called when ARKit reset the actual session.
 * @discussion This most likely will happen when the app was sent to background.
 */
- (void)T3DARKitDidResetSession;
@end

/*!
 @class T3DRenderController
 
 @brief Main Class for the Emcore3D Framework.
 
 @discussion This class manage all the states and logic for the framework, it should be retained and created only once per session.
 
 @superclass UIViewController
 */
@interface T3DRenderController : UIViewController

/*!
 * @brief  Property for the T3DControlDelegate.
 */
@property (nonatomic, weak) id <T3DControlDelegate> controlDelegate;
/*!
 * @brief  Property for the T3DRenderControllerARDelegate.
 */
@property (nonatomic, weak) id <T3DRenderControllerARDelegate> arDelegate;
/*!
 * @brief  Property for the T3DRenderControllerDelegate.
 */
@property (nonatomic, weak) id <T3DRenderControllerDelegate> renderControllerDelegate;

/*!
 * @brief  Property to set the interpupillary distance (IPD) for VR.
 * @param vrIPD Although varying from person-to-person, human eye pupils are approximately 65 mm apart, so by default is 0.32.
 */
@property (nonatomic, assign) float vrIPD;

/*!
 * @brief  Method to init a new Instance of T3DRenderController.
 * @param sessionName String with the session name to be loaded, if there is no previous session then the current one will have this name, if one is found then it will be loaded, if it is set to nil it will never save the session and a new one will be created.
 * @returns self.
 */
- (instancetype)initWithSessionName:(NSString*)sessionName withGraphicsAPIType:(T3DGraphicsAPIType)graphicsAPIType andLicenseKey:(NSString*)licenseKey;

/*!
 * @brief  Method to get the time since last render.
 * @returns float.
 */
- (float)getDeltaTime;

/*!
 * @brief  Method to clean memory when removing the T3DRenderController, should be called before dismissing the parent VC.
 */
- (void)cleanUpOnRemove;

/*!
 * @brief  Method to restore the defaul values of the camera, doesn't work in AR.
 */
- (void)resetCameraTransformationValues;

/*!
 * @brief  Method to restore all object to their default values after loading.
 */
- (void)resetAllObjectsTransformationValues;

/*!
 * @brief  Method to get the current render type (Normal, VR).
 * @returns T3DRenderType.
 */
- (T3DRenderType)getRenderType;

/*!
 * @brief  Method to change the current render type (Normal, VR).
 */
- (void)changeRenderType:(T3DRenderType)type;

#warning check if this is necessary
- (void)setT3DObjectForDinamicThrow:(T3DObject*)throwObject;

//T3DObject Methods

/*!
 * @brief  Method to hide (not render) all models, it will still be updated.
 */
- (void)hideModels:(BOOL)hide;

/*!
 * @brief  Method to add a new instance of a T3DObject.
 */
- (void)addT3DObject:(T3DObject*)object;

/*!
 * @brief  Method to add a surface detector for AR with a pulsing effect when searching and a shutter effect when detected.
 * @param searching The image to display while searching.
 * @param detected The image to display when a surface has been detected.
 */
- (void)addARSurfaceDetectorWithSearchingImage:(UIImage*)searching andDetectedImage:(UIImage*)detected;

/*!
 * @brief  Method to remove the AR surface detector.
 */
- (void)removeARSurfaceDetector;

/*!
 * @brief  Method to get the current surface status, YES it a surface has been found, NO if still searching for one.
 * @returns BOOL.
 */
- (BOOL)checkSurfaceDetectorStatus;

/*!
 * @brief  Method to get the current object selected in which most operations will be applied, (Touch controls, camera focal point, etc).
 * @returns T3DObject.
 */
- (T3DObject*)getCurrentObjectSelected;

/*!
 * @brief  Method to get the current object selected in which most operations will be applied, (Touch controls, camera focal point, etc).
 * @param identifier String with the name of the object to return.
 * @returns T3DObject.
 */
- (T3DObject*)getObjectWithIdentifier:(NSString*)identifier;

/*!
 * @brief  Method to select the object in which most operations will be applied, (Touch controls, camera focal point, etc).
 * @param identifier String with the name of the object to select.
 */
- (void)selectObjectWithIdentifier:(NSString*)identifier;

/*!
 * @brief  Method to remove from the scene the object with the specified identifier.
 * @param identifier String with the name of the object to return.
 */
- (void)removeT3DObjectWithIdentifier:(NSString*)identifier;

/*!
 * @brief  Method to select the next object in the scene.
 */
- (void)selectNextObject;

/*!
 * @brief  Method to select the first object that was added to the scene.
 */
- (void)selectFirsObject;

/*!
 * @brief  Method to get the number of object currently in the scene.
 */
- (int)numberOfObjects;

//Object Control Methods

/*!
 * @brief  Property to set/get the control type (Touch, gyro, etc.).
 * @param controlType T3DControlType enumeration.
 */
@property (nonatomic, assign) T3DControlType controlType;

/*!
* @brief  Property to set/get the current object type (Model, Camera, Light, etc) in which the control type (Touch, gyro, etc.) will work.
* @param objectModifiedByControl T3DSceneObjectType enumeration.
*/
@property (nonatomic, assign) T3DSceneObjectType objectModifiedByControl;

/*!
 * @brief  Property to set/get the rotation axis (X,Y,Z) when interacting with the UI controls.
 * @param objectRotationAxis T3DObjectRotationAxis enumeration.
 */
@property (nonatomic, assign) T3DObjectRotationAxis objectRotationAxis;

//T3DRenderManager handle methods

/*!
 * @brief  Method to enable/disable if the shadow will be shown if the camera is bellow the object lowest top position.
 * @param ignore YES to ignore, No to enable (default enabled).
 */
- (void)ignoreShadowZLimit:(BOOL)ignore;

/*!
 * @brief  Method to change the world Up coordinate system.
 * @param upCoord T3DWorldUpCoord enumeration.
 */
- (void)changeWorldUpCoord:(T3DWorldUpCoord)upCoord;

/*!
 * @brief  Property to display useful information about the scene (world grid, light position, bounding box, etc).
 * @param display3DWorld Boolean value to enable/disable it, (default set to no).
 */
@property (nonatomic, assign) BOOL display3DWorld;

/*!
 * @brief  Property to enable/disable light transformations to the scene.
 * @param lightActive Boolean value to enable/disable it, (default set to YES).
 */
@property (nonatomic, assign) BOOL lightActive;

/*!
 * @brief  Property to enable/disable shadow to currently object selected.
 * @param shadowActiveInCurrentObjectSelected Boolean value to enable/disable it.
 */
@property (nonatomic, assign) BOOL shadowActiveInCurrentObjectSelected;

/*!
 * @brief  Property to show an alert when there is a warning logged by the Framework.
 * @discussion By default is set to NO
 * @param displayWarnings Boolean value to enable/disable it.
 */
@property (nonatomic, assign) BOOL displayWarnings;

/*!
 * @brief  Property to show an alert when there is an error logged by the Framework.
 * @discussion By default is set to YES
 * @param displayWarnings Boolean value to enable/disable it.
 */
@property (nonatomic, assign) BOOL displayErrors;

/*!
 * @brief  Method to enable/disable shadows in all models.
 * @param active Boolean value to enable/disable it.
 */
- (void)setShadowActiveOnAllModels:(BOOL)active;

/*!
 * @brief  Method to set the identifier for the object in which the shadow will be attached.
 * @param arAnchorIdentifier String.
 */
- (void)identifierForShadowARAnchor:(NSString*)arAnchorIdentifier;

/*!
 * @brief  Property to change the shader type (blinn phong, toon, etc).
 * @param shaderType T3DShaderType enumeration.
 */
@property (nonatomic, assign) T3DShaderType shaderType;

/*!
 * @brief  Method to get the camera position.
 * @param offset The distance to project the camera position in meters (1.0 = 1mt).
 */
- (GLKVector3)getCameraPositionWithForwardOffset:(CGFloat)offset;

//T3DLight Methods

/*!
 * @brief  Property to get/set the current light in which the UI controls will be applied.
 * @param currentLightSelected T3DLight object.
 */
@property (nonatomic, weak) T3DLight* currentLightSelected;

/*!
 * @brief  Method to get the Array of T3DLights currently applied to the scene (Max number of lights is 3).
 * @returns NSArray.
 */
- (NSArray*)getAllLigthsData;

/*!
 * @brief  Method to select the light based on its light index.
 * @param lightNumber The integer for the index of the light.
 */
- (void)selectLight:(int)lightNumber;

/*!
 * @brief  Method to get the T3DLight based on the index given.
 * @param lightIndex The integer for the index of the light.
 * @returns T3DLight.
 */
- (T3DLight*)getLightAtIndex:(int)lightIndex;

/*!
 * @brief  Method to add a T3DLight and chose to select it.
 * @param light T3DLight object.
 * @param selected Boolean value to select it or not.
 * @returns T3DLight.
 */
- (BOOL)addLight:(T3DLight*)light andSelectIt:(BOOL)selected;

/*!
 * @brief  Method to remove a T3DLight at a given index.
 * @param index The integer for the index of the light.
 * @returns BOOL.
 */
- (BOOL)removeLigthAtIndex:(int)index;

/*!
 * @brief  Method to get a T3DLight based on their identifier.
 * @param identifier String.
 * @returns T3DLight.
 */
- (T3DLight*)getLightWithIdentifier:(NSString*)identifier;

//Session Methods

/*!
 * @brief  Method to get the name of the current session (could be nil).
 * @returns NSString.
 */
- (NSString*)getSessionName;

/*!
 * @brief  Method to know if this is a new session, useful if session names has been automated.
 * @returns BOOL.
 */
- (BOOL)isNewSession;

/*!
 * @brief  Method to delete the current session (this will also release resources).
 */
- (void)deleteSession;

//Camera Input Methods

/*!
 * @brief  Property to change the camera filter.
 * @param cameraFilter T3DShaderType enumeration.
 */
@property (nonatomic, assign) T3DShaderType cameraFilter;

/*!
 * @brief  Method to get a image from the current rendered frame.
 * @returns UIImage.
 */
- (UIImage*)captureFrame;

/*!
 * @brief  Recording methods not available in the current version.
 */
- (void)startRecording;
- (BOOL)isRecording;
- (void)finishRecording;

/*!
 * @brief  Property to show/hide camera input in the background of the rendered frame.
 * @param showCameraBackground Boolean value to show/hide it.
 */
@property (nonatomic, assign) BOOL showCameraBackground;

/*!
 * @brief  Property to set/get the camera input source type (only available when not in AR).
 * @param cameraSourceType T3DCameraSource enumeration (default to T3DCameraSourceBack).
 */
@property (nonatomic, assign) T3DCameraSource cameraSourceType;

/*!
 * @brief  Method to start the camera input in the background of the rendered frame (When no in AR).
 */
- (void)startCameraBackground;

//ARKit Methods

/*!
 * @brief  Method to know if ARKit is currently running.
 * @returns BOOL.
 */
- (BOOL)isARKitEnabled;

/*!
 * @brief  Method to know if ARKit is supported in this device.
 * @returns BOOL.
 */
+ (BOOL)isARKitSupported;

/*!
 * @brief  Method to start an ARKit Session.
 * @param arConfiguration T3DARConfiguration enumeration with the type of configuration to run in the ARKit session.
 * @param completionBlock The completion block used when ARKit has finished initialization.
 * @returns T3DARKitAvailability Enumeration to know the current device ARKit capabilities.
 */
- (T3DARKitAvailability)startARKitWithConfiguration:(T3DARConfiguration)arConfiguration withCompletion:(void(^)(void))completionBlock;

/*!
 * @brief  Method to add an Image Market to the current ARKit Session.
 * @param image The image to be recognized.
 * @param width The physical width in cm for the image.
 * @param identifier The string for the image that will be returned when it is recognized.
 */
- (void)addARImageReferenceWithImage:(UIImage*)image andPhysicalWidth:(float)width imageIdentifier:(NSString*)identifier;

/*!
 * @brief  Method to add a 3D Object reference to be detected by ARKit.
 * @param arobjectPath the path to the .arobject file.
 */
- (void)addARObjectReferenceAtPath:(NSString*)arobjectPath;

/*!
 * @brief  Method to stop the current ARKit session.
 */
- (void)stopARKit;

/*!
 * @brief  Method to enable plane detection in the current ARKit session.
 * @param enable BOOL.
 */
- (void)enablePlaneDetection:(BOOL)enable;

/*!
 * @brief  Method to change the blending function default(T3DBlendFunctionSRC_ALPHA, T3DBlendFunctionONE_MINUS_SRC_ALPHA, T3DBlendFunctionONE, T3DBlendFunctionONE_MINUS_SRC_ALPHA).
 * @param blendFunct T3DBlendFunction enumeration.
 * @param option int (max 4).
 */
- (void)changeBlendingFunc:(T3DBlendFunction)blendFunct forOption:(int)option;

/*!
 * @brief  Method to get the blending function for the specified index in a string format.
 * @param opt The index for the blending function (max 4).
 * @returns NSString.
 */
- (NSString*)getStringFromBlendingOption:(int)opt;

//Image recognition Methods

/*!
 * @brief  Method to load an image machine learning model (can be used when camera input is enabled (ARKit or Not)).
 * @param path The string path to the file.
 */
- (void)startImageRecognitionForMLModelInPath:(NSString*)path;

/*!
 * @brief  Method to stop an image machine learning model.
 */
- (void)stopImageRecognition;

//Post Rendering Effects

/*!
 * @brief  Method to perform a new render effect in the whole scene.
 * @param postRenderEffect T3DPostRenderingEffectType enumeration for the effect to be rendered.
 * @param loops The number of times to be repeated (if applicable).
 */
- (void)performPostRenderEffect:(T3DPostRenderingEffectType)postRenderEffect numberOfLoops:(int)loops;

/*!
 * @brief  Method to get all the warnings currently logged by the framework as an array of NSString.
 * @return NSArray.
 */
- (NSArray*)getAllWarnings;

/*!
 * @brief  Method to get all the errors currently logged by the framework as an array of NSString.
 * @return NSArray.
 */
- (NSArray*)getAllErrors;

/*!
 * @brief  Method to display an alert message with all the errors and warning currently logged by the framework.
 * @discussion After the alert is called the errors and warnings will be cleared.
 */
- (void)displayAlertWithErrorsAndWarnings;

@end
