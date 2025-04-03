// Early bringup
#pragma once
#include "early_init_declarations.h"
#include "config.h"
#include "drivers/led.h"
#include "critical.h"
#include "registers_declarations.h"

void jump_to_bootloader(void) {
  // do enter bootloader
  enter_bootloader_mode = 0;

  bootloader_fcn_ptr bootloader_ptr = (bootloader_fcn_ptr)BOOTLOADER_ADDRESS;
  bootloader_fcn bootloader = *bootloader_ptr;

  // jump to bootloader
  enable_interrupts();
  bootloader();

  // reset on exit
  enter_bootloader_mode = BOOT_NORMAL;
  NVIC_SystemReset();
}

void early_initialization(void) {
  // Reset global critical depth
  disable_interrupts();
  global_critical_depth = 0;

  // Init register and interrupt tables
  init_registers();

  // after it's been in the bootloader, things are initted differently, so we reset
  if ((enter_bootloader_mode != BOOT_NORMAL) &&
      (enter_bootloader_mode != ENTER_BOOTLOADER_MAGIC) &&
      (enter_bootloader_mode != ENTER_SOFTLOADER_MAGIC)) {
    enter_bootloader_mode = BOOT_NORMAL;
    NVIC_SystemReset();
  }

  // if wrong chip, reboot
  volatile unsigned int id = DBGMCU->IDCODE;
  if ((id & 0xFFFU) != MCU_IDCODE) {
    enter_bootloader_mode = ENTER_BOOTLOADER_MAGIC;
  }

  // setup interrupt table
  SCB->VTOR = (uint32_t)&g_pfnVectors;

  // early GPIOs float everything
  early_gpio_float();

  detect_board_type();

  if (enter_bootloader_mode == ENTER_BOOTLOADER_MAGIC) {
    led_init();
    #ifdef PANDA
    current_board->init_bootloader();
    #endif
    led_set(LED_GREEN, 1);
    jump_to_bootloader();
  }
}
