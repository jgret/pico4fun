#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "lwip/apps/httpd.h"
#include "dht22-pico.h"

#define DHT_DATA_PIN 15
	
int main() {
    stdio_init_all();

    dht_reading sensor = dht_init(DHT_DATA_PIN);
    
    if (cyw43_arch_init()) 
    {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    while (true) 
    {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1); 

        dht_read(&sensor);
        printf("Temperature: %.1f Humidity: %.1f\n", sensor.temp_celsius, sensor.humidity);

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(1000);
    }
    return 0;
}