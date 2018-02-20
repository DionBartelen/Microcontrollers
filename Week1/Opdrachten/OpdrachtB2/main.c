/*
 * OpdrachtB2.c
 *
 * Created: 1-2-2018 16:31:17
 * Author : dionb
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF;
	
    /* Replace with your application code */
    while (1) 
    {
		PORTD = 0b10000000;
		wait(500);
		PORTD = 0b01000000;
		wait(500);
    }
}

void wait(int ms) {
	int i = 0;
	while(i < ms) {
		_delay_ms(1);
		i++;
	}
}

