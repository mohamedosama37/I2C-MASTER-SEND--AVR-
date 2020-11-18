/***************************************************************************************************************************************************/
/*AUTHOR   : MOHAMED OSAMA                                                                                                                          */
/*DATE     : 4 FEB 2019                                                                                                                             */
/*VERSION  : V01                                                                                                                                    */
/***************************************************************************************************************************************************/
/* DESCRIPTION                                                                                                                                       */
/*------------                                                                                                                                       */
/* this filedefines the implementation of both private and public functions                                                                          */
/*****************************************************************************************************************************************************/
#include "STD_TYPES.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#define CONC_8BIT(b0,b1,b2,b3,b4,b5,b6,b7)   CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)
#define CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)    0b##b7##b6##b5##b4##b3##b2##b1##b0

/* description : this function shall initalize the                                                                                                    */
/* direction and intial value for 	DIO                                                                                                               */
/* direction and intial value for 	Pins                                                                                                              */
void DIO_voidInitialize (void)

{
	DIO_u8_DDRA = CONC_8BIT( DIO_u8_PIN_0_DIR,
			                           DIO_u8_PIN_1_DIR,
										DIO_u8_PIN_2_DIR,
										DIO_u8_PIN_3_DIR,
										DIO_u8_PIN_4_DIR,
										DIO_u8_PIN_5_DIR,
										DIO_u8_PIN_6_DIR,
										DIO_u8_PIN_7_DIR);
										
	DIO_u8_DDRB = CONC_8BIT(DIO_u8_PIN_8_DIR,
	                                    DIO_u8_PIN_9_DIR,
										DIO_u8_PIN_10_DIR,
										DIO_u8_PIN_11_DIR,
										DIO_u8_PIN_12_DIR,
										DIO_u8_PIN_13_DIR,
										DIO_u8_PIN_14_DIR,
										DIO_u8_PIN_15_DIR);

    DIO_u8_DDRC = CONC_8BIT(DIO_u8_PIN_16_DIR,
	                                    DIO_u8_PIN_17_DIR,
										DIO_u8_PIN_18_DIR,
										DIO_u8_PIN_19_DIR,
										DIO_u8_PIN_20_DIR,
										DIO_u8_PIN_21_DIR,
										DIO_u8_PIN_22_DIR,
										DIO_u8_PIN_23_DIR);
										
     DIO_u8_DDRD = CONC_8BIT(DIO_u8_PIN_24_DIR,
	                                    DIO_u8_PIN_25_DIR,
										DIO_u8_PIN_26_DIR,
										DIO_u8_PIN_27_DIR,
										DIO_u8_PIN_28_DIR,
										DIO_u8_PIN_29_DIR,
										DIO_u8_PIN_30_DIR,
										DIO_u8_PIN_31_DIR);
}	
/* description : this function shall set certain value                                                                                                */
/*    to certain DIO channel                                                                                                                          */
u8 DIO_u8SetPinDir (u8 Copy_u8PinId , u8 Copy_u8PinDirection)
{
	u8 Local_u8ErrorState =0;
	u8 Local_u8PinNo;
	u8 Local_u8PortNo;
	if ( Copy_u8PinId >= DIO_u8_PINSNUMBERS )
	{
	   Local_u8ErrorState=1;
	}
    else if ( (	Copy_u8PinDirection != DIO_u8_input )&& (Copy_u8PinDirection != DIO_u8_output))
	{
		 Local_u8ErrorState=1;
	}else
    {
		Local_u8ErrorState =0;
    }
   
   Local_u8PinNo = Copy_u8PinId %  DIO_u8_PINSPERPORT ;
   Local_u8PortNo= Copy_u8PinId /  DIO_u8_PINSPERPORT ;
   
   
   switch ( Local_u8PortNo)
   {
	   case GROUP_A :
	                     if ( Copy_u8PinDirection ==  DIO_u8_input)
						 {
							 clear_bit( DIO_u8_DDRA,Local_u8PinNo);
						 } else	 
						 
						 {
                             set_bit( DIO_u8_DDRA,Local_u8PinNo);
	                     } 

                          break;
       case GROUP_B :		
                         if ( Copy_u8PinDirection ==  DIO_u8_input)
						 {
							 clear_bit( DIO_u8_DDRB,Local_u8PinNo);
						 } else	 
						 
						 {
                             set_bit( DIO_u8_DDRB,Local_u8PinNo);
	                     } 

                          break;	
       case GROUP_C :	
                         if ( Copy_u8PinDirection ==  DIO_u8_input)
						 {
							 clear_bit( DIO_u8_DDRC,Local_u8PinNo);
						 } else	 
						 
						 {
                             set_bit( DIO_u8_DDRC,Local_u8PinNo);
	                     } 

                          break;	   
						 
	    case GROUP_D :	
                         if ( Copy_u8PinDirection ==  DIO_u8_input)
						 {
							 clear_bit( DIO_u8_DDRD,Local_u8PinNo);
						 } else	 
						 
						 {
                             set_bit( DIO_u8_DDRD,Local_u8PinNo);
	                     } 

                          break;	

    
     

	
}
return Local_u8ErrorState;		
}



