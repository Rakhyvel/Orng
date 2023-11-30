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
int64_t _546_main(void);
uint8_t _551_addr_equal(int64_t* _551_x,int64_t* _551_y);

/* Function definitions */
int64_t _546_main(void) {
    int64_t _547_x;
    int64_t _547_y;
    function0 _546_t4;
    int64_t* _546_t6;
    int64_t* _546_t7;
    uint8_t _546_t5;
    function0 _546_t8;
    int64_t* _546_t10;
    int64_t* _546_t11;
    uint8_t _546_t9;
    int64_t _546_t2;
    int64_t _546_$retval;
    _547_x = 4;
    _547_y = 4;
    _546_t4 = _551_addr_equal;
    _546_t6 = &_547_x;
    _546_t7 = &_547_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _546_t5 = _546_t4(_546_t6, _546_t7);
    $line_idx--;
    if (_546_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _546_t8 = _551_addr_equal;
    _546_t10 = &_547_x;
    _546_t11 = &_547_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _546_t9 = _546_t8(_546_t10, _546_t11);
    $line_idx--;
    if (_546_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _546_t2 = -3;
    goto BB6;
BB3:
    _546_t2 = 236;
    goto BB6;
BB6:
    _546_$retval = _546_t2;
    return _546_$retval;
}

uint8_t _551_addr_equal(int64_t* _551_x,int64_t* _551_y) {
    uint8_t _551_t1;
    uint8_t _551_t0;
    uint8_t _551_$retval;
    _551_t1 = _551_x == _551_y;
    if (_551_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _551_t0 = 1;
    goto BB3;
BB4:
    _551_t0 = 0;
    goto BB3;
BB3:
    _551_$retval = _551_t0;
    return _551_$retval;
}

int main(void) {
  printf("%ld",_546_main());
  return 0;
}
