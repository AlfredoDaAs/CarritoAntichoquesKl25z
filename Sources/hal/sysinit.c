/*
 * sysinit.c
 *
 *  Created on: May 27, 2013
 *      Author: B34443
 */

#include "sysinit.h"

int mcg_clk_hz;
int mcg_clk_khz;
int core_clk_khz;
int periph_clk_khz;
int pll_clk_khz;
int uart0_clk_khz;
uint32_t uart0_clk_hz;


void sysinit(void)
{
	 /* Enable all of the port clocks. These have to be enabled to configure
	 * pin muxing options, so most code will need all of these on anyway.
	 */
	/*SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK
			  | SIM_SCGC5_PORTB_MASK
			  | SIM_SCGC5_PORTC_MASK
			  | SIM_SCGC5_PORTD_MASK
			  | SIM_SCGC5_PORTE_MASK );*/
	
	/* Ramp up the system clock */
	/* Set the system dividers */
	/* NOTE: The PLL init will not configure the system clock dividers,
	* so they must be configured appropriately before calling the PLL
	* init function to ensure that clocks remain in valid ranges.
	*/  
	SIM_CLKDIV1 = ( 0
					| SIM_CLKDIV1_OUTDIV1(0)
					| SIM_CLKDIV1_OUTDIV4(1) );

#if defined(NO_PLL_INIT)
        // If PLL initialization is not desired, set FLL to 48 MHz clock in default FEI mode
        //MCG_C4 |= (MCG_C4_DRST_DRS(1) | MCG_C4_DMX32_MASK);
        mcg_clk_hz = 21000000; //FEI mode
        
        SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; // clear PLLFLLSEL to select the FLL for this clock source
        
        uart0_clk_khz = (mcg_clk_hz / 1000); // the uart0 clock frequency will equal the FLL frequency
#else
	
	/* Initialize PLL */
	/* PLL will be the source for MCG CLKOUT so the core, system, and flash clocks are derived from it */ 
	mcg_clk_hz = pll_init(	 CLK0_FREQ_HZ,  /* CLKIN0 frequency */
							 LOW_POWER,     /* Set the oscillator for low power mode */
							 CLK0_TYPE,     /* Crystal or canned oscillator clock input */
							 PLL0_PRDIV,    /* PLL predivider value */
							 PLL0_VDIV,     /* PLL multiplier */
							 MCGOUT);       /* Use the output from this PLL as the MCGOUT */
	
	/*
	 * Use the value obtained from the pll_init function to define variables
	 * for the core clock in kHz and also the peripheral clock. These
	 * variables can be used by other functions that need awareness of the
	 * system frequency.
	 */
	mcg_clk_khz = mcg_clk_hz / 1000;
	core_clk_khz = mcg_clk_khz / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV1_MASK) >> 28)+ 1);
	periph_clk_khz = core_clk_khz / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV4_MASK) >> 16)+ 1);
	
	SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK; // set PLLFLLSEL to select the PLL for this clock source
#endif
}