u8 DIO_u8SetPinValue (u8 Copy_u8PinId , u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState=0;
	u8 Local_u8PinNo;
	u8 Local_u8PortNo;
	
	if ( Copy_u8PinId >= DIO_u8_PINSNUMBERS)
	{
		Local_u8ErrorState=1;
	}else if ((Copy_u8PinValue != DIO_u8_input ) && (Copy_u8PinValue != DIO_u8_output ))
		
	{
	    Local_u8ErrorState=1;
	}else
    {
        Local_u8ErrorState=0;
	}

   Local_u8PinNo = Copy_u8PinId %  DIO_u8_PINSPERPORT ;
   Local_u8PortNo= Copy_u8PinId /  DIO_u8_PINSPERPORT ;
   
   switch (Local_u8PortNo)
   {
	   
	   
	  case GROUP_A :
	                 if (  Copy_u8PinValue == INPUT_LOW )
					 {
						 clear_bit(DIO_u8_PORTA ,Local_u8PinNo);
					 }else
						 
                     {		
                        set_bit(DIO_u8_PORTA ,Local_u8PinNo);
                     }						
			           
					 break;
       					 
      case GROUP_B :
	                if (  Copy_u8PinValue == INPUT_LOW )
					 {
						 clear_bit(DIO_u8_PORTB ,Local_u8PinNo);
					 }else
						 
                     {		
                        set_bit(DIO_u8_PORTB ,Local_u8PinNo);
                     }						
			           
					 break;
 	
		case GROUP_C :
	                if (  Copy_u8PinValue == INPUT_LOW )
					 {
						 clear_bit(DIO_u8_PORTC,Local_u8PinNo);
					 }else
						 
                     {		
                        set_bit(DIO_u8_PORTC,Local_u8PinNo);
                     }						
			           
					 break;
		
	
	    case GROUP_D :
	                if (  Copy_u8PinValue == INPUT_LOW )
					 {
						 clear_bit(DIO_u8_PORTD,Local_u8PinNo);
					 }else
						 
                     {		
                        set_bit(DIO_u8_PORTD,Local_u8PinNo);
                     }						
			           
					 break;
   }
   return Local_u8ErrorState;
}

	
u8 DIO_u8SetPortDir(u8 Copy_u8PortId , u8 Copy_u8PortDirection)
{


   u8 Local_u8ErrorState= 0;
	
	if ( Copy_u8PortId >= DIO_u8_PORTSNUMBERS)
	{
		 Local_u8ErrorState = 1;
    }else if (( Copy_u8PortDirection != DIO_u8_input) && ( Copy_u8PortDirection != DIO_u8_output))
	{
        Local_u8ErrorState = 1 ;
    }else
    
    {
		Local_u8ErrorState = 0 ;
    }
    
    switch ( Copy_u8PortId)
	{
    
	  case GROUP_A : 
	                if ( Copy_u8PortDirection == DIO_u8_input )
					{
						
	                	DIO_u8_DDRA =   0x00;
					}else
					{
						DIO_u8_DDRA =  0xff;
                    }	
                   break;
				   
	 case GROUP_B : 
	                if ( Copy_u8PortDirection == DIO_u8_input )
					{
						
	                	DIO_u8_DDRB  = 0x00;
					}else
					{
						DIO_u8_DDRB = 0xff;
                    }	
                   break;
      case GROUP_C : 
	                if ( Copy_u8PortDirection == DIO_u8_input )
					{
						
	                	DIO_u8_DDRC  =0x00;
					}else
					{
						DIO_u8_DDRC =0xff;
                    }	
                   break;
		
        case GROUP_D : 
	                if ( Copy_u8PortDirection == DIO_u8_input )
					{
						
	                	DIO_u8_DDRD  =0x00;
					}else
					{
						DIO_u8_DDRD =0xff;
                    }	
                   break;		
					
    }
 return Local_u8ErrorState;
} 
   	


