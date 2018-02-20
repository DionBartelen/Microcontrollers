/*
 * OpdrachtB6.c
 *
 * Created: 6-2-2018 11:54:24
 * Author : dionb
 */ 
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

int state = 0;

int main(void)
{
	DDRC = 0x00;
	DDRD = 0xFF;
	int ledOn = 0;
    /* Replace with your application code */
    while (1) 
    {
		
		if(ledOn == 1) {
			PORTD = 0x00;
			ledOn = 0;
		} else {
			PORTD = 0b10000000;
			ledOn = 1;
		}
		
		if(state == 0) {
			wait(1000);
		} else if(state == 1) {
			wait(250);
		}
    }
}

void wait(int ms) {
	for(int i = 0; i < ms; i++) {
		_delay_ms(1);
		if(PINC & 0x01) {
			state = (state + 1) % 2;
		}
	}
}

