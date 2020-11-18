/***************************************************************************************************************************************************/
/*AUTHOR   : MOHAMED OSAMA                                                                                                                          */
/*DATE     : 4 FEB 2019                                                                                                                             */
/*VERSION  : V01                                                                                                                                    */
/***************************************************************************************************************************************************/
/* DESCRIPTION                                                                                                                                       */
/*------------                                                                                                                                       */
/* this file defines the APIs corresponding to DIO                                                                                                    */
/*****************************************************************************************************************************************************/

/* comment :Header file guard                                                                                                                         */
#ifndef DIO_interface_h
#define DIO_interface_h
/* comment : DIO pin index assigment                                                                                                                */

#define  DIO_u8_PIN_0                                                                   0
#define  DIO_u8_PIN_1                                                                   1
#define  DIO_u8_PIN_2                                                                   2
#define  DIO_u8_PIN_3                                                                   3
#define  DIO_u8_PIN_4                                                                   4
#define  DIO_u8_PIN_5                                                                   5
#define  DIO_u8_PIN_6                                                                   6
#define  DIO_u8_PIN_7                                                                   7
#define  DIO_u8_PIN_8                                                                   8
#define  DIO_u8_PIN_9                                                                   9
#define  DIO_u8_PIN_10                                                                  10
#define  DIO_u8_PIN_11                                                                  11
#define  DIO_u8_PIN_12                                                                  12
#define  DIO_u8_PIN_13                                                                  13
#define  DIO_u8_PIN_14                                                                  14
#define  DIO_u8_PIN_15                                                                  15
#define  DIO_u8_PIN_16                                                                  16 
#define  DIO_u8_PIN_17                                                                  17
#define  DIO_u8_PIN_18                                                                  18
#define  DIO_u8_PIN_19                                                                  19
#define  DIO_u8_PIN_20                                                                  20
#define  DIO_u8_PIN_21                                                                  21
#define  DIO_u8_PIN_22                                                                  22
#define  DIO_u8_PIN_23                                                                  23
#define  DIO_u8_PIN_24                                                                  24
#define  DIO_u8_PIN_25                                                                  25
#define  DIO_u8_PIN_26                                                                  26
#define  DIO_u8_PIN_27                                                                  27
#define  DIO_u8_PIN_28                                                                  28
#define  DIO_u8_PIN_29                                                                  29
#define  DIO_u8_PIN_30                                                                  30
#define  DIO_u8_PIN_31                                                                  31

/* comment : DIO pin value                                                                                                                */

#define INPUT_LOW                                                                       0
#define INPUT_HIGH                                                                      1
/* comment : DIO pin direction                                                                                                             */
#define DIO_u8_input                                                                    0
#define DIO_u8_output                                                                   1
/* comment : maxmium pins number                                                                                                           */
#define  DIO_u8_PINSNUMBERS                                                             32
/* comment : maxmium ports number                                                                                                           */
#define  DIO_u8_PORTSNUMBERS                                                            4
/* comment : maximum pins in the port                                                                                                       */
#define  DIO_u8_PINSPERPORT                                                             8


#define  DIO_u8_PORT0                                                             0
#define  DIO_u8_PORT1                                                             1
#define  DIO_u8_PORT2                                                             2
#define  DIO_u8_PORT3                                                             3



/* description : this function shall initalize the                                                                                                    */
/* direction and intial value for 	DIO                                                                                                               */
/* direction and intial value for 	Pins                                                                                                              */
void DIO_voidInitialize (void);
/* description : this function shall set certain value                                                                                           */
/*    to certain DIO channel                                                                                                                     */
u8 DIO_u8SetPinValue (u8 Copy_u8PinId , u8 Copy_u8PinValue);
/* description : this function shall set certain Direction                                                                                       */
/*    to certain DIO channel                                                                                                                     */
u8 DIO_u8SetPinDir (u8 Copy_u8PinId , u8 Copy_u8PinDirection);

/* description : this function shall set certain Value                                                                                           */
/*    to certain DIO PORT                                                                                                                        */
u8 DIO_u8SetPortValue (u8 Copy_u8PortId , u8 Copy_u8PortValue);
/* description : this  function shall set  certain value                                                                                         */
/*    from certain DIO   port                                                                                                                  */
u8 DIO_u8SetPortDir (u8 Copy_u8PortId , u8 Copy_u8PortDirection);

u8 DIO_u8GetPinValue ( u8 Copy_u8PinId , u8 * Copy_u8Variable);

u8 DIO_u8GetPortValue ( u8 Copy_u8PortId , u8 * Copy_u8Variable);

#endif