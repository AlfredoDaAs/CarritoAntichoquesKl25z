/*
 * tpm.h
 *
 *  Created on: Jul 16, 2013
 *      Author: B34443
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
#ifndef	TPM_H_
#define	TPM_H_
    //--------------------------------------------------------------------------
    // Includes
    //--------------------------------------------------------------------------
	#include "Types.h"
	#include "derivative.h"
	#include "PORTCfgs.h"
	#include "GPIO.h"
    
    //--------------------------------------------------------------------------
    // Defines
    //--------------------------------------------------------------------------
	/*
		\def
		\brief
	*/
	#define TPM_PLLFLL 		1
	#define TPM_OSCERCLK 	2
	#define TPM_MCGIRCLK	3
	
	#define	TPM_CNT_DIS	0
	#define	TPM_CLK		1
	#define	TPM_EXT_CLK	2
	
	#define PS_1	0
	#define PS_2	1
	#define PS_4	2
	#define PS_8	3
	#define PS_16	4
	#define PS_32	5
	#define PS_64	6
	#define PS_128	7
	
	#define TPM_OC_TOGGLE	TPM_CnSC_MSA_MASK|TPM_CnSC_ELSA_MASK
	#define TPM_OC_CLR		TPM_CnSC_MSA_MASK|TPM_CnSC_ELSB_MASK
	#define TPM_OC_SET		TPM_CnSC_MSA_MASK|TPM_CnSC_ELSA_MASK|TPM_CnSC_ELSB_MASK
	#define TPM_OC_OUTL		TPM_CnSC_MSB_MASK|TPM_CnSC_MSA_MASK|TPM_CnSC_ELSB_MASK
	#define TPM_OC_OUTH		TPM_CnSC_MSB_MASK|TPM_CnSC_MSA_MASK|TPM_CnSC_ELSA_MASK
	
	#define TPM_PWM_H 		TPM_CnSC_MSB_MASK|TPM_CnSC_ELSB_MASK
	#define TPM_PWM_L		TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK
	
	#define EDGE_PWM		0
	#define CENTER_PWM		1
	
	//#define TPM_MODULE  3750 52816
	#define TPM_MODULE  52816
	//#define DUTY_MIN	220
	#define DUTY_MIN	1800 //antes 2000
	//#define DUTY_MAX	350

	#define DUTY_MED	3700
	//3000

	#define DUTY_MAX	5900

	#define TPM_MUX 3

#define TIMER 1000000
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
	void vfnSelectChannelPortPin(ePorts port, U08 u08Pin);
    void TPM_init_PWM(TPM_MemMapPtr TPMx, U08  clock_source, U16 module, U08 clock_mode, U08 ps, U08 counting_mode);
	void TPM_CH_init(TPM_MemMapPtr TPMx, U08 channel, U08 mode);
	void set_TPM_CnV(TPM_MemMapPtr TPMx, U08 channel, U16 value);
	void set_pos(U16 angle);
	void vfnDelayTpm(U32 u32Delay);
    
//------------------------------------------------------------------------------
#endif /* TPM_H_ */
