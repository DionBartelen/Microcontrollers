/*
 * OpdrachtB4.c
 *
 * Created: 6-2-2018 10:49:16
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
		for(int i = 0x01; i < 0xFF; i <<= 1) {
			PORTD = i;
			wait(50);
		}
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


