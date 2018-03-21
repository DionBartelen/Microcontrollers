/*
 * LCD.c
 *
 * Created: 22-2-2018 15:34:08
 *  Author: dionb
 */
#define F_CPU 8000000

#include <avr/io.h>
#include <avr/delay.h>
#include <string.h>
#include "LCD.h"

int cursorPos = 0;

void LCDinit() {
	// return home
	LCD_command( 0x02 );
	// mode: 4 bits interface data, 2 lines, 5x8 dots
	LCD_command( 0x28 );
	// display: on, cursor off, blinking off
	LCD_command( 0x0C );
	// entry mode: cursor to right, no shift
	LCD_command( 0x06 ); //was 0x06
	// RAM address: 0, first position, line 1
	LCD_command( 0x80 );
}

void LCDdisplay_text(char *str) {
	_delay_ms(1);
	int length = strlen(str);
	for(int x = 0; x < length; x++) {
		lcd_writeChar(str[x]);
	}
}

void LCDdisplay_textTop(char *str) {
	LCDdisplay_text(str);
}

void LCDdisplay_textBot(char *str) {
	LCD_command(0xC0);
	LCDdisplay_text(str);
}

void LCDset_display(int pos) {
	_delay_ms(1);
	for(int x = 0; x < pos; x++) {
		LCD_command(0b0000011000);
	}
}

void LCDset_cursor(int pos){
	_delay_ms(1);
	if(pos < cursorPos) {
		LCD_command(0x02);
	}
	for(int x = cursorPos; x < pos; x++) {
		LCD_command(0b0000010100);
	}
	cursorPos = cursorPos + pos;
}

void LCDclr_display() {
	_delay_ms(1);
	LCD_command(0x01);
}

void lcd_writeChar( unsigned char dat )
{
	PORTC = dat & 0xF0; // hoge nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x04; // stop (EN = 0)
	PORTC = (dat & 0x0F) << 4; // lage nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x00; // stop
	// (EN=0 RS=0)
}

void LCD_command ( unsigned char dat )
{
	PORTC = dat & 0xF0; // hoge nibble
	PORTC = PORTC | 0x08; // data (RS=0),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x04; // stop (EN = 0)
	PORTC = (dat & 0x0F) << 4; // lage nibble
	PORTC = PORTC | 0x08; // data (RS=0),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x00; // stop
	// (EN=0 RS=0)
}