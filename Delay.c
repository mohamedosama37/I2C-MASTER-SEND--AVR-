/************************************************************************************/
/*	Author	:	Khaled Mohamed Nasser												*/
/*	Date	:	14 Feb 2019															*/
/*	Version	:	V01																	*/
/************************************************************************************/
/*	Description																		*/
/*	-----------																		*/
/*	This file has the implementation of both private and							*/
/*	public functions corresponding to Delay module									*/
/************************************************************************************/
#include "STD_TYPES.h"
#include "Delay.h"

void delay_ms(u32 time_ms)
{
	u32 counter;
	u32 n;
	n=((8000*time_ms)-168)/64;//(time_ms*191)-4;

	for(counter=0;counter<n;counter++)
	{
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		//asm("NOP");
	}
}

void delay_us(u32 time_us)
{
	u32 counter;
	u32 n;
	n=((8*time_us)-123)/64;

	for(counter=0;counter<n;counter++)
	{
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		//asm("NOP");
	}
}
