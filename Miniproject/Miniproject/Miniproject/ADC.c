/*
 * ADC.c
 *
 * Created: 15-3-2018 16:04:58
 *  Author: dionb
 */ 

#include <avr/io.h>
#include <avr/delay.h>

void ADCInit(){
	ADMUX = 0b01100000;
	ADCSRA = 0b11100110;
	
}


int ADCcurrentValue() {
	return (((float)(ADCH)) / 255.0) * 50.0;
}