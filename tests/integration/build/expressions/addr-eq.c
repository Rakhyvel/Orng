/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
uint8_t _6_addr_equal(int64_t* _6_x,int64_t* _6_y);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _2_x;
    int64_t _2_y;
    int64_t* _1_t5;
    int64_t* _1_t6;
    uint8_t _1_t4;
    int64_t* _1_t8;
    int64_t* _1_t9;
    uint8_t _1_t7;
    int64_t _1_t2;
    int64_t _1_$retval;
    _2_x = 4;
    _2_y = 4;
    _1_t5 = &_2_x;
    _1_t6 = &_2_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _1_t4 = _6_addr_equal(_1_t5, _1_t6);
    $line_idx--;
    if (_1_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _1_t8 = &_2_x;
    _1_t9 = &_2_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _1_t7 = _6_addr_equal(_1_t8, _1_t9);
    $line_idx--;
    if (_1_t7) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _1_t2 = -3;
    goto BB6;
BB3:
    _1_t2 = 236;
BB6:
    _1_$retval = _1_t2;
    return _1_$retval;
}

uint8_t _6_addr_equal(int64_t* _6_x,int64_t* _6_y) {
    uint8_t _6_t0;
    uint8_t _6_$retval;
    if (_6_x == _6_y) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _6_t0 = 1;
    goto BB3;
BB4:
    _6_t0 = 0;
BB3:
    _6_$retval = _6_t0;
    return _6_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
