//
//  BaseVC.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 5/16/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "BaseVC.h"

@interface BaseVC ()

@property (strong, nonatomic) OptionsView *options;

@end

@implementation BaseVC

- (void)viewDidLoad {
    [super viewDidLoad];
    _theOptions = [[NSMutableArray alloc] init];
    // Do any additional setup after loading the view.
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self startEmcore3d];
    [self addBackButton];
}

- (void)startEmcore3d{
    _renderController = [[T3DRenderController alloc] initWithSessionName:nil withGraphicsAPIType:[Manager preferences].graphicsAPI andLicenseKey:[Manager preferences].licenseKey];
    [self.view addSubview:_renderController.view];
}

- (void)addBackButton{
    //CGRect topFrame = CGRectMake(0, [UIApplication sharedApplication].statusBarFrame.size.height, self.view.frame.size.width, 50 + [UIApplication sharedApplication].statusBarFrame.size.height);
    CGFloat statusBarH = [UIApplication sharedApplication].statusBarFrame.size.height;
    CGFloat narBarH = 50.0;
    CGRect bottomFrame =  CGRectMake(0, self.view.frame.size.height - narBarH, self.view.frame.size.width, statusBarH + narBarH);
    UINavigationBar *navbar = [[UINavigationBar alloc] initWithFrame:bottomFrame];
    //do something like background color, title, etc you self
    [self.view addSubview:navbar];
    
    UINavigationItem *item = [[UINavigationItem alloc]
                              init];
    navbar.items= @[item];
    UIBarButtonItem *backButton = [[UIBarButtonItem alloc]
                                   initWithTitle:@"Back"
                                   style:UIBarButtonItemStylePlain
                                   target:self
                                   action:@selector(backBtnClicked:)];
    item.leftBarButtonItem = backButton;
    
    UIBarButtonItem *actionButton = [[UIBarButtonItem alloc]
                                     initWithTitle:@"Options"
                                     style:UIBarButtonItemStylePlain
                                     target:self
                                     action:@selector(actionBtnClicked:)];
    item.rightBarButtonItem = actionButton;
}

- (void)backBtnClicked:(id)sender{
    [_renderController cleanUpOnRemove];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)actionBtnClicked:(id)sender{
    if (self.options == nil){
        self .options = [OptionsView addToView:self.view atPlace:RTOptionsViewPlaceRight];
    }
    if (self.options.visible){
        [self.options hide];
    }else{
        [self.options showWithOptions:_theOptions];
    }
}

- (void)displayMessage:(NSString*)message withTitle:(NSString*)title inVC:(UIViewController*)vc{
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"Got it!" style:UIAlertActionStyleDefault handler:nil]];
    [vc presentViewController:alert animated:YES completion:nil];
}

@end
