#ifndef LCD_H_
#define LCD_H_


/*******************************************************************************
 *                      Dependencies                                           *
 *******************************************************************************/
#include <stdlib.h>
#include "../../MCAL/GPIO/DIO_Driver.h"
#include "../../MCAL/STK/Systick.h"

#include "../../UTILITIES/tm4c123gh6pm.h"
#include "../../UTILITIES/STD_TYPES.h"
#include "../../UTILITIES/Bit_Utilities.h"






/*******************************************************************************
*                      Configuration                                           *
 *******************************************************************************/
#define LCD_DATA_BITS_MODE 4

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

#define LCD_RS_PIN_ID       3                    
#define LCD_RW_PIN_ID       2           
#define LCD_EN_PIN_ID       1   



#define LCD_E_PORT_ID                  
#define LCD_E_PIN_ID                   

#define LCD_DATA_PORT_ID               

#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN_ID     4                 
#define LCD_DB5_PIN_ID     5           
#define LCD_DB6_PIN_ID     6           
#define LCD_DB7_PIN_ID     7           

#endif


/*******************************************************************************
 *                            LCD Commands                                     *
 *******************************************************************************/
/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
 /*Initialize the LCD*/

void LCD_init(void);

/*Send the passed command to the LCD*/
void LCD_sendCommand(uint8 command);

/*
 * Display the passed character on the screen
 */
void LCD_displayCharacter(uint8 data);

/*
 * Display the passed string on the screen
 */
void LCD_displayString(uint8 *str);

/*
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col);


/*
 * Display the required decimal value on the screen
 */
void LCD_integerToString(float64 data);

/*
 * Send the clear screen command
 */
void LCD_clearScreen(void);


#endif