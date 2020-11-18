/*******************************************************************************************************************************/
/*AUTHOR   : MOHAMED OSAMA                                                                                                    */
/*DATE     : 4 FEB 2019                                                                                                       */
/*VERSION  : V01                                                                                                              */
/******************************************************************************************************************************/
/* DESCRIPTION                                                                                                                */
/*------------                                                                                                                */


/*********************************************************************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H
/*comment : unsigned 8 bits type                                                                                              */
typedef unsigned char                   u8 ;     
/*comment : unsigned 16 bits type                                                                                              */
typedef unsigned short int              u16 ;                                                                                                                    
/*comment : unsigned 32 bits type                                                                                               */
typedef unsigned long int               u32 ;   
/*comment : signed   8 bits  type                                                                                               */
typedef signed  char                    s8 ;   
/*comment : signed  16  bits  type                                                                                               */
typedef signed short int                s16 ;
/*commment: signed 32   bits  type                                                                                               */
typedef signed long  int                s32 ; 
/*Decimal type float value with size 32 bits                                                                                     */
typedef float                           f32 ;
/*Decimal type float value with size  64 bits                                                                                */
typedef double                          f64;      



typedef union
{
	struct
	{
		u8 BIT0:1;
		u8 BIT1:1;
		u8 BIT2:1;
		u8 BIT3:1;
		u8 BIT4:1;
		u8 BIT5:1;
		u8 BIT6:1;
		u8 BIT7:1;


	}BitAccess;

	u8 ByteAccess;
}Register;


typedef union
{
	struct
	{
		u32 BIT0:1;
		u32 BIT1:1;
		u32 BIT2:1;
		u32 BIT3:1;
		u32 BIT4:1;
		u32 BIT5:1;
		u32 BIT6:1;
		u32 BIT7:1;
		u32 BIT8:1;
		u32 BIT9:1;
		u32 BIT10:1;
		u32 BIT11:1;
		u32 BIT12:1;
		u32 BIT13:1;
		u32 BIT14:1;
		u32 BIT15:1;
		u32 BIT16:1;
		u32 BIT17:1;
		u32 BIT18:1;
		u32 BIT19:1;
		u32 BIT20:1;
		u32 BIT21:1;
		u32 BIT22:1;
		u32 BIT23:1;
		u32 BIT24:1;
		u32 BIT25:1;
		u32 BIT26:1;
		u32 BIT27:1;
		u32 BIT28:1;
		u32 BIT29:1;
		u32 BIT30:1;
		u32 BIT31:1;


	}BitAccess;

	u32 ByteAccess;
}Register_32bit;


#define DDRA_REG          (*( (Register *)0x3A))
#define DIO_u8_DDRA              DDRA_REG.ByteAccess

#define PORTA_REG         (*( (Register * )0x3B))
#define DIO_u8_PORTA             PORTA_REG.ByteAccess

#define PINA_REG           (*( (Register * )0x39))
#define DIO_u8_PINA               PINA_REG.ByteAccess
   
#define DDRB_REG          (*( (Register *)0x37))
#define DIO_u8_DDRB           DDRB_REG.ByteAccess

#define PORTB_REG         (*( (Register * )0x38))
#define DIO_u8_PORTB            PORTB_REG.ByteAccess

#define PINB_REG           (*( (Register * )0x36))
#define DIO_u8_PINB             PINB_REG.ByteAccess   

#define DDRC_REG          (*( (Register *)0x34))
#define DIO_u8_DDRC             DDRC_REG.ByteAccess

#define PORTC_REG         (*( (Register * )0x35))
#define DIO_u8_PORTC            PORTC_REG.ByteAccess

#define PINC_REG           (*( (Register * )0x33))
#define DIO_u8_PINC               PINC_REG.ByteAccess 

#define DDRD_REG           (*( (Register *)0x31))
#define DIO_u8_DDRD               DDRD_REG.ByteAccess

#define PORTD_REG          (*( (Register * )0x32))
#define DIO_u8_PORTD            PORTD_REG.ByteAccess

#define PIND_REG             (*( (Register * )0x30))
#define  DIO_u8_PIND              PIND_REG.ByteAccess 


#endif                      