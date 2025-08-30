#include <lpc17xx.h>
#include "lcd.h"
#include "traffic.h"
#include "sensors.h"

// Main program: initializes all peripherals and runs traffic + sensor display
int main() {
    lcd_config();           // Initialize LCD
    adc_init();             // Initialize ADC for sensors
    LPC_GPIO1->FIODIR = (0xFF << 19);  // Set P1.19-P1.26 as output for LEDs
    LPC_GPIO2->FIODIR &= ~(0xF);       // Set P2.0-P2.3 as input for IR sensors

    while (1) {
        // Check IR sensors and control traffic
        if ((LPC_GPIO2->FIOPIN & (1 << 0)) == 0) {
            IR_traffic(1, 1000, 19, 22, 24, 26);
        } else if ((LPC_GPIO2->FIOPIN & (1 << 1)) == 0) {
            IR_traffic(2, 1000, 20, 21, 24, 26);
        } else if ((LPC_GPIO2->FIOPIN & (1 << 2)) == 0) {
            IR_traffic(3, 1000, 20, 22, 23, 26);
        } else if ((LPC_GPIO2->FIOPIN & (1 << 3)) == 0) {
            IR_traffic(4, 1000, 20, 22, 24, 25);
        } else {
            IR_trafficDefault();
        }

        // Show environmental data on LCD
        float temp = read_temperature();
        float airq = read_air_quality();
        lcd_showSensors(temp, airq);
    }
}
