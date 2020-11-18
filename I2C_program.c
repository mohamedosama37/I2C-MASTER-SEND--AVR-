#include "STD_TYPES.h"
#include "I2C_private.h"
#include "I2C_interface.h"
#include "I2C_config.h"
#define NULL 0




static master_states state;
static u8 Transmitt_BusyFlag=0;
static u8 Transmitter_writemode =0;
static u8 Transmitter_Readmode =0;
static u8 i=0;
static u8 ADD_Temp;
static void (*ptr0CallBack)(void)=NULL;


static struct t
{
	
	u8* Buffer;
	u8 size ;
	u8  Salve_Add ;
	
	
	
}master_buffer;






void I2C_initinal ( inital_master	*	I2Cx)
{
	
	
	switch ( I2Cx -> Prescale)
	{

    case NORMALMODE : TWBR = 0x20;
	                  TWSR &=0xfc;break;
	case FASTMODE :   TWBR = 0x02;		
                      TWSR &=0xfc;break;
    }
	
	if (I2Cx -> Interrupt == ENABLE_INTERRUPT)
	{
		  TWCR |=    0x01;
	}

   TWAR   = 	 I2Cx -> Address;
  /* enable ack*/
   TWCR|=0x40;
   TWCR  |=    0x04;
   
	                   

	}	
	
	
	
u8 I2C_MasterWriteAsynchsen ( u8 * Copy_data ,u8 Copy_length , u8 Copy_Address)

	{
		u8 Local_status=0;
		if (Transmitt_BusyFlag ==0)
		{
			if ( Copy_data !=NULL && Copy_length !=0)
			{
			Transmitt_BusyFlag = 1;
			Transmitter_writemode =  1;
		    master_buffer.Buffer= Copy_data ;
		    master_buffer.size  = Copy_length;
			master_buffer.Salve_Add = Copy_Address;
			state = start_sent;
			
           /* send start clear flag enable TWI */
			  TWCR |= 0xA4;
	                   
			}else
			{
				Local_status=1;
			}
			
			
			
			
		}else
		{
		     Local_status=1;
		}
		return (Local_status);
		
		
		
		
		
	}
	
	
u8 	I2C_MasterReadAsynchsen ( u8 * Copy_data ,u8 Copy_length , u8 Copy_Address)
{
	
	
	u8 Local_status=0;
	
		if (Transmitt_BusyFlag ==0)
		{
			if ( Copy_data !=NULL && Copy_length !=0)
			{
			Transmitt_BusyFlag =1;
			Transmitter_Readmode =  1;
		    master_buffer.Buffer= Copy_data ;
		    master_buffer.size  = Copy_length;
			master_buffer.Salve_Add = Copy_Address;
			state = start_sent;
			
	           /* send start clear flag enable TWI */
				  TWCR |= 0xA4;
	                   
			}else
			{
				Local_status=1;
			}
			
			
			
			
		}else
		{
		Local_status=1;
		}
		return (Local_status);
		
		
	
	
	
	
	
	
}
	
void I2C_SendStop(void)
{


			 state = stop_sent;
			 /* send stop clear flag enable twi */
             TWCR |=  0x94;



}	

void __vector_19 (void)__attribute__((signal));
void __vector_19 (void)
{

     if ( Transmitter_writemode == 1)
	   
	   {
	
			switch (state)
			{

					case start_sent:
		  
					state  = add_ack_receive;
					ADD_Temp =  master_buffer.Salve_Add;
					ADD_Temp = ADD_Temp << 1;
					TWDR = ADD_Temp;

					/* clear interrupt flag  enable operation */
					 TWCR |=0x84;
					break;
		  
		  
					case add_ack_receive:
					state = data_ack_recev;
					TWDR = master_buffer.Buffer[i++];
					/* clear interrupt flag  enable operation */
					TWCR |=0x84;
					break;
		  
		  
					case data_ack_recev:
					if (master_buffer.size == i)
							{
								i=0; 
								ptr0CallBack();
			 
							}else
			  
							{ 
		
								TWDR =master_buffer.Buffer[i++];
								/* clear interrupt flag  enable operation */
								TWCR |=0x84;
							}
		  
					break ;
		  
						case stop_sent:
						Transmitt_BusyFlag =0;
						Transmitter_writemode =  0;
						master_buffer.Buffer=NULL;

					break;
		  
			 
		 
			}
	
	}else if (Transmitter_Readmode ==1)
	{
		
		switch (state)
	{
		case start_sent:
		  
		  state  = add_ack_receive;
		  ADD_Temp =  master_buffer.Salve_Add;
		  ADD_Temp = (ADD_Temp << 1) | 0x01;
          TWDR = ADD_Temp;
          /* clear interrupt flag  enable operation */
          TWCR |=0x84;
		  break;
		  
		  case add_ack_receive:
		   state  = data_recev;
		   break;

		  
		 case data_recev :
         if (	master_buffer.size == i)
		   {
            
			i=0;
			ptr0CallBack();
		    }	else
			 
			 {
	      master_buffer.Buffer[i++] = TWDR  ;

          /* clear interrupt flag  enable operation  */
          TWCR |=0x84;
		    }
		
		break;
		
		case stop_sent :
		
		  	Transmitt_BusyFlag =0;
		  	Transmitter_Readmode = 0;
			master_buffer.Buffer=NULL;
			break;
	 }
	 }else
	 {
	 }
		
}	
	
		  
		  
		    		  



void callbkfn (  void  (*Copy_pvidCallBack)(void))
{
	
	
	ptr0CallBack = Copy_pvidCallBack;
	
	
}











	
	
	
	
