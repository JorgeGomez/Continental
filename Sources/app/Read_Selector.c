/*============================================================================*//*                                TEAM 1		                              */
/*============================================================================*/
/*                        TEAM 7 				                               */
/*============================================================================*
* C Source:         Read_Selector.c
* Instance:         RPL_1
* version:         	1
* Created_by:       Jorge G�mez
* Date_created:     Tue March 17 19:41:00 2015 
*=============================================================================*/
/* DESCRIPTION : C source for Read and selector functions file                */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source for some fuctions	  */
/* For the proyect AutoLamps								                  */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 17/04/2014  |                               | Jorge Gomez      */
/* 								                                              */
/*============================================================================*/

#include "Read_Selector.h"
enum {
	STATE_ONE,
	STATE_TWO,
	STATE_THREE,
	STATE_FOUR,
	STATE_FIVE,
	STATE_SIX,
	STATE_SEVEN,
	STATE_EIGHT
};
T_UWORD ruw_LightIntensity = 0;
T_UWORD ruw_LightPorcent = 0;
T_UWORD ruw_SelectorState = STATE_ONE;
T_UWORD ruw_previusState = 0;


PUBLIC_FCT void ReadPort_Selector(void)
{
	ruw_SelectorState &= 0;				//Clears Variable for next selector reading
	ruw_SelectorState |= Digital_Read();		//Reads Selector's position
}

PUBLIC_FCT void SelectorFunction(void)
{
	switch(ruw_SelectorState)					
	 	 {
	 	 	case STATE_ONE:
	 	 		ruw_SelectorState=STATE_TWO;
	 	 		break;
	 	 	case STATE_TWO:
	 	 		ruw_SelectorState=STATE_THREE;
	 	 		break;
	 	 	case STATE_THREE:
	 	 		ruw_SelectorState=STATE_FOUR;
	 	 		break;
	 	 	case STATE_FOUR:
	 	 		ruw_SelectorState=STATE_FIVE;
	 	 		break;
	 	 	case STATE_FIVE:
	 	 		ruw_SelectorState=STATE_SIX;
	 	 		break;
	 	 	case STATE_SIX:
	 	 		ruw_SelectorState=STATE_SEVEN;
	 	 		break;
	 	 	case STATE_SEVEN:
	 	 		ruw_SelectorState=STATE_EIGHT;
	 	 		break;
	 	 	case STATE_EIGHT:
	 	 		ruw_SelectorState=STATE_ONE;
	 	 		break;	 		
	 		default:
	 			//THIS STATE SHOUL NEVER HAPPEN
	 			break;
	 	 }
}
