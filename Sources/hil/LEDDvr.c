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
#include "LEDDvr.h"
#include "Types.h"
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
void vfnInitLeds(void){
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	
	PORTB_PCR18 |= PORT_PCR_MUX(1);
	PORTB_PCR19 |= PORT_PCR_MUX(1);
	
	GPIOB_PSOR |= GPIO_PSOR_PTSO(LED1);
	GPIOB_PSOR |= GPIO_PSOR_PTSO(LED2);
	
	GPIOB_PDDR |= GPIO_PDDR_PDD_MASK;
	
	U32_SET_BIT(MI_PUERTO, LED1);
	U32_SET_BIT(MI_PUERTO, LED2);
}

/*!
    \fn
    \param
    \return
    \brief  
*/
void vfnLedToogle(void){
	U32_TOGGLE_BIT(MI_PUERTO, LED1);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
