/*****************************************************************************
 *==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*
 /*****************************************************************************/
#ifndef EXTINT_CONFIG_H_
#define EXTINT_CONFIG_H_

/*********************************************************/

/*
EXT_Init_DIR
EXT_Init_NORMAL
*/
#define EXT_Init_DIR

/*********************************************************/


/*---------------------------------------------------------*/

#ifdef EXT_Init_DIR

/*---------------------------------------------------------*/

/*
 * EXTINT_EN
 * EXTINT_DIS_EN
 */
#define EXT0  EXTINT_DIS_EN
#define EXT1  EXTINT_EN
#define EXT2  EXTINT_DIS_EN
/*********************************************************/
/*
 * RISING_EDGE
 * FALLING_EDGE
 */
#if EXT0 ==EXTINT_EN
#define EXT0_ControlSens  FALLING_EDGE
#endif

#if EXT1 == EXTINT_EN
#define EXT1_ControlSens  FALLING_EDGE
#endif



#if EXT2 == EXTINT_EN
#define EXT1_ControlSens  FALLING_EDGE
#endif
/*********************************************************/


#endif





#endif /* EXTINT_CONFIG_H_ */
