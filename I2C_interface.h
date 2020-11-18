
#include "I2C_private.h"
#ifndef I2C_interface_h
#define I2C_interface_h

#define NORMALMODE  0
#define FASTMODE    1
#define FASTMODEPLUS 2
#define HIGH_SPEED   3

#define ENABLE_INTERRUPT 1


void  I2C_initinal ( inital_master *I2Cx);





u8 I2C_MasterWriteAsynchsen ( u8 * Copy_data ,u8 Copy_length , u8 Copy_Address);

u8 	I2C_MasterReadAsynchsen ( u8 * Copy_data ,u8 Copy_length , u8 Copy_Address);

void I2C_SendStop(void);


void callbkfn (  void  (*Copy_pvidCallBack)(void));
#endif
