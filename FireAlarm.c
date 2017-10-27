/**
 * Listen for PWM-signals from a 433.92Mhz receiver
 * Parse the packet
 * If proper packet; send a MQTT message (not yet implemented)
 */
#include "espressif/esp_common.h"
#include "esp/uart.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "esp8266.h"

const int gpio = 0;

static void demo(void *pvParameters)
{
	while (1) {
		if (gpio_read(gpio)) {
			printf("push\n");
		} else {
			printf("still\n");
		}
		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}

void user_init(void)
{
	uart_set_baud(0, 115200);

	xTaskCreate(&demo, "demothread", 256, NULL, 2, NULL);
}

