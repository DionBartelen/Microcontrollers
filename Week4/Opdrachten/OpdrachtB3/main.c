/*
 * OpdrachtB3.c
 *
 * Created: 1-3-2018 16:36:33
 * Author : dionb
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "LCD.h"


int main(void)
{	
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0x00;
	DDRF = 0x00;
		
	ADMUX = 0b11100000;
	ADCSRA = 0b11100110;
	
	init();
	wait(100);
	
    /* Replace with your application code */
    while (1) 
    {
		clr_display();
		char string[16];
		int temp = ADCH;
		sprintf(string, "Temp: 0x%.2X", temp);
		display_text(string);
		PORTA = ADCH;
		wait(1000);
    }
}

void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
	}
}

