//
//  Global.h
//  SHCLibrary
//
//  Created by Ambiga on 13/05/15.
//  Copyright (c) 2015 SHCLibrary. All rights reserved.
//


#ifndef SHCPrinterSDK_Global_h
#define SHCPrinterSDK_Global_h

#ifdef DEBUG
#define debugLog(format, ...) NSLog(format, ##__VA_ARGS__)
#else
#define debugLog(format, ...)
#endif
#define sdkLog(format, ...) NSLog(format, ##__VA_ARGS__)

//EA accessory protocol for Sam4S printers
#define PROTOCOL_SHC_PRINTER_ACCESSORY_POS @"com.bncomspp.protocol"


#define PRINTER_NAME_PoS @"BnCOM"
#endif
