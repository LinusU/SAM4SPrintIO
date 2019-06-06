//
//  PrintIOStream.h
//  SHCLibrary
//
//  Created by Ambiga on 13/05/15.
//  Copyright (c) 2015 SHCLibrary. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PrinterConnection;

@interface PrintIOStream : NSObject
{
    PrinterConnection *connection;
}

@property (readonly) PrinterConnection *connection;

- (instancetype) initConnectionWithSAM4S: (PrinterConnection*)printerConnection;
@end
