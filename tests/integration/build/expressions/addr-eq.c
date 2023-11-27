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
int64_t _352_main(void);
uint8_t _357_addr_equal(int64_t* _357_x,int64_t* _357_y);

/* Function definitions */
int64_t _352_main(void) {
    int64_t _353_x;
    int64_t _353_y;
    function0 _352_t4;
    int64_t* _352_t6;
    int64_t* _352_t7;
    uint8_t _352_t5;
    function0 _352_t8;
    int64_t* _352_t10;
    int64_t* _352_t11;
    uint8_t _352_t9;
    int64_t _352_t2;
    int64_t _352_$retval;
    _353_x = 4;
    _353_y = 4;
    _352_t4 = _357_addr_equal;
    _352_t6 = &_353_x;
    _352_t7 = &_353_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _352_t5 = _352_t4(_352_t6, _352_t7);
    $line_idx--;
    if (_352_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _352_t8 = _357_addr_equal;
    _352_t10 = &_353_x;
    _352_t11 = &_353_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _352_t9 = _352_t8(_352_t10, _352_t11);
    $line_idx--;
    if (_352_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _352_t2 = -3;
    goto BB6;
BB3:
    _352_t2 = 236;
    goto BB6;
BB6:
    _352_$retval = _352_t2;
    return _352_$retval;
}

uint8_t _357_addr_equal(int64_t* _357_x,int64_t* _357_y) {
    uint8_t _357_t1;
    uint8_t _357_t0;
    uint8_t _357_$retval;
    _357_t1 = _357_x == _357_y;
    if (_357_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _357_t0 = 1;
    goto BB3;
BB4:
    _357_t0 = 0;
    goto BB3;
BB3:
    _357_$retval = _357_t0;
    return _357_$retval;
}

int main(void) {
  printf("%ld",_352_main());
  return 0;
}
