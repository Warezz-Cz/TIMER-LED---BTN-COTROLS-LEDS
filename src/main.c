#include "main.h"
#include "milis.h"
#include <stdbool.h>
#include <stm8s.h>
// #include "delay.h"
// #include "uart1.h"
// #include <stdio.h>
#include "sonboard.h"

extern uint8_t led_pointer;

// Discovery Board
#ifdef STM8S003
#define LED_PORT GPIOD
#define LED_PIN GPIO_PIN_0
#define BTN_PORT GPIOB
#define BTN_PIN GPIO_PIN_7
#endif
// Dero Board
#ifdef STM8S103
#define LED_PORT GPIOD
#define LED_PIN GPIO_PIN_4
#endif
// Discovery Board
#ifdef STM8S105
#define LED_PORT GPIOD
#define LED_PIN GPIO_PIN_0
#endif
// Nucleo Kit
#ifdef STM8S208
#define LED_PORT GPIOC
#define LED_PIN GPIO_PIN_5
#define BTN_PORT GPIOE
#define BTN_PIN GPIO_PIN_4
#endif


void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // taktovani MCU na 16MHz
    init_milis();
    // init_uart1();

    GPIO_Init(SB_LED5_PORT, SB_LED5_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(SB_LED4_PORT, SB_LED4_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(SB_LED3_PORT, SB_LED3_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    GPIO_Init(SB_S3_PORT, SB_S3_PIN, GPIO_MODE_IN_PU_NO_IT);

    TIM3_TimeBaseInit(TIM3_PRESCALER_128, 50000 - 1);
    TIM3_Cmd(ENABLE);
    TIM3_ITConfig(TIM3_IT_UPDATE, ENABLE);
    enableInterrupts();
}


int main(void)
{

    uint32_t time = 0;
    uint8_t btn_press = 0;

    init();

    while (1) {
        if (milis() - time > 33) {
            time = milis();

            if (PUSH(SB_S3) && !btn_press) {
                led_pointer += 1;
            }
            if (led_pointer > 2) {
                led_pointer = 0;
            }
            btn_press = PUSH(SB_S3);
            time = milis();
        }
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
