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
int64_t _637_main(void);
uint8_t _642_addr_equal(int64_t* _642_x, int64_t* _642_y);


/* Function definitions */
int64_t _637_main(void){
    int64_t _638_x;
    int64_t _638_y;
    function0 _637_t5;
    int64_t* _637_t7;
    int64_t* _637_t8;
    uint8_t _637_t6;
    function0 _637_t9;
    int64_t* _637_t11;
    int64_t* _637_t12;
    uint8_t _637_t10;
    int64_t _637_t4;
    int64_t _637_$retval;
    _638_x = 4;
    _638_y = 4;
    _637_t5 = (function0) _642_addr_equal;
    _637_t7 = &_638_x;
    _637_t8 = &_638_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _637_t6 = _637_t5(_637_t7, _637_t8);
    $line_idx--;
    if (_637_t6) {
        goto BB751;
    } else {
        goto BB756;
    }
BB751:
    _637_t9 = (function0) _642_addr_equal;
    _637_t11 = &_638_x;
    _637_t12 = &_638_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _637_t10 = _637_t9(_637_t11, _637_t12);
    $line_idx--;
    if (_637_t10) {
        goto BB756;
    } else {
        goto BB752;
    }
BB756:
    _637_t4 = -3;
    goto BB755;
BB752:
    _637_t4 = 236;
    goto BB755;
BB755:
    _637_$retval = _637_t4;
    return _637_$retval;
}

uint8_t _642_addr_equal(int64_t* _642_x, int64_t* _642_y){
    uint8_t _642_t1;
    uint8_t _642_t0;
    uint8_t _642_$retval;
    _642_t1 = _642_x==_642_y;
    if (_642_t1) {
        goto BB746;
    } else {
        goto BB749;
    }
BB746:
    _642_t0 = 1;
    goto BB748;
BB749:
    _642_t0 = 0;
    goto BB748;
BB748:
    _642_$retval = _642_t0;
    return _642_$retval;
}


int main(void) {
  printf("%ld",_637_main());
  return 0;
}
