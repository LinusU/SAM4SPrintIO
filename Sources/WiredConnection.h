//
//  WiredConnection.h
//  SHCLibrary
//
//  Created by Ambiga on 13/05/15.
//  Copyright (c) 2015 SHCLibrary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PrinterConnection.h"
#import "Global.h"


@interface WiredConnection : PrinterConnection< NSStreamDelegate >
{
    NSMutableData *dataToSend, *dataFetched;
    
    NSInputStream * inputStream;
    NSOutputStream * outputStream;
    
    NSOperationQueue *writeOpsQueue;
    
    BOOL iSDataAvailableToReadFromPrinter;
    
}

@property (readonly) BOOL dataAvailable;

/*!
 * @discussion Initialize the connection with the Wifi instance.
 * @param ipAddress is a String.
 * @return Returns an instance of the Ethernet connection (WiredConnection) or Wireless Connection
 */
- (instancetype) initConnectionWithPrinter:(NSString *)ipAddress;

@end
