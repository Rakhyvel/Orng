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
int64_t _666_main(void);
uint8_t _671_addr_equal(int64_t* _671_x, int64_t* _671_y);


/* Function definitions */
int64_t _666_main(void){
    int64_t _667_x;
    int64_t _667_y;
    function0 _666_t3;
    int64_t* _666_t5;
    int64_t* _666_t6;
    uint8_t _666_t4;
    function0 _666_t7;
    int64_t* _666_t9;
    int64_t* _666_t10;
    uint8_t _666_t8;
    int64_t _666_t2;
    int64_t _666_$retval;
    _667_x = 4;
    _667_y = 4;
    _666_t3 = (function0) _671_addr_equal;
    _666_t5 = &_667_x;
    _666_t6 = &_667_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _666_t4 = _666_t3(_666_t5, _666_t6);
    $line_idx--;
    if (_666_t4) {
        goto BB808;
    } else {
        goto BB813;
    }
BB808:
    _666_t7 = (function0) _671_addr_equal;
    _666_t9 = &_667_x;
    _666_t10 = &_667_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _666_t8 = _666_t7(_666_t9, _666_t10);
    $line_idx--;
    if (_666_t8) {
        goto BB813;
    } else {
        goto BB809;
    }
BB813:
    _666_t2 = -3;
    goto BB812;
BB809:
    _666_t2 = 236;
    goto BB812;
BB812:
    _666_$retval = _666_t2;
    return _666_$retval;
}

uint8_t _671_addr_equal(int64_t* _671_x, int64_t* _671_y){
    uint8_t _671_t1;
    uint8_t _671_t0;
    uint8_t _671_$retval;
    _671_t1 = _671_x==_671_y;
    if (_671_t1) {
        goto BB803;
    } else {
        goto BB806;
    }
BB803:
    _671_t0 = 1;
    goto BB805;
BB806:
    _671_t0 = 0;
    goto BB805;
BB805:
    _671_$retval = _671_t0;
    return _671_$retval;
}


int main(void) {
  printf("%ld",_666_main());
  return 0;
}
