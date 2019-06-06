//
//  BTConnection.h
//  SDK Sample
//
//  Created by Ambiga on 21/07/15.
//  Copyright (c) 2015 SHCLibrary. All rights reserved.
//

#import "PrinterConnection.h"
#import <ExternalAccessory/ExternalAccessory.h>

/*! @discussion 
 BTConnection ingerits PrinterConnection and defines the methods for bluetooth connectivity.
 */
@interface BTConnection : PrinterConnection <NSStreamDelegate, EAAccessoryDelegate>
{
	EASession *ea_session;
	NSMutableData *dataToSend, *dataFetched;

	NSOperationQueue *writeOpsQueue;

	BOOL isDataAvailable;
}

@property (readonly) BOOL dataAvailable;

/*!
 * @discussion Initialize the connection with the EAAccessory instance.
 * @param The EAAccessory instance.
 * @return Returns an instance of the bluetooth connection (BTConnection)
 */
- (instancetype) initWithExternalAccessory: (EAAccessory*)accessory;

@end
