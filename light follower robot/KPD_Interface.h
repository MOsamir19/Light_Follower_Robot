#ifndef _KPD_INT_H
#define _KPD_INT_H



#define KPD_NOT_PRESSED  (u8)(0XFF)
#define KPD_PRESSED      (u8)(0)

/*************************************************************************************
 *                     Public Function Prototypes                                    *
 *************************************************************************************/
/*
 *  H_KPD_void_Init
 *  	-> This function shall initialize the Keypad i.e., sets all Rows as /P
 *  	   and all Columns as Pulled-up I/P.
 */
void KPD_voidInit(void);
/*
 *  H_KPD_void_GetPressedKey
 *  	-> This function shall return the value of the pressed key
 *  	   or KPD_NOT_PRESSED otherwise.
 */
u8 KPD_voidGetPressedKey(void);

#endif /* _KPD_INT_H */
