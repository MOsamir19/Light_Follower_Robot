#ifndef _KPD_CFG_H
#define _KPD_CFG_H


/*

#define KPD_PORT_COL    PORTD_ID
#define KPD_PORT_ROW    PORTB_ID

#define COL_START   PIN7    //  First Column is PIN2
#define COL_END     PIN3      //  Last  Column is PIN5

#define ROW_START   PIN5     // First Row    is PIN4
#define ROW_END     PIN2      //Last  Row    is PIN7

 */


/*****************************************************************************************/

#define ROW_SIZE         (u8)(4)
#define COL_SIZE         (u8)(4)


/*****************************************************************************************/
#define KPD_COL0_PIN       PIN7
#define KPD_COL0_PORT      PORTD_ID

#define KPD_COL1_PIN       PIN6
#define KPD_COL1_PORT      PORTD_ID

#define KPD_COL2_PIN       PIN5
#define KPD_COL2_PORT      PORTD_ID

#define KPD_COL3_PIN       PIN3
#define KPD_COL3_PORT      PORTD_ID


/*****************************************************************************************/
#define KPD_ROW0_PIN       PIN5
#define KPD_ROW0_PORT      PORTC_ID

#define KPD_ROW1_PIN       PIN4
#define KPD_ROW1_PORT      PORTC_ID

#define KPD_ROW2_PIN       PIN3
#define KPD_ROW2_PORT      PORTC_ID

#define KPD_ROW3_PIN       PIN2
#define KPD_ROW3_PORT      PORTC_ID

/*****************************************************************************************/

#define KEYPAD_ARR_COL_PORT  { KPD_COL0_PORT , KPD_COL1_PORT , KPD_COL2_PORT , KPD_COL3_PORT }
#define KEYPAD_ARR_COL_PINS  { KPD_COL0_PIN , KPD_COL1_PIN , KPD_COL2_PIN ,KPD_COL3_PIN }

#define KEYPAD_ARR_ROW_PORT  { KPD_ROW1_PORT , KPD_ROW1_PORT , KPD_ROW2_PORT , KPD_ROW3_PORT }
#define KEYPAD_ARR_ROW_PINS  { KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN ,KPD_ROW3_PIN }



/*****************************************************************************************/

#define KEYPAD_ARR_VAL  {   {'7','8','9','/'},  \
		                    {'4','5','6','*'},  \
	                     	{'1','2','3','-'},  \
	                     	{'C','0','=','+'}   }


/*#define KEYPAD_ARR_VAL {  {0x07, 0x08, 0x09, 0x0A }, \
                            {0x04, 0x05, 0x06, 0x0B }, \
                            {0x01, 0x02, 0x03, 0x0C }, \
                            {0x0E, 0x00, 0x0F, 0x0D } }
 */



/*
#define KEYPAD_ARR_VAL   { {55, 65, 75, 85 }, \
                             {90, 100, 45, 35}, \
                             {50, 60, 70, 80 }, \
                             {10, 20, 30, 40 } }
 */






#endif /* _KPD_CFG_H */
