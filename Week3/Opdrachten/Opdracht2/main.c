/*
 * Opdracht2.c
 *
 * Created: 22-2-2018 16:40:56
 * Author : dionb
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <avr/delay.h>
#include "LCD.h"

static char text[] = "Aantal keer gedrukt: ";

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0x00;
	
	TCNT2 = 0;
	TIMSK = |= 1 << 6;
	TCCR2 = 0b0010111;
	
	PORTC = 0x00;
	
	init();
	clr_display();
    /* Replace with your application code */
    while (1) 
    {
		PORTB = TCNT2;
		wait(10);
    }
}

void wait(int ms) {
	for(int x = 0; x < ms; x++) {
		_delay_ms(1);
	}
}

ISR ( TIMER2_OVF_vect ) {
	display_text('a');
}

ISR ( TIMER2_OVF_vect_num ) {
	display_text('a');
}


