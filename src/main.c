#include <stdbool.h>
#include <stm8s.h>
#include "main.h"
#include "milis.h"
//#include "delay.h"
//#include "uart1.h"
//#include <stdio.h>
#include "sonboard.h"

uint8_t led_pointer = 0;

// Discovery Board
#ifdef STM8S003
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_0
#define BTN_PORT GPIOB
#define BTN_PIN  GPIO_PIN_7
#endif
// Dero Board
#ifdef STM8S103
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_4
#endif
// Discovery Board
#ifdef STM8S105
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_0
#endif
// Nucleo Kit
#ifdef STM8S208
#define LED_PORT GPIOC
#define LED_PIN  GPIO_PIN_5
#define BTN_PORT GPIOE
#define BTN_PIN  GPIO_PIN_4
#endif


void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    init_milis();
    //init_uart1();

    GPIO_Init(SB_LED1_PORT, SB_LED1_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(SB_LED2_PORT, SB_LED2_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(SB_LED3_PORT, SB_LED3_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    GPIO_Init(SB_S1_PORT,SB_S1_PIN,GPIO_MODE_IN_PU_NO_IT);

    TIM3_TimeBaseInit(TIM3_PRESCALER_128, 37500 - 1);
    TIM3_Cmd(ENABLE);
    TIM3_ITConfig(TIM3_IT_UPDATE, ENABLE);
    enableInterrupts();
}


int main(void)
{
  
    uint32_t time = 0;
    bool S1_press;

    init();

    while (1) {
        if (milis() - time > 33) {
            time = misli();

            if (PUSH(SB_S1) && !S1_press) {
                led_pointer +=1;
            }
            if (led_pointer > 2) {
                led_pointer = 0;
            }
            S1_press = PUSH(SB_S1);
        }
        
    
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
