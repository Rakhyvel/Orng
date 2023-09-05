/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681449729182
#define ORNG_1691899681449729182

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _3_x;
    int64_t _4_i;
    int64_t _2_t4;
    uint8_t _2_t3;
    int64_t _2_t6;
    int64_t _2_$retval;
BB0:
    _3_x = 0;
    _4_i = 0;
    goto BB1;
BB1:
    _2_t4 = 10;
    _2_t3 = _4_i <= _2_t4;
    if (_2_t3) {
        goto BB2;
    } else {
        goto BB10;
    }
BB10:
    _2_$retval = _3_x;
    return _2_$retval;
BB2:
    _3_x = _3_x + _4_i;
    _2_t6 = 1;
    _4_i = _4_i + _2_t6;
    goto BB1;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
