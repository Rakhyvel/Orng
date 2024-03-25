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
int64_t _1160_main(void);


/* Function definitions */
int64_t _1160_main(void){
    int64_t _1160_t1;
    int64_t _1160_t2;
    struct struct0 _1160_t0;
    int64_t _1161_x;
    int64_t _1161_y;
    struct struct0 _1160_t4;
    int64_t _1160_t6;
    uint8_t _1160_t8;
    int64_t _1160_$retval;
    int64_t _1160_t9;
    uint8_t _1160_t11;
    _1160_t1 = 1;
    _1160_t2 = 2;
    _1160_t0 = (struct struct0) {_1160_t1, _1160_t2};
    _1161_x = _1160_t0._0;
    _1161_y = _1160_t0._1;
    _1160_t4 = (struct struct0) {_1161_x, _1161_y};
    _1161_y = _1160_t4._0;
    _1161_x = _1160_t4._1;
    _1160_t6 = 1;
    _1160_t8 = _1161_y==_1160_t6;
    if (_1160_t8) {
        goto BB1320;
    } else {
        goto BB1327;
    }
BB1320:
    _1160_t9 = 2;
    _1160_t11 = _1161_x==_1160_t9;
    if (_1160_t11) {
        goto BB1323;
    } else {
        goto BB1327;
    }
BB1327:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1323:
    _1160_$retval = 159;
    return _1160_$retval;
}


int main(void) {
  printf("%ld",_1160_main());
  return 0;
}
