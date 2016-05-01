/*
 * Timer.c
 *
 *  Created on: Mar 12, 2016
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
#include "derivative.h"
#include "Timer.h"
#include "LEDDvr.h"

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

//------------------------------------------------------------------------------
/*!
    \fn
    \param
    \return
    \brief  
*/
void vfnTimerInit(void)
{
	NVIC_ISER |= (1<<22);
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
	PIT_MCR = 0x00;	
	PIT_TCTRL1 = PIT_TCTRL_TEN_MASK;//interrupcion
	PIT_LDVAL1 = 0x44AA1D;//900ms
	PIT_TCTRL1 = PIT_TCTRL_TIE_MASK;//900ms
}

/*!
    \fn
    \param
    \return
    \brief  
*/
void vfnSetTimer(U32 u32LDVAL)
{
	PIT_TCTRL1 &= ~(PIT_TCTRL_TEN_MASK);
	PIT_LDVAL1 = u32LDVAL;
	PIT_TCTRL1 |= PIT_TCTRL_TEN_MASK;
	PIT_TFLG1 |= (1<<31);
}

/*!
    \fn
    \param
    \return
    \brief  
*/
void vfnStopTimer(void)
{
	PIT_TCTRL1 &= ~(PIT_TCTRL_TEN_MASK);
}

/*!
    \fn
    \param
    \return
    \brief  
*/
void vfnPit1_IRQ(void)
{
	vfnLedToogle();
	vfnSetTimer(0x44AA1D);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
