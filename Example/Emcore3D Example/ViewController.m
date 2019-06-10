//
//  ViewController.m
//  Emcore3D Example
//
//  Created by Rodrigo Galvez on 5/16/19.
//  Copyright © 2019 Rodrigo Galvez. All rights reserved.
//

#import "ViewController.h"
#import "Manager.h"

@interface ViewController () <UITableViewDelegate, UITableViewDataSource>

@property (weak, nonatomic) IBOutlet UITableView *tableView;

@property (strong, nonatomic) NSDictionary *dataSource;

@property (weak, nonatomic) IBOutlet UISegmentedControl *segmentedControl;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    // Do any additional setup after loading the view.
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self setDataSource];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)setDataSource{
    NSArray *vrDataSource = @[@"Haunted_House_VR"];
    NSArray *fbxDataSource = @[@"Humanoid_Model"];
    NSArray *objDataSource = @[@"Joker_In_AR"];
    NSArray *mediaDataSource = @[@"TV_Sky_Video_In_AR"];
    NSArray *customDataSource = @[@"AR_Face_Mask", @"Object_Shaders_And_Camera_Filter"];
    self.dataSource = @{@"Obj Examples":objDataSource,@"Fbx Examples":fbxDataSource,@"VR Examples":vrDataSource,@"Media Examples":mediaDataSource,@"Custom Examples":customDataSource};
    [self.tableView reloadData];
}

-(BOOL)prefersStatusBarHidden{
    return YES;
}

#pragma mark - Table view data source

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section{
    return self.dataSource.allKeys[section];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return self.dataSource.allKeys.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    NSArray *data = self.dataSource[self.dataSource.allKeys[section]];
    return data.count;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = (UITableViewCell*)[tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    
    // Configure the cell...
    NSArray *data = self.dataSource[self.dataSource.allKeys[indexPath.section]];
    NSString *name = data[indexPath.row];
    
    cell.textLabel.text = name;
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 40.0f;
}


#pragma mark - Table view delegate

// In a xib-based application, navigation from a table can be handled in -tableView:didSelectRowAtIndexPath:
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    [Manager preferences].graphicsAPI = self.segmentedControl.selectedSegmentIndex != 0 ? T3DGraphicsAPITypeMetal : T3DGraphicsAPITypeOpenGL;
    NSArray *data = self.dataSource[self.dataSource.allKeys[indexPath.section]];
    NSString *name = data[indexPath.row];
    ViewController *newVC = [[NSClassFromString(name) alloc] init];
    newVC.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
    [self presentViewController:newVC animated:YES completion:nil];
    
}


@end
