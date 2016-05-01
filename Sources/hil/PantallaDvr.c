/*
 * PantallaDvr.c
 *
 *  Created on: Apr 10, 2016
 *      Author: AlfredoDaAs
 */
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file
	\author
	\date
	\brief	
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "PantallaDvr.h"

//------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------
/*!
    \def
    \brief
*/


//------------------------------------------------------------------------------
// Enums
//------------------------------------------------------------------------------
/*!
    \enum
    \brief
*/


//------------------------------------------------------------------------------
// Variables
//------------------------------------------------------------------------------
/*!
    \var
    \brief
*/

U08 u08PinesControl[] = {RS, E};
U08 u08PinesDatos[] = {PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7};

//Cursor Blink off initialization
const unsigned char InitializeLCD[5] = {0x38, 0x0C, 0x01};
//------------------------------------------------------------------------------
/*!
    \fn
    \param
    \return
    \brief  
*/
void vfnInitPantalla(void){ 
	//pines de control
	vfnInitGpio(PORTB);
	vfnSetGPIOPortPins(PORTB, u08PinesControl, 2, OUTPUT);
	
	//pines de datos
	vfnInitGpio(PORTC);
	vfnSetGPIOPortPins(PORTC, u08PinesDatos, 8, OUTPUT);
	
	U08 u08initializeLCD;
	
	for(u08initializeLCD = 0; u08initializeLCD < 5; u08initializeLCD++)
	{
		vfnSendData(INSTRUCTION, InitializeLCD[u08initializeLCD]);
	}
}

void vfnSendData(U08 u08Type, U08 u08Code){
	vfnClearBit(PORTB, RS);
	vfnClearBit(PORTB, E);
	
	vfnSendByte(PORTC, u08Code);
	
	if(u08Type == INSTRUCTION){
		vfnSetBit(PORTB, E);
		//vfnDelayPantalla(_40_USEC);
		time_delay_ms(2);
	}else if(u08Type == DATA){
		vfnSetBit(PORTB, RS);
		vfnSetBit(PORTB, E);
		//vfnDelayPantalla(_15_MSEC);
		time_delay_ms(2);
	}
	
	vfnClearBit(PORTB, RS);
	vfnClearBit(PORTB, E);
}

void vfnDelayPantalla(U32 u32Delay){
	while(u32Delay){
		u32Delay--;
	}
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

