# Emcore3D
The Emcore3D Framework is designed to be a fast, lightweight, optimized engine to render 3D objects, with augmented reality as one of its core components. It also extends to virtual reality, machine learning and multimedia playback. This makes the experience to develop this kind of content really accessible thanks to its easy to use controls and interaction capabilities. 

In order to use the framework in your own app you need to get a free development key here [www.emcore3d.com](https://www.emcore3d.com/index.php?page=licenseoptions#licenseoptions), and when you're ready to deploy commercially, choose between an app or company wide license to launch with.
Also you can check the [documentation](https://www.emcore3d.com/index.php?page=docs) and the [terms of service](https://www.emcore3d.com/index.php?page=terms#terms).

#Quick Start Guide

The first step is to create an instance of T3DRencerController which is the main class of the Framework and then add it to your view.

```objc
//1
T3DRenderController *renderVC = [[T3DRenderController alloc] initWithSessionName:@"Session Name" withGraphicsAPIType:T3DGraphicsAPITypeOpenGL andLicenseKey:@"License Key"];
//2
[self.view addSubview:renderVC.view];
```

Then to load a model you need to create a T3DModelPathInfo instance, specifying the name of the model with the extension, the path to the material file (if needed) and the relative path in your project, by default this class will look for the files in your main bundle, but you can change that with the property modelPathType and set it to the documents or temporary directories.

```objc
//3
T3DModelPathInfo *newModelPath = [T3DModelPathInfo createModelPathInfoWithModelName:@"model.obj" material:@"model.mtl" path:@"/3DModels/"];
```

After that you create a T3DObject with the T3DModelPathInfo and add it to the T3DRenderController.

```objc
//4
T3DObject *newObject = [T3DObject initWithModelPathObject:newModelPath];
[renderVC addT3DObject:newObject];
```

And that's all, this will display the model in normal mode, if you want to see it in AR you only need to call the next method and add the object to the T3DRenderController inside the completion block.

```objc
[renderVC startARKitWithConfiguration:T3DARConfigurationWorldTracking withCompletion:^{
   [renderVC addT3DObject:newObject];
}];
```

