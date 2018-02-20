/*
 * OpdrachtB7B.c
 *
 * Created: 6-2-2018 12:25:16
 * Author : dionb
 */ 
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0b00000000;
	int led = 0;
    /* Replace with your application code */
    while (1) 
    {
		setCharliePlexingLed(led);
		wait(500);
		PORTD = 0b00000000;
		wait(500);
		led = (led + 1) % 6;	
	}
	return 1;
}

void setCharliePlexingLed(int lednr) {
	if(lednr == 0) {
		//Led 1 aan
		DDRD = 0b11111110;
		PORTD = 0b00000100;
	} else if(lednr == 1) {
		//Led 2 aan
		DDRD = 0b11111110;
		PORTD = 0b00000010;
	} else if(lednr == 2) {
		//Led 3 aan
		DDRD = 0b11111011;
		PORTD = 0b00000010;
	} else if(lednr == 3) {
		//Led 4 aan
		DDRD = 0b11111011;
		PORTD = 0b00000001;
	} else if(lednr == 4) {
		//Led 5 aan
		DDRD = 0b11111101;
		PORTD = 0b00000001;
	} else if(lednr == 5) {
		//Led 6 aan
		DDRD = 0b11111101;
		PORTD = 0b00000100;
	}
}

void wait(int ms) {
	for(int i = 0; i < ms; i++) {
		_delay_ms(1);
	}
}

