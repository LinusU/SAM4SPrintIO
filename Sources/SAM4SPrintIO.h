//
//  SAM4SPrintIO.h
//  SHCLibrary
//
//  Created by Ambiga on 13/05/15.
//  Copyright (c) 2015 SHCLibrary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PrinterConnection.h"
#import "PrintIOStream.h"
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

#import "Printer.h"
#import "ConnectionManager.h"
#import "BTConnection.h"
#import "WiredConnection.h"

#define SHARPEN_MODE_OFF 0
#define SHARPEN_MODE_ON 1
#define SHARPEN_MODE_ON_MORE 2

#define BRIGHTNESS_DEFAULT 128

@class Filter;
enum ALIGNMENT
{
    LEFT,
    CENTER,
    RIGHT
};
enum TEXTDIRECTION
{
    DIRECTION_LEFT_TO_RIGHT,
    DIRECTION_BOTTOM_TO_TOP,
    DIRECTION_RIGHT_TO_LEFT,
    DIRECTION_TOP_TO_BOTTOM
};
enum CUTTYPE
{
    CUT_NO_FEED,
    CUT_FEED
};
enum BARCODETYPE
{
    UPC_A,
    UPC_E,
    EAN13,
    JAN13,
    EAN8,
    JAN8,
    CODE_39,
    ITF,
    CODABAR,
    CODE_93,
    CODE_128
};
enum HRI
{
    NONE,
    ABOVE,
    BELOW,
    BOTH
};

enum FONT{
    FONT_A,
    FONT_B
};
enum LANGUAGE{
    ENG,
    KOR
};
enum TWODCODETYPE{
    STANDARD,
    QR_CODE_MODEL1
};
enum ERRORCORRECTIONSTANDARD{
    LEVEL_0,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    LEVEL_4,
    LEVEL_5,
    LEVEL_6,
    LEVEL_7,
    LEVEL_8
};
enum ERRORCORRECTIONQRMODEL{
    LEVEL_L,
    LEVEL_M,
    LEVEL_Q,
    LEVEL_H
};
enum COLOUR{
    COLOR_NONE,
    COLOR_1,
    COLOR_2
};
enum PRINTMODE
{
    NORMAL,
    DOUBLE_WIDE,
    DOUBLE_HIGH,
    QUADRAPLE
};
enum CASHDRAWER
{
    DRAWER_1,
    DRAWER_2
};
enum PAGEDIRECTION
{
   PAGE_DIRECTION_LEFT_TO_RIGHT,
   PAGE_DIRECTION_BOTTOM_TO_TOP,
   PAGE_DIRECTION_RIGHT_TO_LEFT,
   PAGE_DIRECTION_TOP_TO_BOTTOM
};
enum CHARACTERCODE
{
    CHARACTER_CODE_PC437,
    CHARACTER_CODE_KATAKANA,
    CHARACTER_CODE_PC850,
    CHARACTER_CODE_PC860,
    CHARACTER_CODE_PC863,
    CHARACTER_CODE_PC865,
    CHARACTER_CODE_PC737,
    CHARACTER_CODE_WPC1252,
    CHARACTER_CODE_PC866,
    CHARACTER_CODE_PC852,
    CHARACTER_CODE_PC858,
    CHARACTER_CODE_THAI11,
    CHARACTER_CODE_THAI18,
    CHARACTER_CODE_PC775,
    CHARACTER_CODE_PC855,
    CHARACTER_CODE_PC862,
    CHARACTER_CODE_PC864,
    CHARACTER_CODE_FARSI,
    CHARACTER_CODE_WPC1250,
    CHARACTER_CODE_WPC1251,
    CHARACTER_CODE_WPC1253,
    CHARACTER_CODE_WPC1255,
    CHARACTER_CODE_WPC1256,
    CHARACTER_CODE_WPC1257,
    CHARACTER_CODE_THAI_STANDARD_620,
    CHARACTER_CODE_THAI42,
    CHARACTER_CODE_THAI14,
    CHARACTER_CODE_THAI16,
    CHARACTER_CODE_SYSTEM_IRAN_CODE,
    CHARACTER_CODE_SPACE_PAGE
};

@interface SAM4SPrintIO : PrintIOStream
{
    UInt8 *mDataArray;
    NSMutableArray *commandList;

}
/*!
 * @discussion Initializes the command buffer, which contains the commands to clear and initialize the Printer buffer.
 */
