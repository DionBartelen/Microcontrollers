/*
 * Opdracht5.c
 *
 * Created: 6-2-2018 11:26:57
 * Author : dionb
 */ 
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xFF;
	
	int animation1[8] = {
		0b10101010, 0b01010101, 0b10101010, 0b01010101, 0b10101010, 0b01010101, 0b10101010, 0b01010101
	};
	
	int animation2[34] = {
		0b11111111, 0b01111111, 0b001111110, 0b00011111, 0b00001111, 0b00000111, 0b00000011, 0b00000001, 0b00000000, 0b00000001, 0b00000011, 
		0b00000111, 0b00001111, 0b00011111, 0b00111111, 0b01111111, 0b11111111, 0b11111110, 0b11111100, 0b11111000, 0b11110000, 0b11100000, 0b11000000, 0b10000000, 
		0b00000000, 0b00000001, 0b00000011, 0b00000111, 0b00001111, 0b00011111, 0b00111111, 0b00111111, 0b01111111, 0b11111111
	};
	
    /* Replace with your application code */
    while (1) 
    {
		for(int j = 0; j < 10; j++) {
			for(int i = 0; i < 8; i++) {
				PORTD = animation1[i];
				wait(100);
			}
		}
		
		for(int i = 0; i < 34; i++) {
			PORTD = animation2[i];
			wait(50);
		}
    }
}

void wait(int ms) {
	for(int i = 0; i < ms; i++) {
		_delay_ms(1);
	}
}

