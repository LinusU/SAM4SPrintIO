//
//  Printer+Private.h
//  SHCLibrary
//
//  Created by Ambiga on 13/05/15.
//  Copyright (c) 2015 SHCLibrary. All rights reserved.
//

#import "Printer.h"

@interface Printer (Private)

/*
 The SDK will determine the printer based on the IP Address.
 The printers are expected that have been connected in wifi Network for PoS .
 */
- (instancetype) initWithIPAddress: (NSString *)ipAddress;
/*
 The SDK will determine the printer type based on the model name of the accessory.
 The printers are expected to have the naming format "Cognitive-PoS-xxxx" and "Cognitive-Label-xxxx"
 for PoS and label printers respectively.
 */
- (instancetype) initWithExternalAccessory: (EAAccessory*)accessory;


//Returns YES/NO based on whether or not the conenction is successfully established
- (BOOL) openConnection;

- (void) closeConnection;

@end
