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
int64_t _571_main(void);
uint8_t _576_addr_equal(int64_t* _576_x,int64_t* _576_y);

/* Function definitions */
int64_t _571_main(void) {
    int64_t _572_x;
    int64_t _572_y;
    function0 _571_t4;
    int64_t* _571_t6;
    int64_t* _571_t7;
    uint8_t _571_t5;
    function0 _571_t8;
    int64_t* _571_t10;
    int64_t* _571_t11;
    uint8_t _571_t9;
    int64_t _571_t2;
    int64_t _571_$retval;
    _572_x = 4;
    _572_y = 4;
    _571_t4 = _576_addr_equal;
    _571_t6 = &_572_x;
    _571_t7 = &_572_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _571_t5 = _571_t4(_571_t6, _571_t7);
    $line_idx--;
    if (_571_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _571_t8 = _576_addr_equal;
    _571_t10 = &_572_x;
    _571_t11 = &_572_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _571_t9 = _571_t8(_571_t10, _571_t11);
    $line_idx--;
    if (_571_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _571_t2 = -3;
    goto BB6;
BB3:
    _571_t2 = 236;
    goto BB6;
BB6:
    _571_$retval = _571_t2;
    return _571_$retval;
}

uint8_t _576_addr_equal(int64_t* _576_x,int64_t* _576_y) {
    uint8_t _576_t1;
    uint8_t _576_t0;
    uint8_t _576_$retval;
    _576_t1 = _576_x == _576_y;
    if (_576_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _576_t0 = 1;
    goto BB3;
BB4:
    _576_t0 = 0;
    goto BB3;
BB3:
    _576_$retval = _576_t0;
    return _576_$retval;
}

int main(void) {
  printf("%ld",_571_main());
  return 0;
}
