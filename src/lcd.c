#include <lpc17xx.h>
#include "lcd.h"
#include <stdio.h>
#define RS (1<<10)
#define EN (1<<11)
#define DATA (0xFF<<15)

void lcd_delay(unsigned int a) {
    unsigned int i, j;
    for (i = 0; i < a; i++)
        for (j = 0; j < 6000; j++);
}

void lcd_config() {
    LPC_GPIO0->FIODIR = RS | EN | DATA;
    lcd_cmd(0x38);
    lcd_cmd(0x0E);
    lcd_cmd(0x01);
    lcd_cmd(0x80);
}

void lcd_cmd(unsigned int c) {
    LPC_GPIO0->FIOCLR = (0xFF << 15);
    LPC_GPIO0->FIOSET = (c << 15);
    LPC_GPIO0->FIOCLR = RS;
    LPC_GPIO0->FIOSET = EN;
    lcd_delay(10);
    LPC_GPIO0->FIOCLR = EN;
}

void lcd_data(unsigned char a) {
    LPC_GPIO0->FIOCLR = (0xFF << 15);
    LPC_GPIO0->FIOSET = (a << 15);
    LPC_GPIO0->FIOSET = RS;
    LPC_GPIO0->FIOSET = EN;
    lcd_delay(10);
    LPC_GPIO0->FIOCLR = EN;
}

void lcd_str(unsigned char *ptr) {
    while (*ptr != '\0') {
        lcd_data(*ptr);
        ptr++;
    }
}

void lcd_num(unsigned int num) {
    if (num) {
        lcd_num(num / 10);
        lcd_data(num % 10 + 0x30);
    }
}

void lcd_trafficCh(int n, int d) {
    switch (n) {
    case 1:
        lcd_str("R1 R2 R3 R4");
        lcd_cmd(0xC0);
        lcd_str("G  R  R  R");
        lcd_delay(d);
        lcd_cmd(0x01);
        break;
    case 2:
        lcd_str("R1 R2 R3 R4");
        lcd_cmd(0xC0);
        lcd_str("R  G  R  R");
        lcd_delay(d);
        lcd_cmd(0x01);
        break;
    case 3:
        lcd_str("R1 R2 R3 R4");
        lcd_cmd(0xC0);
        lcd_str("R  R  G  R");
        lcd_delay(d);
        lcd_cmd(0x01);
        break;
    case 4:
        lcd_str("R1 R2 R3 R4");
        lcd_cmd(0xC0);
        lcd_str("R  R  R  G");
        lcd_delay(d);
        lcd_cmd(0x01);
        break;
    default:
        lcd_str("TRAFFIC CTRL");
        lcd_cmd(0xC0);
        lcd_str("WAIT...");
        lcd_delay(d);
        lcd_cmd(0x01);
    }
}

void lcd_showSensors(float temp, float airq) {
    char buf[16];
    lcd_cmd(0x80);
    sprintf(buf, "ENV: T:%2.1fC", temp);
    lcd_str(buf);
    lcd_cmd(0xC0);
    sprintf(buf, "AQ:%3.0f%%", airq);
    lcd_str(buf);
    lcd_delay(500);
    lcd_cmd(0x01);
}
