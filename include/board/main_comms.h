#pragma once
#include <stdint.h>
#include <stdbool.h>

extern int _app_start[0xc000]; // Only first 3 sectors of size 0x4000 are used

extern void update_can_health_pkt(uint8_t can_number, uint32_t ir_reg);
void set_safety_mode(uint16_t mode, uint16_t param);
bool is_car_safety_mode(uint16_t mode);

