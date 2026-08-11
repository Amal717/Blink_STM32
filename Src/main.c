#include "clock.h"
#include <stdint.h>

void delay(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
        for (uint32_t j = 0; j < 12000; j++);
}

void led_init(void)
{
    /* Enable GPIOD clock */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    /* PD12 = output */
    GPIOD->MODER &= ~(3U << (12 * 2));
    GPIOD->MODER |=  (1U << (12 * 2));

    GPIOD->MODER &= ~(3U << (13 * 2));
    GPIOD->MODER |=  (1U << (13 * 2));

    GPIOD->MODER &= ~(3U << (14 * 2));
    GPIOD->MODER |=  (1U << (14 * 2));

    GPIOD->MODER &= ~(3U << (15 * 2));
    GPIOD->MODER |=  (1U << (15 * 2));


    // /* Push-pull */
    // GPIOD->OTYPER &= ~(1U << 12);
    // GPIOD->OTYPER &= ~(1U << 14);
    //
    // /* No pull-up/pull-down */
    // GPIOD->PUPDR &= ~(3U << (12 * 2));
    // GPIOD->PUPDR &= ~(3U << (14 * 2));
}

int main(void)
{
    clock_init();
    led_init();

    while (1)
    {
        GPIOD->BSRR = 1 << 12;
        delay(500);
        GPIOD->BSRR = 1 << (12 + 16);
        GPIOD->BSRR = 1 << 13;
        delay(500);
        GPIOD->BSRR = 1 << (13 + 16);
        GPIOD->BSRR = 1 << 14;
        delay(500);
        GPIOD->BSRR = 1 << (14 + 16);
        GPIOD->BSRR = 1 << 15;
        delay(500);
        GPIOD->BSRR = 1 << (15 + 16);
    }
    return 0;
}
