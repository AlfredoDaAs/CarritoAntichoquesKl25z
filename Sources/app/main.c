//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file   
	\author
	\date
	\brief

    History:
        20130207_1635   :   
	
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "derivative.h"
#include "Types.h"
#include "MotorDvr.h"
#include "PantallaDvr.h"
#include "PWM.h"
#include "HC-SR04.h"
#include "lptmr.h"
#include "GPIO.h"
//------------------------------------------------------------------------------
// Local Defines
//------------------------------------------------------------------------------
/*!
    \def	motor controls
    \brief controles para los motores
*/
#define MI_1 30

/*!
    \def	motor controls
    \brief controles para los motores
*/
#define MI_2 29

/*!
    \def	motor controls
    \brief controles para los motores
*/
#define MD_1 23

/*!
    \def	motor controls
    \brief controles para los motores
*/
#define MD_2 22

/*!
    \def	giro del sensor
    \brief	constantes para checar el giro del sensor del robot
*/
#define SENSOR_LEFT 	0

/*!
    \def	giro del sensor
    \brief	constantes para checar el giro del sensor del robot
*/
#define SENSOR_RIGHT 	1

/*!
    \def	giro del sensor
    \brief	constantes para checar el giro del sensor del robot
*/
#define SENSOR_BLOCK	2


/*!
    \def	delay giro carro
    \brief	delay para esperar un tiempo mientras el carro esta girando a una direccion
*/
#define DELAY_TURN_DIRECTION	100000

/*!
    \def	delay preparar movimiento
    \brief	delay para preparar el movimiento a hacer
*/
#define DELAY_PREPARE_MOVEMENT	100000

/*!
    \def	delay movimiento atras
    \brief	delay para darle un tiempo para ir hacia atras
*/
#define DELAY_MOVEMENT_BACK		100000

/*!
    \def	delay sensor
    \brief	delay para darle tiempo al sensor de que este en una nueva posicion y volver a sensar
*/
#define DELAY_SENSOR			100000

#define MOTOR_DRIVER 	1
#define TEMPERATURA		2
#define SERVO_MOTOR		3
#define PANTALLA		4
#define ULTRASONICO		5
#define DEBBUG_STATUS	6
#define PRODUCTIVO		7
#define TEST 			PRODUCTIVO
//------------------------------------------------------------------------------
// Enums
//------------------------------------------------------------------------------
/*!
    \enum	Maquina de estados del carro
    \brief	los estados en los que se puede encontrar el carro
*/
typedef enum //mis estados
{
	CAR_STOP,
	CAR_CHECK_FRONT_FREE,
	CAR_MOVE_FRONT,
	CAR_TURN_SENSOR_LEFT,
	CAR_TURN_SENSOR_RIGHT,
	CAR_TURN,
	CAR_MOVE_BACK
}eMoveCarStates;

//------------------------------------------------------------------------------
// Local Functions prototypes
//------------------------------------------------------------------------------
void vfnCarStop(void);
void vfnCarCheckFrontFree(void);
void vfnCarMoveFront(void);
void vfnCarTurnSensorLeft(void);
void vfnCarTurnSensorRight(void);
void vfnCarTurn(void);
void vfnCarMoveBack(void);
//------------------------------------------------------------------------------
// Variables
//------------------------------------------------------------------------------
/*!
    \var	carState variable de la maquina de estados
    \brief	variable para controlar el estado en el que se encuentra y al que se va a mover
*/
eMoveCarStates carState = CAR_CHECK_FRONT_FREE;
/*!
    \var	arreglo de apuntadores a funciones
    \brief	este arreglo se encuentran las funciones de los estados del carro
*/
void (* vfnStateMachineFuncPtrCar[])(void) = {vfnCarStop, vfnCarCheckFrontFree, vfnCarMoveFront, vfnCarTurnSensorLeft, vfnCarTurnSensorRight, vfnCarTurn, vfnCarMoveBack};

