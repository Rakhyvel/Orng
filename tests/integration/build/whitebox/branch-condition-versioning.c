/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1694154712892655626
#define ORNG_1694154712892655626

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
    uint8_t _3_found;
    int64_t _4_n;
    int64_t _2_t4;
    uint8_t _2_t3;
    int64_t _2_t9;
    uint8_t _2_t8;
    int64_t _2_t11;
    int64_t _2_t13;
    int64_t _2_$retval;
BB0:
    _3_found = 0;
    _4_n = 0;
    goto BB1;
BB1:
    _2_t4 = 10;
    _2_t3 = _4_n < _2_t4;
    if (_2_t3) {
        goto BB2;
    } else {
        goto BB26;
    }
BB26:
    if (_3_found) {
        goto BB20;
    } else {
        goto BB24;
    }
BB24:
    _2_t13 = 4;
    goto BB23;
BB23:
    _2_$retval = _2_t13;
    return _2_$retval;
BB20:
    _2_t13 = 15;
    goto BB23;
BB2:
    if (_3_found) {
        goto BB5;
    } else {
        goto BB7;
    }
BB7:
    _2_t9 = 6;
    _2_t8 = _4_n == _2_t9;
    if (_2_t8) {
        goto BB8;
    } else {
        goto BB13;
    }
BB13:
    _2_t11 = 1;
    _4_n = _4_n + _2_t11;
    goto BB1;
BB8:
    _3_found = 1;
    goto BB13;
BB5:
    _4_n = 100;
    goto BB7;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
