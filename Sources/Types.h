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
#ifndef	TYPES_H_
#define	TYPES_H_
/*************************************************************************************************/
/*********************                      Includes                        **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                      Defines                         **********************/
/*************************************************************************************************/
#ifndef TRUE
#define TRUE                        (1)
#endif

#ifndef FALSE
#define FALSE                       (0)
#endif

#ifndef NULL
#define NULL          (void*)0
#endif

/* brief Manipulation of bits (U08 types) */
#define U08_SET_BIT(var, bit)               ((var) |=  (U08)((U08)1 << (U08)(bit)))
#define U08_CLEAR_BIT(var, bit)             ((var) &= ~(U08)((U08)1 << (U08)(bit)))
#define U08_CHECK_BIT(var, bit)             ((U08)(var) & ((U08)(1) << (U08)(bit)))
#define U08_TOGGLE_BIT(var, bit)            ((var) ^=  (U08)((U08)1 << (U08)(bit)))

/* brief Manipulation of bits (U16 types) */
#define U16_SET_BIT(var, bit)               ((var) |=  (U16)((U16)1 << (U16)(bit)))
#define U16_CLEAR_BIT(var, bit)             ((var) &= ~(U16)((U16)1 << (U16)(bit)))
#define U16_CHECK_BIT(var, bit)             ((U16)(var) & ((U16)(1) << (U16)(bit)))
#define U16_TOGGLE_BIT(var, bit)            ((var) ^=  (U16)((U16)1 << (U16)(bit)))

/* brief Manipulation of bits (U32 types) */
#define U32_SET_BIT(var, bit)               ((var) |=  (U32)((U32)1 << (U32)(bit)))
#define U32_CLEAR_BIT(var, bit)             ((var) &= ~(U32)((U32)1 << (U32)(bit)))
#define U32_CHECK_BIT(var, bit)             ((U32)(var) & ((U32)(1) << (U32)(bit)))
#define U32_TOGGLE_BIT(var, bit)            ((var) ^=  (U32)((U32)1 << (U32)(bit)))

/*************************************************************************************************/
/*********************                      Typedefs                        **********************/
/*************************************************************************************************/
typedef unsigned char               U08;
typedef unsigned short              U16;
typedef unsigned long               U32;
typedef signed char                 S08;
typedef signed short                S16;
typedef signed long                 S32;

/* State Machine Structure Definition */
typedef struct
{
    U08 bActualState;
    U08 bPrevState;
    U08 bNextState;
    U08 bErrorState;
}_sSM_;

/* Access unsigned long as unsigned char */
typedef union
{
    U32 u32Long;
    U16 u16Short[2];
    U08 u8Byte[4];
}_uAccessLongAsChars;

/* 8 Bit handling */
typedef union
{
    U08 u8Flags;
    struct
    {
        U08 _b0  :1;
        U08 _b1  :1;
        U08 _b2  :1;
        U08 _b3  :1;
        U08 _b4  :1;
        U08 _b5  :1;
        U08 _b6  :1;
        U08 _b7  :1;
    }_sBits;
}_u8BitFlags;

/*************************************************************************************************/
/*********************               Functions Like Macros                  **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Extern Variables                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Extern Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Function Prototypes                 **********************/
/*************************************************************************************************/

/*************************************************************************************************/
#endif
