/*
 * Opdrachten.c
 *
 * Created: 22-2-2018 15:29:24
 * Author : dionb
 */ 
#define F_CPU 8000000

#include <avr/io.h>
#include <avr/delay.h>
#include <string.h>
#include "LCD.h"

static char zin[] = "Darth vader is my daddy , Daddy vader";

int main(void)
{
	DDRD = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
    /* Replace with your application code */
	
	init();
	clr_display();
	display_text(zin);
	int length = strlen(zin);
    while (1) 
    {
		for(int x = 0; x< length; x++) {
		set_display(1);	
		wait(250);
		}
    }
	
	return 0;
}

void wait(int ms) {
	for(int x= 0; x < ms; x++) {
		_delay_ms(1);
	}
}
