#ifndef RF24_UTILITY_ESP_IDF_COMPATIBILITY_H_
#define RF24_UTILITY_ESP_IDF_COMPATIBILITY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void __msleep(int millisec);
void __usleep(int microsec);
void __start_timer(void);
uint32_t __millis(void);

#ifdef __cplusplus
}
#endif

#endif // RF24_UTILITY_ESP_IDF_COMPATIBILITY_H_
