// minimal code to fake a panda for tests
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "opendbc/safety/board/fake_stm.h"

#define CANFD

#define ENTER_CRITICAL() 0
#define EXIT_CRITICAL() 0

typedef uint32_t GPIO_TypeDef;
