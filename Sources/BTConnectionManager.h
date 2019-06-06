//
//  BTConnection.h
//  SDK Sample
//
//  Created by Ambiga on 21/07/15.
//  Copyright (c) 2015 SHCLibrary All rights reserved.

//

#import "ConnectionManager.h"

/*! BTConnectionManager inherits from ConnectionManager and 
 implements the methods of ConnectionManager using bluetooth connectivity.
 */

@interface BTConnectionManager : ConnectionManager
{
	Printer *connectedPrinter;
}

@end
