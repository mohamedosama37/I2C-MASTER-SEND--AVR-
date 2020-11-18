#ifndef I2C_private_h
#define I2C_private_h



#define TWDR *((u8*)0x23)
#define TWAR *((u8*)0x22)
#define TWSR *((u8*)0x21)
#define TWBR *((u8*)0x20)
#define TWCR *((u8*)0x56)


typedef struct 
{
	u8 Prescale;
	u8 Address;
	u8 Interrupt;
	
}inital_master;


typedef struct 
{
	
	u8 Address;
	u8 Interrupt;
	
}inital_slave ;


typedef enum
{
	add_receive,
	ack_receive,
	data_receive
	
	
}slave_states;


typedef enum
{
	
 start_sent,
 add_ack_receive,
 data_ack_recev,
 stop_sent,
 data_sent,
 data_recev
 
}master_states;




























#endif
