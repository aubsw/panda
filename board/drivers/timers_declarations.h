#pragma once

// Platform includes
#ifdef STM32H7
#include "stm32h7/stm32h7_platform_definitions.h"
#elif defined(STM32F4)
#include "stm32f4/stm32f4_platform_definitions.h"
#endif

void timer_init(TIM_TypeDef *TIM, int psc);
void microsecond_timer_init(void);
uint32_t microsecond_timer_get(void);
void interrupt_timer_init(void);
void tick_timer_init(void);

