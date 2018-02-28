/*
 * Opdracht2.c
 *
 * Created: 22-2-2018 16:40:56
 * Author : dionb
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"

static char text[] = "Aantal keer gedrukt: ";
int aantalKeer = 0;

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0x00;
	
	TCNT2 = -1;
	TIMSK |= (1 << 6);
	SREG |= (1 << 7);
	TCCR2 = 0b0000111;  //TCCR2 = 0b0010111;
	sei();
	
	PORTC = 0x00;
	
		init();
		clr_display();
		int length = strlen(text) + 1;
		while (1)
		{
			for(int x = 0; x< length; x++) {
				PORTB = TCNT2;
				set_display(1);
				wait(250);
			}
		}
		
		return 0;
}

void wait(int ms) {
	for(int x = 0; x < ms; x++) {
		_delay_ms(1);
	}
}

ISR ( TIMER2_OVF_vect ) {
	aantalKeer++;
	displayUpdate();
	TCNT2 = -1;
}

void displayUpdate() {
		clr_display();
		display_text(text);
		lcd_writeChar(aantalKeer+'0');
}




