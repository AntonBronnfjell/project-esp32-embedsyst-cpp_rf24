#include "interrupt.h"

#ifdef __cplusplus
extern "C" {
#endif

int attachInterrupt(rf24_gpio_pin_t pin, int mode, void (*function)(void))
{
    (void)pin;
    (void)mode;
    (void)function;
    return 0;
}

int detachInterrupt(rf24_gpio_pin_t pin)
{
    (void)pin;
    return 0;
}

void rfNoInterrupts(void) {}
void rfInterrupts(void) {}

#ifdef __cplusplus
}
#endif
