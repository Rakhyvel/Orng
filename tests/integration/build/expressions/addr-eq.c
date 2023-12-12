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
int64_t _393_main(void);
uint8_t _398_addr_equal(int64_t* _398_x,int64_t* _398_y);

/* Function definitions */
int64_t _393_main(void) {
    int64_t _394_x;
    int64_t _394_y;
    function0 _393_t4;
    int64_t* _393_t6;
    int64_t* _393_t7;
    uint8_t _393_t5;
    function0 _393_t8;
    int64_t* _393_t10;
    int64_t* _393_t11;
    uint8_t _393_t9;
    int64_t _393_t2;
    int64_t _393_$retval;
    _394_x = 4;
    _394_y = 4;
    _393_t4 = _398_addr_equal;
    _393_t6 = &_394_x;
    _393_t7 = &_394_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _393_t5 = _393_t4(_393_t6, _393_t7);
    $line_idx--;
    if (_393_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _393_t8 = _398_addr_equal;
    _393_t10 = &_394_x;
    _393_t11 = &_394_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _393_t9 = _393_t8(_393_t10, _393_t11);
    $line_idx--;
    if (_393_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _393_t2 = -3;
    goto BB6;
BB3:
    _393_t2 = 236;
    goto BB6;
BB6:
    _393_$retval = _393_t2;
    return _393_$retval;
}

uint8_t _398_addr_equal(int64_t* _398_x,int64_t* _398_y) {
    uint8_t _398_t1;
    uint8_t _398_t0;
    uint8_t _398_$retval;
    _398_t1 = _398_x == _398_y;
    if (_398_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _398_t0 = 1;
    goto BB3;
BB4:
    _398_t0 = 0;
    goto BB3;
BB3:
    _398_$retval = _398_t0;
    return _398_$retval;
}

int main(void) {
  printf("%ld",_393_main());
  return 0;
}