-(void)PrinterSetup;
/*!
 * @discussion initialize the printer in for image printing.Performed by the printer to signal certain conditions.
 */
- (void)initializePrinterForImagePrinting;
/*!
 * @discussion Generates an audible beep tone.
 */
-(void)addTone;
/*!
 * @discussion Get the printer  ID
 */
-(void)getPrinterID;
/*!
 * @discussion Get the printer  firmware version
 */
-(void)getPrinterFirmware;
/*!
 * @discussion Get the printer Manufacturer name
 */
-(void)getPrinterManufacturer;
/*!
 * @discussion Get the printer font
 */
-(void)getPrinterFont;
/*!
 * @discussion Get the printer Name
 */
-(void)getPrinterName;
/*!
 * @discussion Cuts the receipt, with paper feed or without paper feed as specified by the argument.
 * @param type - This should be either Feed Cut or No feed Cut.
 */
-(void)addCut:(enum CUTTYPE)cutType;
/*!
 * Used to open a cash drawer.
 * @param drawerNo - This is the Pin number to generate pulse.
 * @param time - This is the Start time to generate pulse.
 */
- (void)addOpenCashDrawer : (enum CASHDRAWER)drawerNo : (int)time;
/*!
 * used to add a black mark in the  specified cutting position.
 * @param dbCuttingPosition - This is the Position to add a black mark.
 */
- (void)addBlackMark :(double) dbCuttingPosition;
/*!
 * @discussion Feed with paper feed as specified by the argument.
 * @param Unit - This should be integer to feed paper.
 */
-(void)addFeedLine : (int)line;

-(void)addFeedUnit : (int)Unit;
/*!
* @discussion adds text to printer buffer
* @param text - This should be a string.
*/
-(void)addTextData: (NSString*)text;
/*!
 * @discussion This function is used to specify the font of characters, graphics, logos, and bar codes on the receipt station.
 * @param font - font can be Font_A, Font_B
 */
- (void)addTextFont:(enum FONT)font;
/*!
 * @discussion This function is used to specify the alignment of characters, graphics, logos, and bar codes on the receipt station.
 * @param alignment - Alignment can be Left,Center,Right
 */
- (void)addTextAlignment:(enum ALIGNMENT)alignment;
/*!
 * @discussion This function is used to specify the language of characters on the receipt station.
 * @param language - language can be KOR, ENG
 */
- (void)addTextLanguage:(enum LANGUAGE)language;
/*!
 * @discussion This function is used to specify the line space for characters on the receipt station.
 * @param space - space can be integer
 */
- (void)addLineSpace:(int)space;
/*!
 * @discussion This function is used to specify the bold for characters on the receipt station.
 * @param set - align can be yes or no
 */
-(void)addTextBold : (BOOL)set;
/*!
 * @discussion This function is used to specify the underline for characters on the receipt station.
 * @param set - set can be yes or no
 */
-(void)addTextUnderline : (BOOL)set;
/*!
 * @discussion This function is used to specify the reverse printing is on or off for characters on the receipt station.
 * @param set - set can be yes or no
 */
- (void)addReverse : (BOOL)isBoolOn;
/*!
 * @discussion This function is used to specify the text printing  direction for characters on the receipt station.
 * @param direction - direction can be enum integer
 */
- (void)addTextDirection : (enum TEXTDIRECTION)direction;
/*!
 * @discussion This function is used to specify the text width or height or both as souble-sized for characters on the receipt station.
 * @param doubleWidth - doubleWidth can be Yes or No
 * @param doubleHeight - doubleHeight can be Yes or No
 */
- (void)addTextDouble : (BOOL)doubleWidth : (BOOL)doubleHeight;
/*!
 * @discussion This function is used to specify the char code for characters on the receipt station.
 * @param characterCode - characterCode can be integer
 */
- (void)addCharacterCode : (enum CHARACTERCODE)characterCode;
/*!
 * @discussion This function is used to specify the text height & width for characters on the receipt station.
 * @param width & height - width & height can be 1 to 8
 */
-(void)addTextSize : (int)width :(int)height;
/*!
 * @discussion This function is used to specify the text x position for characters on the receipt station.
 * @param position - position can be 0
 */
