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
int64_t _632_main(void);
uint8_t _637_addr_equal(int64_t* _637_x, int64_t* _637_y);


/* Function definitions */
int64_t _632_main(void){
    int64_t _633_x;
    int64_t _633_y;
    function0 _632_t5;
    int64_t* _632_t7;
    int64_t* _632_t8;
    uint8_t _632_t6;
    function0 _632_t9;
    int64_t* _632_t11;
    int64_t* _632_t12;
    uint8_t _632_t10;
    int64_t _632_t4;
    int64_t _632_$retval;
    _633_x = 4;
    _633_y = 4;
    _632_t5 = (function0) _637_addr_equal;
    _632_t7 = &_633_x;
    _632_t8 = &_633_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _632_t6 = _632_t5(_632_t7, _632_t8);
    $line_idx--;
    if (_632_t6) {
        goto BB748;
    } else {
        goto BB753;
    }
BB748:
    _632_t9 = (function0) _637_addr_equal;
    _632_t11 = &_633_x;
    _632_t12 = &_633_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _632_t10 = _632_t9(_632_t11, _632_t12);
    $line_idx--;
    if (_632_t10) {
        goto BB753;
    } else {
        goto BB749;
    }
BB753:
    _632_t4 = -3;
    goto BB752;
BB749:
    _632_t4 = 236;
    goto BB752;
BB752:
    _632_$retval = _632_t4;
    return _632_$retval;
}

uint8_t _637_addr_equal(int64_t* _637_x, int64_t* _637_y){
    uint8_t _637_t1;
    uint8_t _637_t0;
    uint8_t _637_$retval;
    _637_t1 = _637_x==_637_y;
    if (_637_t1) {
        goto BB743;
    } else {
        goto BB746;
    }
BB743:
    _637_t0 = 1;
    goto BB745;
BB746:
    _637_t0 = 0;
    goto BB745;
BB745:
    _637_$retval = _637_t0;
    return _637_$retval;
}


int main(void) {
  printf("%ld",_632_main());
  return 0;
}
