#include "bbspi.h"


void bb_spi_init(bb_spi_config_t *cfg)
{
    gpio_init(cfg->BB_SPI_PORT, cfg->BB_SPI_CS, GPIO_OUTPUT);
    gpio_init(cfg->BB_SPI_PORT, cfg->BB_SPI_SCK, GPIO_OUTPUT);
    gpio_init(cfg->BB_SPI_PORT, cfg->BB_SPI_MOSI, GPIO_OUTPUT);
    gpio_init(cfg->BB_SPI_PORT, cfg->BB_SPI_MISO, GPIO_INPUT);
}

static void spi_start(bb_spi_config_t *cfg)
{
    gpio_clr_pin(cfg->BB_SPI_PORT, cfg->BB_SPI_CS); 
}

static void spi_stop(bb_spi_config_t *cfg)
{
    gpio_set_pin(cfg->BB_SPI_PORT, cfg->BB_SPI_CS);
}

static void delay_us(bb_spi_config_t *cfg)
{

}

void bb_spi_write(bb_spi_config_t *cfg, uint8_t byte)
{
    /* Step 1: Start the spi transaction by pulling CS pin low */
    spi_start(cfg);
    delay()
}
