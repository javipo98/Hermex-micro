/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "nvs_flash.h"

#include "esp_log.h"
#include "driver/uart.h"
// #include "minmea.h"

/*
    Definicion de todas las variables a utilizar en el proyecto.
    Las variables estan organizadas segun el modulo.
*/
#define MICROPHONE 34
#define CS_SD 36
#define CS_OBD2 39
#define SPI_MOSI 23
#define SPI_MISO 19
#define SPI_SCK 9
#define ACC_ SCL 22
#define ACC_SDA 21
#define GPS_TX 1
#define GPS_RX 3
#define GSM_TX 17
#define GSM_RX 16

// void app_main()
// {
//     printf("--------HERMEX--------\n");

//     for (int i = 10; i >= 0; i--)
//     {
//         printf("Restarting in %d seconds...\n", i);
//         vTaskDelay(1000 / portTICK_PERIOD_MS);
//     }
//     printf("Restarting now.\n");
//     fflush(stdout);
//     esp_restart();
// }

void tarea1(void *pvParameter)
{
    while (1)
    {
        printf("Ejecutando tarea 1\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void tarea2(void *pvParameter)
{
    while (1)
    {
        printf("Ejecutando tarea 2\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void tarea3(void *pvParameter)
{
    while (1)
    {
        printf("Ejecutando tarea 3\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void tarea4(void *pvParameter)
{
    while (1)
    {
        printf("Ejecutando tarea 4\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

static char tag[] = "gps";
void doGPS(void *pvParameter)
{
    
    // ESP_LOGD(tag, ">> doGPS");

    
    uart_config_t myUartConfig;
    myUartConfig.baud_rate = 9600;
    myUartConfig.data_bits = UART_DATA_8_BITS;
    myUartConfig.parity = UART_PARITY_DISABLE;
    myUartConfig.stop_bits = UART_STOP_BITS_1;
    myUartConfig.flow_ctrl = UART_HW_FLOWCTRL_DISABLE;
    myUartConfig.rx_flow_ctrl_thresh = 120;

    uart_param_config(UART_NUM_1, &myUartConfig);
    uart_set_pin(UART_NUM_1,
                 UART_PIN_NO_CHANGE,             // TX
                 UART_NUM_1_RXD_DIRECT_GPIO_NUM, // RX
                 UART_PIN_NO_CHANGE,             // RTS
                 UART_PIN_NO_CHANGE              // CTS
    );
    uart_driver_install(UART_NUM_0, 2048, 2048, 10, 17, NULL);
    unsigned char buf[100];
    int size;
    while (1)
    {
        size = uart_read_bytes(UART_NUM_1, buf, sizeof(buf), 1000 / portTICK_PERIOD_MS);
        // printf(size);
        printf("GPS reading ====================>>>>>>>>>>>>>>>");
        printf("Size: %d",size);
        // ESP_LOGD(tag, "Bytes read = %d", size);
        if (size > 0)
        {
            // ESP_LOGD(tag, "%.*s", size, buf);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}


void app_main()
{
    nvs_flash_init();
    // setup();
    xTaskCreate(&tarea1, "tarea1", 1024, NULL, 1, NULL);
    xTaskCreate(&tarea2, "tarea2", 1024, NULL, 2, NULL);
    xTaskCreate(&tarea3, "tarea3", 1024, NULL, 3, NULL);
    xTaskCreate(&tarea4, "tarea4", 1024, NULL, 4, NULL);
    xTaskCreate(&doGPS, "doGPS", 1024, NULL, 4, NULL);

    //vTaskStartScheduler();
}