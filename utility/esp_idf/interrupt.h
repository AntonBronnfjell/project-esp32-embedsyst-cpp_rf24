#ifndef RF24_UTILITY_ESP_IDF_INTERRUPT_H_
#define RF24_UTILITY_ESP_IDF_INTERRUPT_H_

#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

int attachInterrupt(rf24_gpio_pin_t pin, int mode, void (*function)(void));
int detachInterrupt(rf24_gpio_pin_t pin);
void rfNoInterrupts(void);
void rfInterrupts(void);

#ifdef __cplusplus
}
#endif

#endif // RF24_UTILITY_ESP_IDF_INTERRUPT_H_
