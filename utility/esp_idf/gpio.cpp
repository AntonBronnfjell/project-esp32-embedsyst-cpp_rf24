/**
 * GPIO implementation for ESP-IDF
 */
#include "gpio.h"
#include "driver/gpio.h"

void GPIO::open(rf24_gpio_pin_t port, int direction)
{
    gpio_config_t io = {};
    io.pin_bit_mask = (1ULL << port);
    io.mode = (direction == DIRECTION_OUT) ? GPIO_MODE_OUTPUT : GPIO_MODE_INPUT;
    io.pull_up_en = GPIO_PULLUP_DISABLE;
    io.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io);
}

void GPIO::close(rf24_gpio_pin_t port)
{
    (void)port;
}

int GPIO::read(rf24_gpio_pin_t port)
{
    return gpio_get_level((gpio_num_t)port) ? OUTPUT_HIGH : OUTPUT_LOW;
}

void GPIO::write(rf24_gpio_pin_t port, int value)
{
    gpio_set_level((gpio_num_t)port, value ? 1 : 0);
}
