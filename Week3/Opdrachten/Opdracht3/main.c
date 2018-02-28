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
		
	TCNT2 = 5;
	TIMSK |= (1 << 6);
	SREG |= (1 << 7);
	TCCR2 = 0b00001011;  // met een prescaler van 32 en een startwaarde van 5 is er precies een overflow bij 1 milliseconden
	sei();
		
	PORTC = 0x00;

    while (1) 
    {
		
    }
}


ISR ( TIMER2_OVF_vect ) {
	TCNT2 = 5;
	overflowCount = (overflowCount + 1) % 40;
	if(overflowCount == 0) {
		PORTD = 0b10000000;
	} else if(overflowCount == 15) {
		PORTD = 0b00000000;
	}
}
