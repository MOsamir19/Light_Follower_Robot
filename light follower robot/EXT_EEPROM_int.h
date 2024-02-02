/*****************************************************************************
 *==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*
 /*****************************************************************************/
#ifndef EXT_EEPROM_EXT_EEPROM_INT_H_
#define EXT_EEPROM_EXT_EEPROM_INT_H_



void H_EXT_EEPROM_void_Init(void);
void H_EXT_EEPROM_void_Write(u16 Copy_u16ByteNo,u8 Copy_u8Data);
u8   H_EXT_EEPROM_void_Read(u16 Copy_u16ByteNo);

#endif /* EXT_EEPROM_EXT_EEPROM_INT_H_ */
