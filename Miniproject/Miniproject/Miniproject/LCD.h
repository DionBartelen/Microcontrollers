/*
 * LCD.h
 *
 * Created: 22-2-2018 15:34:21
 *  Author: dionb
 */ 


#ifndef LCD_H_
#define LCD_H_

void LCDinit();
void LCDclr_display();
void LCDdisplay_text(char *str);
void LCDset_cursor(int pos);
void LCDset_display(int pos);
void LCD_command ( unsigned char dat );
void LCDdisplay_textTop(char*);
void LCDdisplay_textBot(char*);

#endif /* LCD_H_ */