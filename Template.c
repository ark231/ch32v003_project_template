#include <stdint.h>
#include <stdio.h>

#include "ch32v003fun.h"

#define LED PD4

#define LOOP_FREQ     100
#define SEC_IN_US     1'000'000
#define LOOP_DURATION Ticks_from_Us(SEC_IN_US / LOOP_FREQ)

int main(void) {
    SystemInit();

    // Enable GPIOs
    funGpioInitAll();

    funPinMode(LED, GPIO_Speed_10MHz | GPIO_CNF_OUT_PP);

    uint32_t count    = 0;
    uint32_t cur_time = SysTick->CNT;

    printf("Hello, world!\n");

    while (1) {
        if (count % LOOP_FREQ == 0) {
            funDigitalWrite(LED, FUN_HIGH);
        } else if (count % LOOP_FREQ == LOOP_FREQ / 2) {
            funDigitalWrite(LED, FUN_LOW);
        }

        while ((SysTick->CNT - cur_time) < LOOP_DURATION) {
        }
        cur_time = SysTick->CNT;
        count++;
    }
}
