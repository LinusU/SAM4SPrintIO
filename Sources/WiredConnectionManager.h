//
//  WiredConnectionManager.h
//  SHCLibrary
//
//  Created by Ambiga on 13/05/15.
//  Copyright (c) 2015 SHCLibrary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ConnectionManager.h"
#import "GCDAsyncUdpSocket.h"
/*! WiredConnectionManager inherits from ConnectionManager and
 implements the methods of ConnectionManager using Wired Ehernet connectivity.
 */
@protocol WiredConnectionUDPDelegate
/*! This method is used to get the IP address from the UDP packet.
 */
- (void)didReceiveIPAddress : (NSArray *)discoveredIP;

@end
@interface WiredConnectionManager : ConnectionManager<GCDAsyncUdpSocketDelegate>
{
    Printer *connectedPrinter;
    NSString *selectedIPAddress;

    GCDAsyncUdpSocket *udpSocket;
    
    long tag;

}
@property NSString * RouterIP;
@property NSMutableArray * ip;
@property NSMutableArray * mac;
@property NSMutableArray * discoveredIPAddress;
@property id <WiredConnectionUDPDelegate> wireddelegate;

- (BOOL) isValidIpAddress:(NSString *)ipAddress;
- (NSString*) getDefaultGatewayIp;
@end
