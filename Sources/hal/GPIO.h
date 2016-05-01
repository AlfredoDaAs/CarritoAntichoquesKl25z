/*
 * GPIO.h
 *
 *  Created on: Apr 1, 2016
 *      Author: AlfredoDaAs
 */

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file	GPIO Driver
	\author	Alfredo Dávila Assad
	\date	01-04-2016
	\brief	driver para uso de GPIO para uso de entrada y salidas de los puertos, archivo cabecera
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#ifndef	GPIO_H_
#define	GPIO_H_
    //--------------------------------------------------------------------------
    // Includes
    //--------------------------------------------------------------------------
	#include "Types.h"
	#include "derivative.h"
	#include "PORTCfgs.h"
    
    //--------------------------------------------------------------------------
    // Defines
    //--------------------------------------------------------------------------
	/*
		\def	gpio
		\brief	configurar mux para funcionar como gpio
	*/
	#define GPIO 1

	/*
		\def	input
		\brief	pin de entrada
	*/
	#define INPUT 0

	/*
		\def	output
		\brief	pin de salida
	*/
	#define OUTPUT 1

	#define BYTE_MASK 0xFF
    //--------------------------------------------------------------------------
    // Enums
    //--------------------------------------------------------------------------
	
    //--------------------------------------------------------------------------
    // Variables
    //--------------------------------------------------------------------------
	
    //--------------------------------------------------------------------------
    // Functions
    //--------------------------------------------------------------------------
    void vfnInitGpio(ePorts port);
    void vfnSetGPIOPortPins(ePorts port, U08 u08arrayPins[], U08 u08arrayPinsSize, U08 u08PinsDirection);
    void vfnSetBit(ePorts port, U08 u08Bit);
    void vfnClearBit(ePorts port, U08 u08Bit);
    void vfnSendByte(ePorts port, U08 u08Byte);
    U32 vfnReadData(ePorts port);
    
//------------------------------------------------------------------------------
#endif /* GPIO_H_ */
