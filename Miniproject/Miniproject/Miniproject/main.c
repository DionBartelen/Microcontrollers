/*
 * Miniproject.c
 *
 * Created: 8-3-2018 14:33:50
 * Author : dionb
 */ 
#define F_CPU 8000000
#define LOCKED 0
#define UNLOCKED 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "ADC.h"
#include "ButtonInput.h"

char amountNumberInputText[] = "Code: %s";
char numberLockText[] = "Value %03d   #%d";
int displayDirtyFlag = 1;

int state = 0;
int currentNumber = 0;
int amountGuesses = 3;
int prevADCvalue = 0;
int lengthCode = 4;
int code[] = {0, 0, 0, 0};
	
void wait(int);

int main(void)
{
	DDRC = 0xFF;
	DDRD = 0x00;
	DDRF = 0x00;
	
	ADCInit();
	wait(100);
	LCDinit();
	wait(100);
	ButtonInputInit();
	sei();
    /* Replace with your application code */
    while (1) 
    {
		if(state == LOCKED) {
			checkADC();
			checkBPLocked();
			if(displayDirtyFlag) {
				updateDisplayCodeInput();
			}
		} else if(state == UNLOCKED) {
			checkBPUnlocked();
			if(displayDirtyFlag) {
				updateDisplayUnlocked();
			}
		}
		wait(250);
    }
}

void checkADC() {
	int newADCvalue = ADCcurrentValue();
	if(prevADCvalue != newADCvalue) {
		prevADCvalue = newADCvalue;
		displayDirtyFlag = 1;
	}
}

void checkBPLocked() {
	if(ButtonInputGetButtonPressed()) {
		if(prevADCvalue == code[currentNumber]) {
			currentNumber++;
			if(currentNumber >= lengthCode) {
				state = UNLOCKED;
				currentNumber = 0;
			}
		} else {
			amountGuesses--;
		}
		displayDirtyFlag = 1;
	}
}

void checkBPUnlocked() {
	if(ButtonInputGetButtonPressed()) {
		state = LOCKED;
		currentNumber = 0;
		amountGuesses = 3;
	}
}

void updateDisplayCodeInput() {
	displayDirtyFlag = 0;
	LCDclr_display();
	char newTopText[16];
	char *codeStr;
	if(currentNumber == 0) {
		codeStr = "    ";
		} else if(currentNumber == 1) {
		codeStr = "-   ";
		} else if(currentNumber == 2) {
		codeStr = "--  ";
		} else if(currentNumber == 3) {
		codeStr = "--- ";
		} else  {
		codeStr = "err";
	}
	sprintf(newTopText, amountNumberInputText, codeStr);
	LCDdisplay_textTop(newTopText);
	char newBotText[16];
	sprintf(newBotText, numberLockText, prevADCvalue, amountGuesses);
	LCDdisplay_textBot(newBotText);
	if(state == UNLOCKED) {
		displayDirtyFlag = 1;
	}
}

void updateDisplayUnlocked() {
	displayDirtyFlag = 0;
	LCDclr_display();
	LCDdisplay_textTop("Unlocked");
	if(state == LOCKED) {
		displayDirtyFlag = 1;
	}
}

void wait(int ms) {
	for(int x = 0; x < ms; x++) {
		_delay_ms(1);
	}
}