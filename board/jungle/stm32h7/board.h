<<<<<<< HEAD
#include "boards/board_declarations.h"

#include "stm32h7/lladc.h"
#include "boards/board_v2.h"

void detect_board_type(void) {
=======
#pragma once
#include "jungle/boards/board.h"
#include "jungle/stm32h7/lladc.h"
#include "jungle/boards/board_v2.h"

extern uint8_t hw_type;
extern struct board *current_board;
extern struct board board_v2;

static inline void detect_board_type(void) {
>>>>>>> 98e26738 (adopt source/header model)
  hw_type = HW_TYPE_V2;
  current_board = &board_v2;
}
