/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t* _0;
    int64_t* _1;
};

typedef uint8_t(*function0)(int64_t*, int64_t*);

/* Function forward definitions */
int64_t _640_main(void);
uint8_t _645_addr_equal(int64_t* _645_x, int64_t* _645_y);


/* Function definitions */
int64_t _640_main(void){
    int64_t _641_x;
    int64_t _641_y;
    function0 _640_t5;
    int64_t* _640_t7;
    int64_t* _640_t8;
    uint8_t _640_t6;
    function0 _640_t9;
    int64_t* _640_t11;
    int64_t* _640_t12;
    uint8_t _640_t10;
    int64_t _640_t4;
    int64_t _640_$retval;
    _641_x = 4;
    _641_y = 4;
    _640_t5 = (function0) _645_addr_equal;
    _640_t7 = &_641_x;
    _640_t8 = &_641_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _640_t6 = _640_t5(_640_t7, _640_t8);
    $line_idx--;
    if (_640_t6) {
        goto BB754;
    } else {
        goto BB759;
    }
BB754:
    _640_t9 = (function0) _645_addr_equal;
    _640_t11 = &_641_x;
    _640_t12 = &_641_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _640_t10 = _640_t9(_640_t11, _640_t12);
    $line_idx--;
    if (_640_t10) {
        goto BB759;
    } else {
        goto BB755;
    }
BB759:
    _640_t4 = -3;
    goto BB758;
BB755:
    _640_t4 = 236;
    goto BB758;
BB758:
    _640_$retval = _640_t4;
    return _640_$retval;
}

uint8_t _645_addr_equal(int64_t* _645_x, int64_t* _645_y){
    uint8_t _645_t1;
    uint8_t _645_t0;
    uint8_t _645_$retval;
    _645_t1 = _645_x==_645_y;
    if (_645_t1) {
        goto BB749;
    } else {
        goto BB752;
    }
BB749:
    _645_t0 = 1;
    goto BB751;
BB752:
    _645_t0 = 0;
    goto BB751;
BB751:
    _645_$retval = _645_t0;
    return _645_$retval;
}


int main(void) {
  printf("%ld",_640_main());
  return 0;
}
