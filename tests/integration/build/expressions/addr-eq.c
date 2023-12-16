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
int64_t _579_main(void);
uint8_t _584_addr_equal(int64_t* _584_x,int64_t* _584_y);

/* Function definitions */
int64_t _579_main(void){
    int64_t _580_x;
    int64_t _580_y;
    function0 _579_t4;
    int64_t* _579_t6;
    int64_t* _579_t7;
    uint8_t _579_t5;
    function0 _579_t8;
    int64_t* _579_t10;
    int64_t* _579_t11;
    uint8_t _579_t9;
    int64_t _579_t2;
    int64_t _579_$retval;
    _580_x = 4;
    _580_y = 4;
    _579_t4 = _584_addr_equal;
    _579_t6 = &_580_x;
    _579_t7 = &_580_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _579_t5 = _579_t4(_579_t6, _579_t7);
    $line_idx--;
    if (_579_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _579_t8 = _584_addr_equal;
    _579_t10 = &_580_x;
    _579_t11 = &_580_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _579_t9 = _579_t8(_579_t10, _579_t11);
    $line_idx--;
    if (_579_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _579_t2 = -3;
    goto BB6;
BB3:
    _579_t2 = 236;
    goto BB6;
BB6:
    _579_$retval = _579_t2;
    return _579_$retval;
}

uint8_t _584_addr_equal(int64_t* _584_x,int64_t* _584_y){
    uint8_t _584_t1;
    uint8_t _584_t0;
    uint8_t _584_$retval;
    _584_t1 = _584_x == _584_y;
    if (_584_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _584_t0 = 1;
    goto BB3;
BB4:
    _584_t0 = 0;
    goto BB3;
BB3:
    _584_$retval = _584_t0;
    return _584_$retval;
}

int main(void) {
  printf("%ld",_579_main());
  return 0;
}
