#pragma once
#include <stdint.h>
#include "drivers/interrupts_declarations.h"

// Platform includes (provides __enable_irq, __disable_irq)
#ifdef STM32H7
  #include "stm32h7/stm32h7_platform_definitions.h"
#elif defined(STM32F4)
  #include "stm32f4/stm32f4_platform_definitions.h"
#endif

// ********************* Critical section helpers *********************
void enable_interrupts(void);
void disable_interrupts(void);

extern uint8_t global_critical_depth;
extern volatile bool interrupts_enabled;

#define ENTER_CRITICAL()                                      \
  __disable_irq();                                            \
  global_critical_depth += 1U;

#define EXIT_CRITICAL()                                       \
  global_critical_depth -= 1U;                                \
  if ((global_critical_depth == 0U) && interrupts_enabled) {  \
    __enable_irq();                                           \
  }
