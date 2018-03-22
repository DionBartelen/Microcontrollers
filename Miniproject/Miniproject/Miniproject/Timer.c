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
#include "Timer.h"

long tickCount = 0;
long msCount = 0;

void TimerInit() {
	// PWM,Phase correct,8-Bit mode
	TCCR1A|=(1<<WGM10);
	//no-inverting PWM
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<COM1C1);
	// Timer running on MCU clock/256
	TCCR1B |= 0b100;
	OCR1A = POS_LOCKED;
	
	OCR2 = 125;
	TIMSK |= (1<<7); 
	TCCR2 = 0b00001011;
}

void Lock() {
	OCR1A = POS_LOCKED;
}

void UnLock() {
	OCR1A = POS_UNLOCKED;
}

ISR( TIMER2_COMP_vect )
{
	msCount++;
	if(msCount % 1000 == 0) {
		secondHasPassed();
		msCount = 0;
	}
}