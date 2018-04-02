/*
 * LCD.h
 *
 * Created: 22-2-2018 15:34:21
 *  Author: dionb
 */ 


#ifndef LCD_H_
#define LCD_H_

void lcd_init();
void lcd_clr_display();
void lcd_writeChar( unsigned char dat );
void lcd_display_text(char *str);
void lcd_set_cursor(int pos);
void lcd_set_display(int pos);

void lcd_command ( unsigned char dat );

#endif /* LCD_H_ */