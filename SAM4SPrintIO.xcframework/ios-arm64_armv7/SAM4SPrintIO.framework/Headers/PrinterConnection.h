//
//  PrinterConnection.h
//  SHCLibrary
//
//  Created by Ambiga on 13/05/15.
//  Copyright (c) 2015 SHCLibrary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>


/*! @discussion
 ConnectionPrinterDelegate defines callback messages that will be sent when
 events related to the data transfer between the iOS device and the printer occurs.
 */
@protocol ConnectionPrinterDelegate <NSObject>

@optional
/*!
 * @discussion The message didReceivedDataFromPrinter is sent whenever some data is received form the printer.
 * @param data The NSData instance that encapsulates the data received from the printer.
 */
- (void) didReceivedDataFromPrinter:(NSData*)data;

@end

/*! @discussion PrinterConnection is an abstract definition of the connection between the printer and the iOS device.
 It defines the methods to open conenction, close connection, send data to the printer and a delegate to receive data
 sent from the printer.
 */

extern NSString *const SAM4SPrinterConnectionLostNotification;

@interface PrinterConnection : NSObject

@property (nonatomic) id<ConnectionPrinterDelegate> delegate;

//Connection Open/Close
- (void) openConnection;
- (void) closeConnection;

//Printer IO methods
- (void) sendDataToPrinter: (NSData*)data;


@end
