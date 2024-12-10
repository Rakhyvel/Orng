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
int64_t _652_main(void);
uint8_t _657_addr_equal(int64_t* _657_x, int64_t* _657_y);


/* Function definitions */
int64_t _652_main(void){
    int64_t _653_x;
    int64_t _653_y;
    function0 _652_t5;
    int64_t* _652_t7;
    int64_t* _652_t8;
    uint8_t _652_t6;
    function0 _652_t9;
    int64_t* _652_t11;
    int64_t* _652_t12;
    uint8_t _652_t10;
    int64_t _652_t4;
    int64_t _652_$retval;
    _653_x = 4;
    _653_y = 4;
    _652_t5 = (function0) _657_addr_equal;
    _652_t7 = &_653_x;
    _652_t8 = &_653_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _652_t6 = _652_t5(_652_t7, _652_t8);
    $line_idx--;
    if (_652_t6) {
        goto BB767;
    } else {
        goto BB772;
    }
BB767:
    _652_t9 = (function0) _657_addr_equal;
    _652_t11 = &_653_x;
    _652_t12 = &_653_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _652_t10 = _652_t9(_652_t11, _652_t12);
    $line_idx--;
    if (_652_t10) {
        goto BB772;
    } else {
        goto BB768;
    }
BB772:
    _652_t4 = -3;
    goto BB771;
BB768:
    _652_t4 = 236;
    goto BB771;
BB771:
    _652_$retval = _652_t4;
    return _652_$retval;
}

uint8_t _657_addr_equal(int64_t* _657_x, int64_t* _657_y){
    uint8_t _657_t1;
    uint8_t _657_t0;
    uint8_t _657_$retval;
    _657_t1 = _657_x==_657_y;
    if (_657_t1) {
        goto BB762;
    } else {
        goto BB765;
    }
BB762:
    _657_t0 = 1;
    goto BB764;
BB765:
    _657_t0 = 0;
    goto BB764;
BB764:
    _657_$retval = _657_t0;
    return _657_$retval;
}


int main(void) {
  printf("%ld",_652_main());
  return 0;
}
