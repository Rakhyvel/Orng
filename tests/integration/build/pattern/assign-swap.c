/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1151_main(void);


/* Function definitions */
int64_t _1151_main(void){
    int64_t _1151_t1;
    int64_t _1151_t2;
    struct struct0 _1151_t0;
    int64_t _1152_x;
    int64_t _1152_y;
    struct struct0 _1151_t4;
    int64_t _1151_t6;
    uint8_t _1151_t8;
    int64_t _1151_$retval;
    int64_t _1151_t9;
    uint8_t _1151_t11;
    _1151_t1 = 1;
    _1151_t2 = 2;
    _1151_t0 = (struct struct0) {_1151_t1, _1151_t2};
    _1152_x = _1151_t0._0;
    _1152_y = _1151_t0._1;
    _1151_t4 = (struct struct0) {_1152_x, _1152_y};
    _1152_y = _1151_t4._0;
    _1152_x = _1151_t4._1;
    _1151_t6 = 1;
    _1151_t8 = _1152_y==_1151_t6;
    if (_1151_t8) {
        goto BB1314;
    } else {
        goto BB1321;
    }
BB1314:
    _1151_t9 = 2;
    _1151_t11 = _1152_x==_1151_t9;
    if (_1151_t11) {
        goto BB1317;
    } else {
        goto BB1321;
    }
BB1321:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1317:
    _1151_$retval = 159;
    return _1151_$retval;
}


int main(void) {
  printf("%ld",_1151_main());
  return 0;
}
