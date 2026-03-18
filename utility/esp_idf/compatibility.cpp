#include "compatibility.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#ifdef __cplusplus
extern "C" {
#endif

void __msleep(int millisec)
{
    vTaskDelay(pdMS_TO_TICKS(millisec));
}

void __usleep(int microsec)
{
    if (microsec >= 1000) {
        vTaskDelay(pdMS_TO_TICKS(microsec / 1000));
    } else {
        int n = microsec * 10;
        for (int i = 0; i < n; i++) { __asm__ __volatile__("nop"); }
    }
}

void __start_timer(void)
{
}

uint32_t __millis(void)
{
    return (uint32_t)(esp_timer_get_time() / 1000ULL);
}

#ifdef __cplusplus
}
#endif
