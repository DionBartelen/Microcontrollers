/*
 * Opdracht1.c
 *
 * Created: 1-3-2018 15:24:49
 * Author : dionb
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{	
	DDRF = 0x00;				// set PORTF for input (ADC)
	DDRA = 0xFF;				// set PORTA for output
	DDRB = 0xFF;
		
	ADMUX = 0b01100000;			// 01100001     Bit 7 en 6 zorgen voor de ADC output.  Bit 5 is ADLAR die op 1 wordt gezet. Bit 4 tot en met 0 is voor het kiezen van pinF0 tot en met pinF7.
	ADCSRA = 0b11100110;		// 11100110		Bit 7 enable ADC. Bit 6 ADC start conversie. Bit 5 Free running aan of uit. Bit 2:0 is voor de prescaler (64 in dit geval).
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB = ADCL;			// Show MSB/LSB (bit 10:0) of ADC
		PORTA = ADCH;
		wait(100);
    }
}


void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
	}
}
