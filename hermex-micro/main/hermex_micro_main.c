/* 
    Hermex micro es el codigo utilizado para el micro del proyecto Hermex.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

/*
    Definicion de todas las variables a utilizar en el proyecto.
    Las variables estan organizadas segun el modulo.
*/
#define MICROPHONE  34
#define CS_SD       36
#define CS_OBD2     39
#define SPI_MOSI    23
#define SPI_MISO    19
#define SPI_SCK     9
#define ACC_ SCL    22
#define ACC_SDA     21
#define GPS_TX      1
#define GPS_RX      3
#define GSM_TX      17
#define GSM_RX      16

void app_main()
{
    printf("--------HERMEX--------\n");

    for (int i = 10; i >= 0; i--)
    {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
