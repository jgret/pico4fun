/**
 * @file main.c
 * @author Thomas Greimel (thomas.greimel04@gmail.com)
 * @brief Simple led blink program
 * @version 0.1
 * @date 2023-08-13
 * 
 * HARDWARE CONNECTIONS
 *  - GPIO 18 ---> LED
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hello.pio.h"

#define LED_PIN 18

int main() {

    PIO pio = pio0;

    uint offset = pio_add_program(pio, &hello_program);

    // claim a free state machine
    uint sm = pio_claim_unused_sm(pio, 1);

    hello_program_init(pio, sm, offset, LED_PIN);

    while (1) {
        pio_sm_put_blocking(pio, sm, 1);
        sleep_ms(500);

        pio_sm_put_blocking(pio, sm, 0);
        sleep_ms(500);
    }


    return 0;
}