

 /*****************************************************************************
 *==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*
 /*****************************************************************************/



/*************************************************************************************
 *                                  Files Inclusion                                  *
 *************************************************************************************/

/* User Defined Library Files */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "util/delay.h"
#include"DIO_Interface.h"


/* Module Header Files */
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"




/*************************************************************************************
 *                             Static Objects Definition                             *
 *************************************************************************************/


static u8 arr_COL_pins[COL_SIZE] = KEYPAD_ARR_COL_PINS  ;
static u8 arr_COL_port[COL_SIZE] = KEYPAD_ARR_COL_PORT  ;

static u8 arr_ROW_pins[ROW_SIZE] = KEYPAD_ARR_ROW_PINS  ;
static u8 arr_ROW_port[ROW_SIZE] = KEYPAD_ARR_ROW_PORT  ;



/*************************************************************************************
 *                             Public Function Definition                            *
 *************************************************************************************/


void KPD_voidInit(void)
{

	u8 counter = ZERO ;

	for( counter=ZERO ; counter<ROW_SIZE ; counter++ )
	{
		DIO_voidSetPinDirection( arr_ROW_port[counter] , arr_ROW_pins[counter] , PIN_OUTPUT ) ;
		DIO_voidSetPinValue( arr_ROW_port[counter] , arr_ROW_pins[counter] , PIN_HIGH ) ;
	}

	for( counter=ZERO ; counter<COL_SIZE ; counter++ )
	{

		DIO_voidSetPinDirection( arr_COL_port[counter] , arr_COL_pins[counter] , PIN_INPUT ) ;
		DIO_voidSetPinValue( arr_COL_port[counter] ,arr_COL_pins[counter] , PIN_HIGH ) ;

	}


}


/*****************************************************************************************/
u8 KPD_voidGetPressedKey(void)
{
	u8 counter1 ;                 //counter loop1
	u8 counter2 ;                 //counter loop2
	u8 get_key=KPD_NOT_PRESSED ;  //init val
	u8 pin_val ;                  // to get val of pin if 0 or 1

	u8 SwitchVal[ROW_SIZE][COL_SIZE] = KEYPAD_ARR_VAL ;

	for(counter1=ZERO ; counter1 < ROW_SIZE ; counter1++ )
	{
		DIO_voidSetPinValue(arr_ROW_port[counter1],arr_ROW_pins[counter1],PIN_LOW);

		for(counter2=ZERO ; counter2 < COL_SIZE ; counter2++ )
		{

			pin_val=DIO_voidGetBitValue( ( arr_COL_port[counter2] ) , (arr_COL_pins[counter2]) );

			if(pin_val==KPD_PRESSED)
			{
				get_key=SwitchVal[counter1][counter2]  ;

				while(pin_val==KPD_PRESSED)
				{
					pin_val=DIO_voidGetBitValue( ( arr_COL_port[counter2] ) , (arr_COL_pins[counter2]) );
				}

		   	DIO_voidSetPinValue(arr_ROW_port[counter1],arr_ROW_pins[counter1],PIN_HIGH);
				//return get_key ;
				break ;
			}

		}

		if(get_key!=0xff)
		{
			break ;
		}

		DIO_voidSetPinValue(arr_ROW_port[counter1],arr_ROW_pins[counter1],PIN_HIGH);

	}


	return get_key;
}


/*****************************************************************************************/