u8 DIO_u8SetPortValue (u8 Copy_u8PortId , u8 Copy_u8PortValue)
{
	
	
	
	
	
	 u8 Local_u8ErrorState = 0;
	
	if ( Copy_u8PortId >= DIO_u8_PORTSNUMBERS)
	{
		 Local_u8ErrorState = 1;
    }else
    
    {
		Local_u8ErrorState = 0 ;
    }
    
    switch ( Copy_u8PortId)
	{
    
	  case GROUP_A : 
	                	
	                	DIO_u8_PORTA =   Copy_u8PortValue;
					
                   break;
				   
	 case GROUP_B : 
	                   DIO_u8_PORTB =   Copy_u8PortValue;
	                	
                   break;
      case GROUP_C : 
	  
	                  DIO_u8_PORTC =   Copy_u8PortValue;
	                	
                   break;
		
        case GROUP_D : 
	                    DIO_u8_PORTD =   Copy_u8PortValue;
                   break;		
					
    }
 return Local_u8ErrorState;
	
	
}	
	

	
u8 DIO_u8GetPinValue ( u8 Copy_u8PinId , u8 * Copy_u8Variable)
{
  u8 Local_u8ErrorState = 0;
  u8 Local_u8PortNo;
  u8 Local_u8PinNo;
  
  if (  Copy_u8PinId >= DIO_u8_PINSNUMBERS )
  {
      Local_u8ErrorState = 1;
  }else 
  {
	   Local_u8ErrorState=0;
  }	  
  
    Local_u8PinNo = Copy_u8PinId %  DIO_u8_PINSPERPORT ;
   Local_u8PortNo= Copy_u8PinId /  DIO_u8_PINSPERPORT ;
   
  switch ( Local_u8PortNo)
  {
	  
	  case GROUP_A :
                    	   
	 * Copy_u8Variable = get_bit(DIO_u8_PINA, Local_u8PinNo);
	  break;
	  
	  case GROUP_B :
                    	   
	 * Copy_u8Variable = get_bit(DIO_u8_PINB, Local_u8PinNo);
	  break;

	  case GROUP_C :
                    	   
	 * Copy_u8Variable = get_bit(DIO_u8_PINC, Local_u8PinNo);
	  break;
	  
	  case GROUP_D :
                    	   
	 * Copy_u8Variable = get_bit(DIO_u8_PIND, Local_u8PinNo);
	  break;
  }
	return Local_u8ErrorState ;
}
	
	
	
	
	
	
u8 DIO_u8GetPortValue ( u8 Copy_u8PortId , u8 * Copy_u8Variable)
{
  u8 Local_u8ErrorState =0;
 
  if (  Copy_u8PortId >= DIO_u8_PORTSNUMBERS  )
  {
      Local_u8ErrorState=1;
  }else 
  {
	   Local_u8ErrorState=0;
  }	  
  
   
   
  switch ( Copy_u8PortId )
  {
	  
	  case GROUP_A :
                    	   
	 * Copy_u8Variable = DIO_u8_PINA;
	  break;
	  
	  case GROUP_B :
                    	   
	 * Copy_u8Variable = DIO_u8_PINB;
	  break;

	  case GROUP_C :
                    	   
	 * Copy_u8Variable = DIO_u8_PINC;
	  break;
	  
	  case GROUP_D :
                    	   
	 * Copy_u8Variable = DIO_u8_PIND;
	  break;
  }
	return Local_u8ErrorState;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	