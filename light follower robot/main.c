

/*****************************************************************************
 *==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*
 /*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_Interface.h"
#include "EXTINT_Interface.h"
#include "UART_Interface.h"
#include "SPI_Interface.h"
#include "GIE_Interface.h"
#include "ADC_Interface.h"
#include "TMR0_Interface.h"
#include "KPD_Interface.h"
#include "LCD_Interface.h"
#include "TIMER1_int.h"
#include "TWI_int.h"
#include "EXT_EEPROM_int.h"

#include"string.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
//#include "avr/io.h"
//#undef  F_CPU
//#define F_CPU (16000000UL)



int main()
{


	u16 DATA[4] ={0} ;
	u16 DATA_NEW =0 ;
	u16 DATA_OLD =5 ;
	u16 MAX =0;
	u8 i=0 ;
	u8 y=4 ;


	LCD_voidInit();
	ADC_voidInit() ;



	DIO_voidSetPinDirection(PORTA_ID,PIN0,PIN_INPUT);
	DIO_voidSetPinDirection(PORTA_ID,PIN1,PIN_INPUT);
	DIO_voidSetPinDirection(PORTA_ID,PIN2,PIN_INPUT);
	DIO_voidSetPinDirection(PORTA_ID,PIN3,PIN_INPUT);

	DIO_voidSetPinDirection(PORTD_ID,PIN0,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTD_ID,PIN1,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTD_ID,PIN2,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTD_ID,PIN3,PIN_OUTPUT);



	while(1)
	{
		ADC_voidChannelMulBoling(DATA);

		MAX = 0 ;
		for(i=0 ; i<4 ; i++)
		{

			if(DATA[i] > MAX)
			{
				MAX = DATA[i]  ;
				y = i ;
			}
			else if(MAX == DATA[i]) {
				y = 4 ;
			}
			DATA_NEW =y ;
		}



		if(DATA_OLD!=DATA_NEW)
		{
			LCD_voidClear();

			switch(y)
			{
			case 0 : LCD_voidWriteString((u8*)"Moving Forward") ;
			DIO_voidSetPinValue(PORTD_ID,PIN0,PIN_HIGH);
			DIO_voidSetPinValue(PORTD_ID,PIN1,PIN_LOW);

			DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_HIGH);
			DIO_voidSetPinValue(PORTD_ID,PIN3,PIN_LOW);
			break ;

			case 1 : LCD_voidWriteString((u8*)"Moving Right") ;
			DIO_voidSetPinValue(PORTD_ID,PIN0,PIN_LOW);
			DIO_voidSetPinValue(PORTD_ID,PIN1,PIN_LOW);

			DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_HIGH);
			DIO_voidSetPinValue(PORTD_ID,PIN3,PIN_LOW);
			break ;

			case 2 :  LCD_voidWriteString((u8*)"Moving Back") ;
			DIO_voidSetPinValue(PORTD_ID,PIN0,PIN_LOW);
			DIO_voidSetPinValue(PORTD_ID,PIN1,PIN_HIGH);

			DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_LOW);
			DIO_voidSetPinValue(PORTD_ID,PIN3,PIN_HIGH);

			break ;


			case 3 :
				LCD_voidWriteString((u8*)"Moving Left") ;
				DIO_voidSetPinValue(PORTD_ID,PIN0,PIN_HIGH);
				DIO_voidSetPinValue(PORTD_ID,PIN1,PIN_LOW);

				DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_LOW);
				DIO_voidSetPinValue(PORTD_ID,PIN3,PIN_LOW);
				break ;

			default :  LCD_voidWriteString((u8*)"STOP") ;
			DIO_voidSetPinValue(PORTD_ID,PIN0,PIN_LOW);
			DIO_voidSetPinValue(PORTD_ID,PIN1,PIN_LOW);

			DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_LOW);
			DIO_voidSetPinValue(PORTD_ID,PIN3,PIN_LOW);
			break ;
			}

		}

		DATA_OLD = DATA_NEW ;

	}



	return 0 ;
}






