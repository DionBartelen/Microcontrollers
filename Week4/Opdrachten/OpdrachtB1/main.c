/*
 * OpdrachtB1.c
 *
 * Created: 1-3-2018 16:07:16
 * Author : dionb
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
		DDRF = 0x00;
		DDRA = 0xFF;
		DDRB = 0xFF;
		
		ADMUX = 0b01100011;			
		ADCSRA = 0b11000110; // free running was aan: 0b11100110 nu 0b11000110.
	
    /* Replace with your application code */
    while (1) 
    {
		ADCSRA = 0b11000110;
		wait(50);
		PORTA = ADCH;
		wait(50);
    }
}

void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
	}
}