 /*****************************************************************************
 *==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*
 /*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "TWI_int.h"
#include "TWI_private.h"
#include "EXT_EEPROM_int.h"
#include "EXT_EEPROM_private.h"
#include "LCD_Interface.h"



void H_EXT_EEPROM_void_Init(void)
{
	M_TWI_void_Init();
}

/***************************************************************************/

void H_EXT_EEPROM_void_Write(u16 Copy_u16ByteNo , u8 Copy_u8Data)
{


M_TWI_u8_StartCondition();

M_TWI_u8_SendSlaveAddressWrite( EXT_EEPROM_ADDRESS_SEQ | (u8)(Copy_u16ByteNo>>8)   );

M_TWI_u8_SendByte( (u8)Copy_u16ByteNo);

M_TWI_u8_SendByte(Copy_u8Data);

M_TWI_void_StopCondition();

	_delay_ms(10);
}

/***************************************************************************/
u8   H_EXT_EEPROM_void_Read(u16 Copy_u16ByteNo)
{
	u8 data = 0;
	u8 Local_u8Data=0 ;

	M_TWI_u8_StartCondition();

	M_TWI_u8_SendSlaveAddressWrite(EXT_EEPROM_ADDRESS_SEQ | (u8)(Copy_u16ByteNo>>8));
	M_TWI_u8_SendByte((u8)Copy_u16ByteNo);

	M_TWI_u8_RepeatedStart();

	M_TWI_u8_SendSlaveAddressRead( EXT_EEPROM_ADDRESS_SEQ | (u8)(Copy_u16ByteNo>>8));

	M_TWI_u8_ReadByte(&Local_u8Data);

	M_TWI_void_StopCondition();



	return Local_u8Data;
}
