#pragma once
#include <stdbool.h>
#include <stdint.h>

// ******************** Prototypes ********************
extern void print(const char *a);
extern void puth(unsigned int i);
extern void puth4(unsigned int i);
extern void hexdump(const void *a, int l);
typedef struct board board;
typedef struct harness_configuration harness_configuration;

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
