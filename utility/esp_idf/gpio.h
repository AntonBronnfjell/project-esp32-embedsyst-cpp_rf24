/**
 * GPIO helper for ESP-IDF (RF24 backend)
 */
#ifndef RF24_UTILITY_ESP_IDF_GPIO_H_
#define RF24_UTILITY_ESP_IDF_GPIO_H_

#include <cstdint>

typedef uint16_t rf24_gpio_pin_t;
#define RF24_PIN_INVALID 0xFFFF

class GPIO
{
public:
    static const int DIRECTION_OUT = 1;
    static const int DIRECTION_IN = 0;
    static const int OUTPUT_HIGH = 1;
    static const int OUTPUT_LOW = 0;

    static void open(rf24_gpio_pin_t port, int direction);
    static void close(rf24_gpio_pin_t port);
    static int read(rf24_gpio_pin_t port);
    static void write(rf24_gpio_pin_t port, int value);
};

#endif // RF24_UTILITY_ESP_IDF_GPIO_H_
