/*
 * Timer.c
 *
 * Created: 22-3-2018 09:39:11
 *  Author: dionb
 */ 
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "main.h"

long msCount = 0;

void TimerInit() {
	//TCNT2 = 0;
	//OCR2 = 125;
	//TIMSK |= (1 << 7);
	//SREG |= (1 << 7);
	//TCCR2 = 0b00001011;
	
	OCR2 = 125;
	TIMSK |= (1<<7); 
	TCCR2 = 0b00001011;
}

ISR( TIMER2_COMP_vect )
{
	msCount++;
	if(msCount % 1000 == 0) {
		secondHasPassed();
	}
}