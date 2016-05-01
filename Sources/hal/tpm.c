/*
 * tpm.c
 *
 *  Created on: Jul 16, 2013
 *      Author: B34443
 */
#include "tpm.h"

void vfnSelectChannelPortPin(ePorts port, U08 u08Pin){
	U08 u08pines[] = {u08Pin};
	vfnConfigPortRegPins(port, u08pines, 1, TPM_MUX);
}

void TPM_init_PWM(TPM_MemMapPtr TPMx, U08  clock_source, U16 module, U08 clock_mode, U08 ps, U08 counting_mode)
{
	if(TPMx == TPM0_BASE_PTR)
		SIM_SCGC6	|= SIM_SCGC6_TPM0_MASK;
	else if(TPMx == TPM1_BASE_PTR)
		SIM_SCGC6	|= SIM_SCGC6_TPM1_MASK;
	else
		SIM_SCGC6	|= SIM_SCGC6_TPM2_MASK;
	
	//8MHz clock 
	SIM_SOPT2	|= SIM_SOPT2_TPMSRC(clock_source);
	
	TPM_MOD_REG(TPMx)  	=  module;
	
	TPM_SC_REG(TPMx)	|= TPM_SC_CMOD(clock_mode) | TPM_SC_PS(ps);
	
	if(counting_mode)
		TPM_SC_REG(TPMx) |= TPM_SC_CPWMS_MASK;
}

void TPM_CH_init(TPM_MemMapPtr TPMx, U08 channel, U08 mode)
{
	TPM_CnSC_REG(TPMx, channel) |= mode;
}

void set_TPM_CnV(TPM_MemMapPtr TPMx, U08 channel, U16 value)
{
	TPM_CnV_REG(TPMx, channel) = value;
}

void set_pos(U16 duty)
{
	set_TPM_CnV(TPM1_BASE_PTR, 1, duty);
}

void vfnDelayTpm(U32 u32Delay){
	while(u32Delay){
		u32Delay--;
	}
}
