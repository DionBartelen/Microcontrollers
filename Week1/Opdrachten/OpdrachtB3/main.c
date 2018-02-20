/*
 * OpdrachtB3.c
 *
 * Created: 1-2-2018 16:43:27
 * Author : dionb
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xFF;
	DDRC = 0x00;

    /* Replace with your application code */
    while (1)
    {
		if(PINC & 0x01) {
			PORTD = 0b10000000;
			} else {
			PORTD = 0b00000000;
		}
		wait(100);
    }
	return 1;
}

void wait(int ms) {
	int i = 0;
	while(i < ms) {
		_delay_ms(1);
		i++;
	}
}

