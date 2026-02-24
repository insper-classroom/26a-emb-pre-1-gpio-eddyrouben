#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;
const int LED_R   = 5;
const int LED_P   = 8;
const int LED_B   = 11;
const int LED_Y   = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(LED_R);
  gpio_set_dir(LED_R, GPIO_OUT);

  gpio_init(LED_P);
  gpio_set_dir(LED_P, GPIO_OUT);

  gpio_init(LED_B);
  gpio_set_dir(LED_B, GPIO_OUT);

  gpio_init(LED_Y);
  gpio_set_dir(LED_Y, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      while (!gpio_get(BTN_PIN)) {
      };

      gpio_put(LED_R, 0);
      gpio_put(LED_P, 0);
      gpio_put(LED_B, 0);
      gpio_put(LED_Y, 0);

      gpio_put(LED_R, 1);
      sleep_ms(300);
      gpio_put(LED_R, 0);

      gpio_put(LED_P, 1);
      sleep_ms(300);
      gpio_put(LED_P, 0);

      gpio_put(LED_B, 1);
      sleep_ms(300);
      gpio_put(LED_B, 0);

      gpio_put(LED_Y, 1);
      sleep_ms(300);
      gpio_put(LED_Y, 0);
    }
  }
}
