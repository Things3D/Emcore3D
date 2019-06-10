# Emcore3D
The Emcore3D Framework is designed to be a fast, lightweight, optimized engine to render 3D objects, with augmented reality as one of its core components. It also extends to virtual reality, machine learning and multimedia playback. This makes the experience to develop this kind of content really accessible thanks to its easy to use controls and interaction capabilities. 

In order to use the framework in your own app you need to get a free development key here [www.emcore3d.com](https://www.emcore3d.com/index.php?page=licenseoptions#licenseoptions), and when you're ready to deploy commercially, choose between an app or company wide license to launch with.
Also you can check the [documentation](https://www.emcore3d.com/index.php?page=docs) and the [terms of service](https://www.emcore3d.com/index.php?page=terms#terms).


# Quick Start Guide

The first step is to create an instance of T3DRenderController which is the main class of the Framework and then add its view to your own.

```objc
//1
T3DRenderController *renderVC = [[T3DRenderController alloc] initWithSessionName:@"Session Name" withGraphicsAPIType:T3DGraphicsAPITypeOpenGL andLicenseKey:@"License Key"];
//2
[self.view addSubview:renderVC.view];
```

Then to load a model you need to create a T3DObject instance with a class method that requires a relative path to the folder in which the model assets are (Emcore3D will search for compatible files and load them accordingly) and specify the source where the model is (it can be main bundle, temporary folder and documents folder).

```objc
//3
T3DObject *newObject = [T3DObject initWithModelRelativePath:@"Relative Path" andLoadFromSource:T3DResourcePathMainBundle];
```

After that you just have to add it to the T3DRenderController.

```objc
//4
[renderVC addT3DObject:newObject];
```

And that's all, this will display the model in normal mode, if you want to see it in AR you only need to call the next method and add the object to the T3DRenderController inside the completion block.

```objc
//5
[renderVC startARKitWithConfiguration:T3DARConfigurationWorldTracking withCompletion:^{
   [renderVC addT3DObject:newObject];
}];
```
