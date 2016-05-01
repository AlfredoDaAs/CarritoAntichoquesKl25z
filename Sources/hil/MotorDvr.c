/*
 * MotorDvr.c
 *
 *  Created on: Apr 4, 2016
 *      Author: Alfredo
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
#include "MotorDvr.h"

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
U08 MoI_1 = NULL, MoI_2 = NULL, MoD_1 = NULL, MoD_2 = NULL;

ePorts myPort;

//------------------------------------------------------------------------------
/*!
    \fn
    \param
    \return
    \brief  
*/
void vfnInitMotors(ePorts port, U08 MI_1, U08 MI_2, U08 MD_1, U08 MD_2){
	myPort = port;
	MoI_1 = MI_1;
	MoI_2 = MI_2;
	MoD_1 = MD_1;
	MoD_2 = MD_2;
	
	vfnInitGpio(port);
	U08 u08Pines[] = {MI_1, MI_2, MD_1, MD_2};
	vfnSetGPIOPortPins(port, u08Pines, 4, OUTPUT);
}

void vfnParar(void){
	if(MoD_1 && MoD_2 && MoI_1 && MoI_2){
		vfnClearBit(myPort, MoI_1);
		vfnClearBit(myPort, MoI_2);
		vfnClearBit(myPort, MoD_1);
		vfnClearBit(myPort, MoD_2);
	}
}

void vfnAdelante(void){
	if(MoD_1 && MoD_2 && MoI_1 && MoI_2){
		vfnParar();
		vfnSetBit(myPort, MoI_2);
		vfnSetBit(myPort, MoD_2);
	}
}

void vfnAtras(void){
	if(MoD_1 && MoD_2 && MoI_1 && MoI_2){
		vfnParar();
		vfnSetBit(myPort, MoI_1);
		vfnSetBit(myPort, MoD_1);
	}
}

void vfnIzquierda(void){
	if(MoD_1 && MoD_2 && MoI_1 && MoI_2){
		vfnParar();
		vfnSetBit(myPort, MoD_2);	
	}
}

void vfnDerecha(void){
	if(MoD_1 && MoD_2 && MoI_1 && MoI_2){
		vfnParar();
		vfnSetBit(myPort, MoI_2);
	}
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

