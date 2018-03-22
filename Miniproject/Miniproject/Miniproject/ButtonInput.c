/*
 * ButtonInput.c
 *
 * Created: 15-3-2018 20:18:22
 *  Author: dionb
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

int buttonPressed = 0;

void ButtonInputInit() {
	EICRA = 0b00001100;
	EIMSK = 0b00000010;
}

int ButtonInputGetButtonPressed() {
	if(buttonPressed) {
		wait(100);
		buttonPressed = 0;
		return 1;
	}
	return 0;
}

ISR( INT1_vect )
{
	buttonPressed = 1;
}