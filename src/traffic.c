#include <lpc17xx.h>
#include "lcd.h"
#include "traffic.h"

void IR_traffic(int road, int d, int LED_1, int LED_2, int LED_3, int LED_4) {
    LPC_GPIO1->FIOSET = (1 << LED_1);
    LPC_GPIO1->FIOSET = (1 << LED_2);
    LPC_GPIO1->FIOSET = (1 << LED_3);
    LPC_GPIO1->FIOSET = (1 << LED_4);
    lcd_trafficCh(road, d);
    LPC_GPIO1->FIOCLR = (1 << LED_1);
    LPC_GPIO1->FIOCLR = (1 << LED_2);
    LPC_GPIO1->FIOCLR = (1 << LED_3);
    LPC_GPIO1->FIOCLR = (1 << LED_4);
}

void IR_trafficDefault() {
    // Cycle through all roads briefly
    IR_traffic(1, 200, 19, 22, 24, 26);
    IR_traffic(2, 200, 20, 21, 24, 26);
    IR_traffic(3, 200, 20, 22, 23, 26);
    IR_traffic(4, 200, 20, 22, 24, 25);
}
