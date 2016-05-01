/*
 * HC-SR04.h
 *
 *  Created on: Apr 13, 2016
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
#ifndef	HC_SR04_H_
#define	HC_SR04_H_
    //--------------------------------------------------------------------------
    // Includes
    //--------------------------------------------------------------------------
	#include "derivative.h"
	#include "Types.h"
	#include "nvic.h"
	#include "GPIO.h"
	#include "sysinit.h"
	#include "tpm_hc-sr04.h"
    //--------------------------------------------------------------------------
    // Defines
    //--------------------------------------------------------------------------
	/*
		\def
		\brief
	*/
	#define TPM_MODULE_HC_SR04    0xFFFF
	#define SNSR_1CM_hz	18518
	#define RSLTN	1000
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
   	void hc_sr04_init (void);
   	U16 hc_sr04_read (void);
	void hc_sr04_trigger(void);
    
//------------------------------------------------------------------------------
#endif /* HC_SR04_H_ */