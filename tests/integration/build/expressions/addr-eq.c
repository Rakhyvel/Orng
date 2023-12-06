/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t* _1;
} struct1;

typedef uint8_t(*function0)(int64_t*, int64_t*);

/* Function forward definitions */
int64_t _16_main(void);
uint8_t _21_addr_equal(int64_t* _21_x,int64_t* _21_y);

/* Function definitions */
int64_t _16_main(void) {
    int64_t _17_x;
    int64_t _17_y;
    function0 _16_t4;
    int64_t* _16_t6;
    int64_t* _16_t7;
    uint8_t _16_t5;
    function0 _16_t8;
    int64_t* _16_t10;
    int64_t* _16_t11;
    uint8_t _16_t9;
    int64_t _16_t2;
    int64_t _16_$retval;
    _17_x = 4;
    _17_y = 4;
    _16_t4 = _21_addr_equal;
    _16_t6 = &_17_x;
    _16_t7 = &_17_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _16_t5 = _16_t4(_16_t6, _16_t7);
    $line_idx--;
    if (_16_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _16_t8 = _21_addr_equal;
    _16_t10 = &_17_x;
    _16_t11 = &_17_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _16_t9 = _16_t8(_16_t10, _16_t11);
    $line_idx--;
    if (_16_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _16_t2 = -3;
    goto BB6;
BB3:
    _16_t2 = 236;
    goto BB6;
BB6:
    _16_$retval = _16_t2;
    return _16_$retval;
}

uint8_t _21_addr_equal(int64_t* _21_x,int64_t* _21_y) {
    uint8_t _21_t1;
    uint8_t _21_t0;
    uint8_t _21_$retval;
    _21_t1 = _21_x == _21_y;
    if (_21_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _21_t0 = 1;
    goto BB3;
BB4:
    _21_t0 = 0;
    goto BB3;
BB3:
    _21_$retval = _21_t0;
    return _21_$retval;
}

int main(void) {
  printf("%ld",_16_main());
  return 0;
}
