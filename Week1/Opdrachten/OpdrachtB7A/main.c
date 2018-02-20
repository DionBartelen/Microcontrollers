/*
 * OpdrachtB7A.c
 *
 * Created: 6-2-2018 13:02:52
 * Author : dionb
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

typedef void *(*StateFunc)();

void *start();
void *end();
void *s1();
void *s2();
void *s3();


int main(void)
{
	DDRD = 0xFF;
	DDRB = 0x00;
	DDRE = 0xFF;
	StateFunc statefunc = start;
	
    /* Replace with your application code */
    while (1) 
    {
		statefunc = (StateFunc)(*statefunc)();
		wait(250);
    }
}


void *start() {
	PORTD = 0b00000001;
	int pressedBtn = checkBtn();
	if(pressedBtn == 5) {
		return s2;
	} else if(pressedBtn == 6) {
		return s1;
	}
	return start;
}

void *end() {
	PORTD = 0b10000001;
	int pressedBtn = checkBtn();
	if(pressedBtn == 7) {
		return start;
	}
	return end;
}

void *s1() {
	PORTD = 0b00000101;
	int pressedBtn = checkBtn();
	if(pressedBtn == 7) {
		return start;
	} else if(pressedBtn == 5) {
		return s2;
	}
	return s1;
}

void *s2() {
	PORTD = 0b00010101;
	int pressedBtn = checkBtn();
	if(pressedBtn == 5) {
		return s3;
	} else if(pressedBtn == 6) {
		return s1;
	}
	return s2;
}

void *s3() {
	PORTD = 0b01010101;
	int pressedBtn = checkBtn();
	if(pressedBtn == 7) {
		return start;
	} else if(pressedBtn == 5 || pressedBtn == 6) {
		return end;
	}
	return s3;
}

int checkBtn() {
	if(PINC & (1 << PC0)) {
		PORTE = 0b00000001;
		return 0;
	} else if(PINC & (2 << PC0)) {
		PORTE = 0b00000010;
		return 1;
	} else if(PINC & (4 << PC0)) {
		PORTE = 0b00000100;
		return 2;
	} else if(PINC & (8 << PC0)) {
		PORTE = 0b00001000;
		return 3;
	} else if(PINC & (16 << PC0)) {
		PORTE = 0b00010000;
		return 4;
	} else if(PINC & (32 << PC0)) {
		PORTE = 0b00100000;
		return 5;
	} else if(PINC & (64 << PC0)) {
		PORTE = 0b01000000;
		return 6;
	} else if(PINC & (128 << PC0)) {
		PORTE = 0b10000000;
		return 7;
	}
	return -1;
}

void wait(int ms) {
	for(int i = 0; i < ms; i++) {
		_delay_ms(1);
	}
}
