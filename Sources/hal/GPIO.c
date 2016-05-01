/*
 * GPIO.c
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
	\brief	driver para uso de GPIO para uso de entrada y salidas de los puertos, archivo para contenido de funciones	
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "GPIO.h"

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
U32 arrSIM_SCGC5_PORTS[] = {SIM_SCGC5_PORTA_MASK, SIM_SCGC5_PORTB_MASK, SIM_SCGC5_PORTC_MASK, SIM_SCGC5_PORTD_MASK, SIM_SCGC5_PORTE_MASK};

/*!
    \var
    \brief
*/
GPIO_MemMapPtr arrGPIOBasePtrs[] = GPIO_BASE_PTRS;

//------------------------------------------------------------------------------
/*!
    \fn		vfnInitGpio
    \param	port
    \return	
    \brief  activa el clock del puerto
*/
void vfnInitGpio(ePorts port){
	SIM_SCGC5 |= arrSIM_SCGC5_PORTS[port];
}


/*!
    \fn		vfnSetIOPortPins
    \param	puerto, arreglo de los pines a configurar, direccion de entrada o salida 
    \return
    \brief  configurar los pines de un puerto como entrada o salida.
*/
void vfnSetGPIOPortPins(ePorts port, U08 u08arrayPins[], U08 u08arrayPinsSize, U08 u08PinsDirection){
	U08 x;

	vfnConfigPortRegPins(port, u08arrayPins, u08arrayPinsSize, GPIO);
	
	for(x = 0; x < u08arrayPinsSize; x++){
		GPIO_PSOR_REG(arrGPIOBasePtrs[port]) |= GPIO_PSOR_PTSO(1<<u08arrayPins[x]);
	}
	
	if(u08PinsDirection & (U08)OUTPUT){
		for(x = 0; x < u08arrayPinsSize; x++){
			GPIO_PDDR_REG(arrGPIOBasePtrs[port]) |= GPIO_PDDR_PDD(1<<u08arrayPins[x]); 
		}
	}else{
		for(x = 0; x < u08arrayPinsSize; x++){
			GPIO_PDDR_REG(arrGPIOBasePtrs[port]) &= ~(GPIO_PDDR_PDD(1<<u08arrayPins[x])); 
		}
	}
}

/*!
    \fn		vfnSetBit
    \param	puerto, bit del puerto
    \return
    \brief  setear el bit de puerto enviado
*/
void vfnSetBit(ePorts port, U08 u08Bit){
	U32_SET_BIT(GPIO_PDOR_REG(arrGPIOBasePtrs[port]), u08Bit);
}

/*!
    \fn		vfnClearBit
    \param	puerto, bit del puerto
    \return
    \brief  limpiar el bit de puerto enviado
*/
void vfnClearBit(ePorts port, U08 u08Bit){
	U32_CLEAR_BIT(GPIO_PDOR_REG(arrGPIOBasePtrs[port]), u08Bit);
}

/*!
    \fn		vfnReadData
    \param
    \return	registro del puerto
    \brief  obtiene los datos del puerto deseado
*/
U32 vfnReadData(ePorts port){
	return (U32)GPIO_PDOR_REG(arrGPIOBasePtrs[port]);
}

void vfnSendByte(ePorts port, U08 u08Byte){
	GPIO_PDOR_REG(arrGPIOBasePtrs[port]) |= (u08Byte);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

