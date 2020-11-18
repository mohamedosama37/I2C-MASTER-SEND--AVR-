/*
 * main.c
 *
 *  Created on: May 22, 2019
 *      Author: Marna
 */
#include "STD_TYPES.h"
#include "Delay.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#define SREG   *((u8*)0x5f)

#include "I2C_interface.h"
u8 arr[5]={'a','b','c','d','e'};

void main ()
{

	DIO_u8SetPinDir (22 , 1);
	DIO_u8SetPinDir (23 , 1);
	SREG  |=0x80;
	inital_master mstr = {NORMALMODE ,0x07,ENABLE_INTERRUPT};
	I2C_initinal ( &mstr);
	callbkfn ( I2C_SendStop );
	 I2C_MasterWriteAsynchsen ( arr ,5 , 0xff);
	 while (1)
	 {


	 }


}

