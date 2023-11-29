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
int64_t _424_main(void);
uint8_t _429_addr_equal(int64_t* _429_x,int64_t* _429_y);

/* Function definitions */
int64_t _424_main(void) {
    int64_t _425_x;
    int64_t _425_y;
    function0 _424_t4;
    int64_t* _424_t6;
    int64_t* _424_t7;
    uint8_t _424_t5;
    function0 _424_t8;
    int64_t* _424_t10;
    int64_t* _424_t11;
    uint8_t _424_t9;
    int64_t _424_t2;
    int64_t _424_$retval;
    _425_x = 4;
    _425_y = 4;
    _424_t4 = _429_addr_equal;
    _424_t6 = &_425_x;
    _424_t7 = &_425_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _424_t5 = _424_t4(_424_t6, _424_t7);
    $line_idx--;
    if (_424_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _424_t8 = _429_addr_equal;
    _424_t10 = &_425_x;
    _424_t11 = &_425_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _424_t9 = _424_t8(_424_t10, _424_t11);
    $line_idx--;
    if (_424_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _424_t2 = -3;
    goto BB6;
BB3:
    _424_t2 = 236;
    goto BB6;
BB6:
    _424_$retval = _424_t2;
    return _424_$retval;
}

uint8_t _429_addr_equal(int64_t* _429_x,int64_t* _429_y) {
    uint8_t _429_t1;
    uint8_t _429_t0;
    uint8_t _429_$retval;
    _429_t1 = _429_x == _429_y;
    if (_429_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _429_t0 = 1;
    goto BB3;
BB4:
    _429_t0 = 0;
    goto BB3;
BB3:
    _429_$retval = _429_t0;
    return _429_$retval;
}

int main(void) {
  printf("%ld",_424_main());
  return 0;
}
