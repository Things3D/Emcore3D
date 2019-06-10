//
//  BaseVC.h
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 5/16/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Manager.h"
#import "OptionsView.h"

@interface BaseVC : UIViewController

@property (strong, nonatomic) T3DRenderController *renderController;
@property (strong, nonatomic) NSMutableArray *theOptions;

- (void)displayMessage:(NSString*)message withTitle:(NSString*)title inVC:(UIViewController*)vc;

@end
