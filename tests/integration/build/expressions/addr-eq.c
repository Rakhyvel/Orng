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
int64_t _590_main(void);
uint8_t _595_addr_equal(int64_t* _595_x,int64_t* _595_y);

/* Function definitions */
int64_t _590_main(void){
    int64_t _591_x;
    int64_t _591_y;
    function0 _590_t4;
    int64_t* _590_t6;
    int64_t* _590_t7;
    uint8_t _590_t5;
    function0 _590_t8;
    int64_t* _590_t10;
    int64_t* _590_t11;
    uint8_t _590_t9;
    int64_t _590_t2;
    int64_t _590_$retval;
    _591_x = 4;
    _591_y = 4;
    _590_t4 = _595_addr_equal;
    _590_t6 = &_591_x;
    _590_t7 = &_591_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _590_t5 = _590_t4(_590_t6, _590_t7);
    $line_idx--;
    if (_590_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _590_t8 = _595_addr_equal;
    _590_t10 = &_591_x;
    _590_t11 = &_591_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _590_t9 = _590_t8(_590_t10, _590_t11);
    $line_idx--;
    if (_590_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _590_t2 = -3;
    goto BB6;
BB3:
    _590_t2 = 236;
    goto BB6;
BB6:
    _590_$retval = _590_t2;
    return _590_$retval;
}

uint8_t _595_addr_equal(int64_t* _595_x,int64_t* _595_y){
    uint8_t _595_t1;
    uint8_t _595_t0;
    uint8_t _595_$retval;
    _595_t1 = _595_x == _595_y;
    if (_595_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _595_t0 = 1;
    goto BB3;
BB4:
    _595_t0 = 0;
    goto BB3;
BB3:
    _595_$retval = _595_t0;
    return _595_$retval;
}

int main(void) {
  printf("%ld",_590_main());
  return 0;
}
