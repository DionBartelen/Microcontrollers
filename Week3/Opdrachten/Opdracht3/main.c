/*
 * Opdracht3.c
 *
 * Created: 28-2-2018 13:54:27
 * Author : dionb
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"

int overflowCount = 0;

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
		
	TCNT2 = 0;
	OCR2 = 125;
	TIMSK |= (1 << 7);
	SREG |= (1 << 7);
	TCCR2 = 0b00001011; 
	sei();

    while (1) 
    {
		
    }
}


ISR( TIMER2_COMP_vect )
{
	overflowCount++;
	overflowCount = overflowCount % 40;
	if(overflowCount == 0) {
		PORTD = 0b10000000;
		} else if(overflowCount == 15) {
		PORTD = 0b00000000;
	}
}