/*
 * Timer.h
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
#ifndef	TIMER_H_
#define	TIMER_H_
    //--------------------------------------------------------------------------
    // Includes
    //--------------------------------------------------------------------------
#include "Types.h"
    
    //--------------------------------------------------------------------------
    // Defines
    //--------------------------------------------------------------------------
	/*
		\def
		\brief
	*/
    //--------------------------------------------------------------------------
    // Enums
    //--------------------------------------------------------------------------
	/*
		\enum
		\brief
	*/
    //--------------------------------------------------------------------------
    // Variables
    //--------------------------------------------------------------------------


    //--------------------------------------------------------------------------
    // Functions
    //--------------------------------------------------------------------------
    void vfnPit1_IRQ(void);
    void vfnStopTimer(void);
    void vfnSetTimer(U32 u32LDVAL);
    void vfnTimerInit(void);
    
//------------------------------------------------------------------------------
#endif
