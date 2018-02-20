/*
 * Opdracht3B.c
 *
 * Created: 12-2-2018 10:12:05
 * Author : Brandon WTG
 */ 
#define F_CPU 8000000


#include <avr/io.h>
#include <util/delay.h>

void display(int);
void wait(int);


int main(void)
{
	DDRD = 0xFF;
	
	/* Replace with your application code */
    while (1) 
    {
		PORTD = 0b11111111;
		for (int num = 0;num < 16;num++)
		{
			display(num);
			wait(100);
			
		}
    }
}



/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}


void display(int num){
	if(num >= 15){
		PORTD = 0b01110001;
	}
	else if(num == 0){
		PORTD = 0b00111111;
	}
	else if(num == 1){
		PORTD = 0b00000110;
	}
	else if(num == 2){
		PORTD = 0b01011011;
	}
	else if(num == 3){
		PORTD = 0b01001111;
	}
	else if(num == 4){
		PORTD = 0b01100110;
	}
	else if(num == 5){
		PORTD = 0b01101101;
	}
	else if(num == 6){
		PORTD = 0b01111101;
	}
	else if(num == 7){
		PORTD = 0b00000111;
	}
	else if(num == 8){
		PORTD = 0b01111111;
	}
	else if(num == 9){
		PORTD = 0b01101111;
	}
	else if(num == 10){
		PORTD = 0b01110111;
	}
	else if(num == 11){
		PORTD = 0b01111100;
	}
	else if(num == 12){
		PORTD = 0b00111001;
	}
	else if(num == 13){
		PORTD = 0b01011110;
	}
	else if(num == 14){
		PORTD = 0b01111001; 
	}
}

