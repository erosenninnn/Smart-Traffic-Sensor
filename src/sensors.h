#ifndef SENSORS_H
#define SENSORS_H

void adc_init(void);
unsigned int adc_read(unsigned char channel);
float read_temperature(void);
float read_air_quality(void);

#endif
