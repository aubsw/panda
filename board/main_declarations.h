#pragma once
// Platform includes (provides TIM_TypeDef)
#ifdef STM32H7
  #include "stm32h7/stm32h7_platform_definitions.h"
#elif defined(STM32F4)
  #include "stm32f4/stm32f4_platform_definitions.h"
#endif

// ******************** Prototypes ********************
void print(const char *a);
void puth(unsigned int i);
void puth2(unsigned int i);
void puth4(unsigned int i);
void hexdump(const void *a, int l);
typedef struct board board;
typedef struct harness_configuration harness_configuration;
void pwm_init(TIM_TypeDef *TIM, uint8_t channel);
void pwm_set(TIM_TypeDef *TIM, uint8_t channel, uint8_t percentage);

// ********************* Globals **********************
extern uint8_t hw_type;
extern board *current_board;
extern uint32_t uptime_cnt;
extern bool green_led_enabled;

// heartbeat state
extern uint32_t heartbeat_counter;
extern bool heartbeat_lost;
extern bool heartbeat_disabled;            // set over USB

// siren state
extern bool siren_enabled;
