//
//  SimplePingHelper.h
//  PingTester
//
//  Created by Ambiga on
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SimplePing.h"

@interface SimplePingHelper : NSObject <SimplePingDelegate>

+ (void)ping:(NSString*)address target:(id)target sel:(SEL)sel;

@end
