


#ifndef BIT_CALC_H
#define BIT_CALC_H


#define set_bit(var,bit)   (var|=(1<<bit))
#define clear_bit(var,bit) (var&=(~(1<<bit)))
#define  get_bit(var,bit)  (var&(1<<(bit)))>>(bit)
#define ASSIGN_BIT(var,bit_number,val) do{	if(val == 0){ \
												(var) &= ~( 1<<(bit_number) );\
											}else{ \
												(var) |= 1<<(bit_number);\
											}}while(0)


#endif