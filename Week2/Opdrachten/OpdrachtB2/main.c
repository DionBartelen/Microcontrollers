/*
 * OpdrachtB2.c
 *
 * Created: 8-2-2018 16:01:33
 * Author : dionb
 */ 
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

static int pos = 0;

int main(void)
{
	DDRE = 0xFF;

	DDRD = 0x00;
	EICRA = 0b00111111;
	EIMSK = 0b00111111;
	sei();
	
	//PORTE = 0b00000001;
    /* Replace with your application code */
    while (1) 
    {
		wait(10);
    }
}

ISR( INT0_vect )
{
	if(PORTE == 0x00) {
		PORTE = 0b00000001;
	}else {
	PORTE = (PORTE << 1) % 0xFF;
	}
	//PORTE = 0b00000001;
}

ISR( INT1_vect )
{
	if(PORTE == 0x00) {
		PORTE = 0b00000001;
		}else {
		PORTE = (PORTE >> 1) % 0xFF;
	}
	//PORTE = 0b10000000;
}


void wait(int ms) {
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}