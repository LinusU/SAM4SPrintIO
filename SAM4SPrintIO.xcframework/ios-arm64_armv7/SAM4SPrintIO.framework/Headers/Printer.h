//
//  Printer.h
//  SHCLibrary
//
//  Created by Ambiga on 13/05/15.
//  Copyright (c) 2015 SHCLibrary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PrinterConnection.h"
#import "Global.h"

@class PrinterConnection, EAAccessory, PrintIOStream;

/*! @discussion
 The Printer instance provides two ways to communicate with the printer:
 Raw IO: Using the connection instance, raw data canbe sent to the printer.
 Using the PrintIOStream instance, which defines wrapper methods for several commands,
 various priting operations can be performed.
 */

@interface Printer : NSObject <ConnectionPrinterDelegate>
{
    PrinterConnection *connection;
    PrintIOStream *printIO;
}

@property (readonly) PrintIOStream *printIO;
@property (readonly) NSString *iPAddress;
@property (readonly) EAAccessory *bluetoothAccessory;

@end
