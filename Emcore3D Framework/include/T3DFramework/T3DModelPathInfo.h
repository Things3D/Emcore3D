//
//  T3DModelPathInfo.h
//
//  Created by Rodrigo Galvez on 12/6/15.
//  Copyright © 2015 Things3D. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * @brief Definition of the enumeration to specify the resource path type.
 */
typedef NS_ENUM(NSInteger, T3DResourcePath){
    T3DResourcePathMainBundle,
    T3DResourcePathDocumentsDirectory,
    T3DResourcePathTempDirectory
};

/*!
 * @brief Definition of the enumeration to specify the kind of resource.
 */
typedef NS_ENUM(NSInteger, T3DModelFileType){
    T3DModelFileTypeObject,
    T3DModelFileTypeTexture,
    T3DModelFileTypeNormalMap,
    T3DModelFileTypeMaterial
};

/*!
 @class T3DModelPathInfo
 
 @brief Class to hold all the information needed not load a 3d model.
 
 @superclass NSObject
 */
@interface T3DModelPathInfo : NSObject

/*!
 * @brief Property that hold the name of the model.
 * @param modelName
 */
@property (nonatomic, strong) NSString *modelName;
/*!
 * @brief Property that hold the texture name of the model.
 * @param modelTextureName
 */
@property (nonatomic, strong) NSString *modelTextureName;
/*!
 * @brief Property that hold the normal map texture name of the model.
 * @param modelNormalMapName
 */
@property (nonatomic, strong) NSString *modelNormalMapName;
/*!
 * @brief Property that hold the material name of the model.
 * @param modelMaterialName
 */
@property (nonatomic, strong) NSString *modelMaterialName;

/*!
 * @brief Property that hold the type of path of where the resource will be loaded.
 * @param modelPathType T3DResourcePath enumeration to specify the path (default is T3DResourcePathMainBundle)
 */
@property (nonatomic, assign) T3DResourcePath modelPathType;

/*!
 * @brief Property that hold the relative path to the model.
 * @param modelPath
 */
@property (nonatomic, strong) NSString *modelPath;
/*!
 * @brief Property that hold the decrypted information of a model.
 * @brief If your model was previously encrypted and you just decryted it, you can just pass it in this property so you dont need to save the file to disk.
 * @param decryptedModel
 */
@property (nonatomic, strong) NSString *decryptedModel;

/*!
 * @brief Method to get the full path for a given resource.
 * @param modelFileType T3DModelFileType enumeration to specify the resource type to get
 * @return NSString
 */
- (NSString*)getModelPathFor:(T3DModelFileType)modelFileType;

/*!
 * @brief Method to create a new instance with the required information.
 * @param name String to specify the name of the model (include the type i.e .obj, .fbx)
 * @param name String to specify the material of the model (include the type i.e .mtl)
 * @param name String to specify the path of the model
 * @return T3DModelPathInfo
 */
+ (T3DModelPathInfo*)createModelPathInfoWithModelName:(NSString*)name material:(NSString*)material path:(NSString*)path;

@end
