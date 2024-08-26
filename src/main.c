#include <stdio.h>

#include "ch32v003fun.h"
#include "ch32v003_GPIO_branchless.h"

#define BTN1_PIN GPIOv_from_PORT_PIN(GPIO_port_D, 0)
#define BTN2_PIN GPIOv_from_PORT_PIN(GPIO_port_A, 1)
#define BTN3_PIN GPIOv_from_PORT_PIN(GPIO_port_D, 6)
#define BTN4_PIN GPIOv_from_PORT_PIN(GPIO_port_D, 4)
#define BTN5_PIN GPIOv_from_PORT_PIN(GPIO_port_D, 3)
#define BTN6_PIN GPIOv_from_PORT_PIN(GPIO_port_D, 1)
#define BTN7_PIN GPIOv_from_PORT_PIN(GPIO_port_C, 6)
#define BTN8_PIN GPIOv_from_PORT_PIN(GPIO_port_C, 4)

#define LED1_PIN GPIOv_from_PORT_PIN(GPIO_port_C, 0)
#define LED2_PIN GPIOv_from_PORT_PIN(GPIO_port_A, 2)
#define LED3_PIN GPIOv_from_PORT_PIN(GPIO_port_D, 7)
#define LED4_PIN GPIOv_from_PORT_PIN(GPIO_port_D, 5)
#define LED5_PIN GPIOv_from_PORT_PIN(GPIO_port_D, 2)
#define LED6_PIN GPIOv_from_PORT_PIN(GPIO_port_C, 7)
#define LED7_PIN GPIOv_from_PORT_PIN(GPIO_port_C, 5)
#define LED8_PIN GPIOv_from_PORT_PIN(GPIO_port_C, 3)

static const uint32_t LEDS[] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN, LED8_PIN};
static const uint32_t BTNS[] = {BTN1_PIN, BTN2_PIN, BTN3_PIN, BTN4_PIN, BTN5_PIN, BTN6_PIN, BTN7_PIN, BTN8_PIN};

void setup() {
  SystemInit();

  // Enable GPIOs
  funGpioInitAll();

  // 各GPIOの有効化
  GPIO_port_enable(GPIO_port_A);
  GPIO_port_enable(GPIO_port_C);
  GPIO_port_enable(GPIO_port_D);

  for (int i=0; i<8; i++) {
      GPIO_pinMode(LEDS[i], GPIO_pinMode_O_pushPull, GPIO_Speed_10MHz);
      GPIO_pinMode(BTNS[i], GPIO_pinMode_I_pullUp, GPIO_Speed_10MHz);
  }
}

int main() {
  setup();

  int step = 0;
  while(1) {
#if 0
    if (GPIO_digitalRead(BTN1_PIN) == low)
    {
            GPIO_digitalWrite(LED1_PIN, high);
    } else {
            GPIO_digitalWrite(LED1_PIN, low);
      
    }
    GPIO_digitalWrite(LED2_PIN, high);
    GPIO_digitalWrite(LED3_PIN, high);
    GPIO_digitalWrite(LED4_PIN, high);
    GPIO_digitalWrite(LED5_PIN, high);
    GPIO_digitalWrite(LED6_PIN, high);
    GPIO_digitalWrite(LED7_PIN, high);
    GPIO_digitalWrite(LED8_PIN, high);
    Delay_Ms(200);
    GPIO_digitalWrite(LED2_PIN, low);
    GPIO_digitalWrite(LED3_PIN, low);
    GPIO_digitalWrite(LED4_PIN, low);
    GPIO_digitalWrite(LED5_PIN, low);
    GPIO_digitalWrite(LED6_PIN, low);
    GPIO_digitalWrite(LED7_PIN, low);
    GPIO_digitalWrite(LED8_PIN, low);
    Delay_Ms(200);
#endif
    GPIO_digitalWrite(LEDS[step], low);
    step++;
    step %= 8;
    GPIO_digitalWrite(LEDS[step], high);
    
    Delay_Ms(100);
  }
}