/*!
    \var	arreglo de apuntadores a funciones
    \brief	este arreglo se encuentran las funciones de los estados del carro
*/
U16 read = 0, cm = 0;
volatile U32 u32Delay = DELAY_TURN_DIRECTION, u32DelayPrepareToMove = DELAY_PREPARE_MOVEMENT, u32DelaySensor = DELAY_SENSOR, u32DelayBack = DELAY_MOVEMENT_BACK;
U08 u08turnSensor = SENSOR_LEFT, u08needToTurnCar = 0;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Main Function
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int main( void )
{
	vfnInitMotors(PORTE, MI_1, MI_2, MD_1, MD_2);
	vfnInitPWM(PORTE, 21);
	hc_sr04_init();
		
	#if	TEST == ULTRASONICO
		vfnInitGpio(PORTA);
		U08 u08pin[] = {1};
		vfnSetGPIOPortPins(PORTA, u08pin , 1, OUTPUT);
		vfnClearBit(PORTA, 1);
		hc_sr04_init();
	#endif
	
	#if	TEST == MOTOR
		vfnInitMotors(PORTE, MI_1, MI_2, MD_1, MD_2);
	#endif
		
	#if	TEST == PANTALLA
		U08 u08Name[] = {"Alfredo :P"};
		U08 x;
		//vfnInitPantalla();
		//vfnSendData(INSTRUCTION, FIRST_POSITION);
		//vfnSendData(DATA, 'A');
		for(x = 0; x < 10; x++){
			//vfnSendData(DATA, u08Name[x]);
		}
	#endif
		
	#if TEST == SERVO_MOTOR
		vfnInitPWM(PORTE, 21);
		vfnMoveLeft();
	#endif

    for(;;)
    {	
    	vfnStateMachineFuncPtrCar[carState]();
    	
		#if	TEST == ULTRASONICO
    		read = hc_sr04_read();
			cm=read/RSLTN;
			time_delay_ms(50);
			if(cm <= 10){
				vfnSetBit(PORTA, 1);
				cm = 0;
			}else{
				vfnClearBit(PORTA, 1);
			}
		#endif
		#if	TEST == MOTOR
			vfnAdelante();
			vfnDelay(u32Delay);
			vfnAtras();
			vfnDelay(u32Delay);
			vfnIzquierda();
			vfnDelay(u32Delay);
			vfnDerecha();
			vfnDelay(u32Delay);
		#endif
    }
    
    return 0;
}
//------------------------------------------------------------------------------
/*!
    \fn
    \param
    \return
    \brief  
*/
void vfnCarStop(void){
	vfnParar();
	carState = CAR_TURN_SENSOR_LEFT;
}

void vfnCarCheckFrontFree(void){
	read = hc_sr04_read();
	cm=read/RSLTN;
	time_delay_ms(50);
	if(cm < 8){
		if(u08turnSensor == SENSOR_LEFT){
			u08turnSensor = SENSOR_RIGHT;
		}else if(u08turnSensor == SENSOR_RIGHT){
			u08turnSensor = SENSOR_BLOCK;
		}else{
			u08turnSensor = SENSOR_LEFT;
			carState = CAR_MOVE_BACK;
		}
		carState = CAR_STOP;
	}else{
		if(u08needToTurnCar){
			u08needToTurnCar = 0;
			u32Delay = DELAY_TURN_DIRECTION;
			carState = CAR_TURN;
		}else{
			carState = CAR_MOVE_FRONT;
		}
	}
}

void vfnCarMoveFront(void){
	vfnMoveCenter();
	u32DelayPrepareToMove -= 1;
	if(!u32DelayPrepareToMove){
		u32DelayPrepareToMove = DELAY_PREPARE_MOVEMENT;
		vfnAdelante();
		carState = CAR_CHECK_FRONT_FREE;
	}
}

void vfnCarTurnSensorLeft(void){
	u08needToTurnCar = 1;
	if(u08turnSensor == SENSOR_LEFT){
		vfnMoveLeft();
		u32DelaySensor -= 1;
		if(!u32DelaySensor){
			u32DelaySensor = DELAY_SENSOR;
			carState = CAR_CHECK_FRONT_FREE;
		}
	}else{
		carState = CAR_TURN_SENSOR_RIGHT;
	}
}

void vfnCarTurnSensorRight(void){
	u08needToTurnCar = 1;
	if(u08turnSensor == SENSOR_RIGHT){
		vfnMoveRight();
		u32DelaySensor -= 1;
		if(!u32DelaySensor){
			u32DelaySensor = DELAY_SENSOR;
			carState = CAR_CHECK_FRONT_FREE;
		}
	}else{
		carState = CAR_MOVE_BACK;
	}
}

void vfnCarTurn(void){
	if(u08turnSensor == SENSOR_LEFT){
		vfnIzquierda();
	}else if(u08turnSensor == SENSOR_RIGHT){
		vfnDerecha();
	}
	u32Delay -= 1;
	if(!u32Delay){
		u32Delay = DELAY_TURN_DIRECTION;
		carState = CAR_MOVE_FRONT;
	}
}

void vfnCarMoveBack(void){
	vfnAtras();
	u32DelayBack -= 1;
	if(!u32DelayBack){
		u32DelayBack = DELAY_MOVEMENT_BACK;
		carState = CAR_CHECK_FRONT_FREE;
	}

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
