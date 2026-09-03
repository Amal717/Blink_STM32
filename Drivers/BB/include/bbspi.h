#ifndef BBSPI_H
#define BBSPI_H

#include "stm32f407xx.h"
#include "gpio.h"

typedef struct {
    gpio_port_t BB_SPI_PORT;        /* GPIO port to be used for bit banging */
    uint8_t BB_SPI_CS;              /* CS */
    uint8_t BB_SPI_SCK;
    uint8_t BB_SPI_MISO;            /* Master In Slave Out */
    uint8_t BB_SPI_MOSI;            /* Master Out Slave In */
    uint8_t CPU_CLOCK_FREQ;         /* cpu clock frequency */
}bb_spi_config_t;

void bb_spi_init(bb_spi_config_t *cfg);




#endif // BBSPI_H
