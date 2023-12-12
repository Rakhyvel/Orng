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
int64_t _412_main(void);
uint8_t _417_addr_equal(int64_t* _417_x,int64_t* _417_y);

/* Function definitions */
int64_t _412_main(void) {
    int64_t _413_x;
    int64_t _413_y;
    function0 _412_t4;
    int64_t* _412_t6;
    int64_t* _412_t7;
    uint8_t _412_t5;
    function0 _412_t8;
    int64_t* _412_t10;
    int64_t* _412_t11;
    uint8_t _412_t9;
    int64_t _412_t2;
    int64_t _412_$retval;
    _413_x = 4;
    _413_y = 4;
    _412_t4 = _417_addr_equal;
    _412_t6 = &_413_x;
    _412_t7 = &_413_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _412_t5 = _412_t4(_412_t6, _412_t7);
    $line_idx--;
    if (_412_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _412_t8 = _417_addr_equal;
    _412_t10 = &_413_x;
    _412_t11 = &_413_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _412_t9 = _412_t8(_412_t10, _412_t11);
    $line_idx--;
    if (_412_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _412_t2 = -3;
    goto BB6;
BB3:
    _412_t2 = 236;
    goto BB6;
BB6:
    _412_$retval = _412_t2;
    return _412_$retval;
}

uint8_t _417_addr_equal(int64_t* _417_x,int64_t* _417_y) {
    uint8_t _417_t1;
    uint8_t _417_t0;
    uint8_t _417_$retval;
    _417_t1 = _417_x == _417_y;
    if (_417_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _417_t0 = 1;
    goto BB3;
BB4:
    _417_t0 = 0;
    goto BB3;
BB3:
    _417_$retval = _417_t0;
    return _417_$retval;
}

int main(void) {
  printf("%ld",_412_main());
  return 0;
}