-(void)addTextPosition: (int)xposition;
/*!
 * @discussion This function is used to specify the text style for characters on the receipt station.
 * @param reverse - reverse can be yes or no
 * @param underline - underline can be yes or no
 * @param bold - bold can be yes or no
 * @param color - color can be yes or no
 */
- (void)addTextStyle:(BOOL)reverse :(BOOL)underline :(BOOL)bold :(int)color;
/*!
 * @discussion This function is used to print downloaded logo on receipt.
 * @param imageNo - - should be stored image No
 * @param logomode - should be one of (Normal,Double-Wide,Double-High,Quadruple)
 */
- (void)addLogo:(int)imageNo : (enum PRINTMODE)logomode;
/*!
* @discussion This function is used to specify the image & size of the image on the receipt station.
* param data - data can be image's binary value
* @param width - width can be integer
* @param height - height can be a integer
* @param imageMode - printing mode for the image
*/
-(void) addImageData:(UIImage *) chosenImage imageWidth:(int) width imageHeight:(int)height imageMode:(enum PRINTMODE)imageMode;
/*!
 * @discussion This function is used to specify the image & size of the image with sharpness & brightness values on the receipt station.
 * param data - data can be image's binary value
 * @param width - width can be integer
 * @param height - height can be a integer
 * @param imageMode - printing mode for the image
 * @param shapern_mode - values are sharpen to
 *               SHARPEN_MODE_OFF 0
 *               SHARPEN_MODE_ON 1
 *               SHARPEN_MODE_ON_MORE 2
 * @param brightness - This should be an integer
 */
-(void) addImageWithData:(UIImage *) chosenImage imageWidth:(int) width imageHeight:(int)height imageMode:(enum PRINTMODE)imageMode sharpenMode : (int)shapern_mode imageBrightness :(int)brightness;
/*!
 * @discussion Bar Code : This function is used to generate the barcode based on the Parameter
 * @param height
 * @param width
 * @param hri
 * @param type
 * @param text
 */
-(void)addBarcode :(NSData *)text : (enum BARCODETYPE)type : (enum HRI)hri  : (enum FONT)font : (int)width : (int)height;
/*!
 * @discussion Two D code : This function is used to generate the two dimensional barcode  - PDF 417 based on the Parameter
 * @param maxSize
 * @param height
 * @param width
 * @param error
 * @param type
 * @param text
 */
-(void)addPDF417Symbol : (NSData *)text : (enum TWODCODETYPE)type : (enum ERRORCORRECTIONSTANDARD)error : (int)width : (int)height;
/*!
 * @discussion Two D code : This function is used to generate the two dimensional barcode  - QRCode based on the Parameter
 * @param maxSize
 * @param error
 * @param type
 * @param text
 */
-(void)addQRCodeSymbol : (NSData *)text : (enum TWODCODETYPE)type : (enum ERRORCORRECTIONQRMODEL)error : (int)maxSize;
/*!
 * @discussion adds page begin to printer buffer for page mode
 */
-(void)addPageBegin;
/*!
 * @discussion adds page end to printer buffer for page mode
 */
-(void)addPageEnd;
/*!
 * @discussion This function is used to specify the page area of x, y, height & width for page on the receipt station.
 * @param x, y, width & height - x, y, width & height can be integer
 */
-(void)addPageArea:(int)x :(int)y : (int)width : (int)height ;
/*!
 * @discussion This function is used to specify the direction of the page on the receipt station.
 * @param direction - direction can be integer
 */
-(void)addPageDirection : (enum PAGEDIRECTION)direction;
/*!
 * @discussion This function is used to specify the page position of x and y for characters on the receipt station.
 * @param x & y - x & Y can be integer
 */
-(void)addPagePosition : (int)x : (int)y ;
/*!
 * @discussion In page mode, print all buffered data in the printing area collectively.
 */
-(void)addPageFormFeed;
/*!
 * @discussion turn off the ASB
 */
-(void)turnOFFASB;
/*!
 * @discussion Retrieve the printer status
 * @param isASBTurnedON -  thould be YES or NO
 * YES - Turned ON to receive status from the printer
 * NO - Turned OFF This won't receive status from the printer
 */
-(void) getPrinterStatus : (BOOL)isASBTurnedON;
/*!
 * @discussion Reset the printer
 */
-(void)resetPrinter;
/*!
 * @discussion Returns the NSData instance containing the contents of the command buffer
 */
-(NSData*)getDataTosend:(SAM4SPrintIO *)printIO;

@end
