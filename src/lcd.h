#ifndef LCD_H
#define LCD_H

void lcd_config(void);
void lcd_cmd(unsigned int c);
void lcd_data(unsigned char c);
void lcd_str(unsigned char *ptr);
void lcd_num(unsigned int num);
void lcd_delay(unsigned int a);
void lcd_trafficCh(int n, int d);
void lcd_showSensors(float temp, float airq);

#endif
