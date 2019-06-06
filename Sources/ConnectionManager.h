//
//  ConnectionManager.h
//  SHCLibrary
//
//  Created by Ambiga on 13/05/15.
//  Copyright (c) 2015 SHCLibrary. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Printer;
/*!
 @brief
 The ConnectionManagerDelegate protocol defines some callback messages
 that will be sent whenever certain events related to the printer's connectivity occur:
 printer is connected, printer is disconnected, attempt to connect to a printer fails.
 */
@protocol ConnectionManagerDelegate <NSObject>

@optional
/*!
 @brief
 This method is called when the device connection fails.
 */
-(void) didDeviceNetworkDisconnected:(NSString*)string;

-(void) didPrinterConnected:(Printer*)printer;

-(void) didPrinterDisconnected:(Printer*)printer;

-(void) didPrinterReceivesError:(NSString*)error;


@end

/*!
 @typedef
 enum definition for connection types. Only bluetooth is supported in the current SDK version.
 */
typedef enum
{
    ConnectionTypeBlueTooth,
    ConnectionTypeWiFi
    
} ConnectionType;

/*!
 @brief
 ConnectionManager is an abstract definition of a connection manager.
 In the current SDK version, there is only one concrete implementation which is the BTConnectionManager.
 */
@interface ConnectionManager : NSObject

@property (nonatomic, assign) BOOL isNetworkAvailable;
@property (nonatomic, assign) BOOL isPrinterConnected;

@property (nonatomic) id<ConnectionManagerDelegate> delegate;

/*!
 @brief
 Use this factory method to get an instance of the connection manager for various types of connectivity.
 In the current SDK, only bluetooth connectivity is supported.
 
 @param type
 Specifies the connection type: bluetooth, wifi, etc.
 
 @Returns
 Returns the instance of the ConnectionManager of the specified type.
 */
+(id) sharedConnectionWithType:(ConnectionType)type delegate:(id)sender;


/*!
 @brief
 To get WiFi connection manager (equivalent to sending the message "connectionManagerOfType: wifi")
 
 @Returns
 Returns the singleton instance of wifiConnectionManager
 */
+(id) sharedWiredConnectionManager;

/*!
 @brief
 To get Bluetooth connection manager (equivalent to sending the message "connectionManagerOfType: Bluetooth")

@Returns
Returns the singleton instance of bletoothConnectionManager
*/
+(id) sharedBluetooothConnectionManager;

/*!
 @brief
 Returns the list of connected printers.
 For bluetooth connection, this array contains the list of EAAccessory instances.
 
 @param type
 Specifies the printer type
 */
-(NSArray*) connectedPrintersIPAddress;

/*!
 @brief
 Returns the list of connected printers.
 For bluetooth connection, this array contains the list of EAAccessory instances.
 
 @param type
 Specifies the printer type: PoS or Label
 */
-(NSArray*) connectedPrintersNameForBluetooth;
/*!
 @brief
 Connect to a printer specified by the printerInfo instance.
 For Bluetooth conenction, this will create a EASession with the printer and return an instance of the printer.
 
 @param printerInfo
 When connecting to a printer via Bluetooth, the printer info must be an EAAccessory object.
 For WiFi connection, the printerInfo is not yet defined in current SDK; could be a MAC address or an IP address.
 
 @Returns
 Returns an instance of Printer
 */
-(Printer*) makeConnectWithSelectedPrinter:(id)printerAddress;

/*!
 @brief
 Disconnect from the printer. This will close the connection with the printer.
 */
-(void) disconnectPrinter:(Printer*)printer;

@end
