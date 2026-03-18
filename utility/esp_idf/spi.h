/**
 * SPI class for ESP-IDF (RF24 backend)
 */
#ifndef RF24_UTILITY_ESP_IDF_SPI_H_
#define RF24_UTILITY_ESP_IDF_SPI_H_

#include <stdint.h>
#include "driver/spi_master.h"
#include "driver/gpio.h"

#ifndef RF24_SPI_SPEED
    #define RF24_SPI_SPEED 10000000
#endif

class SPI
{
public:
    SPI(spi_host_device_t host = SPI2_HOST);
    ~SPI();

    void setPins(int sck, int miso, int mosi);
    void begin(int sck, int miso, int mosi, int csn_pin, uint32_t spi_speed = RF24_SPI_SPEED);
    void begin();  // no-arg for RF24 (uses already configured pins)

    uint8_t transfer(uint8_t tx);
    void transfernb(char* txBuf, char* rxBuf, uint32_t len);
    void transfern(char* buf, uint32_t len);

private:
    spi_host_device_t _host;
    int _sck;
    int _miso;
    int _mosi;
    int _csn_pin;
    uint32_t _spi_speed;
    bool _initialized;
    spi_device_handle_t _handle;

    void init();
};

#endif // RF24_UTILITY_ESP_IDF_SPI_H_
