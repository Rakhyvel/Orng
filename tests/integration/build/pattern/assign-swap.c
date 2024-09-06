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
int64_t _1223_main(void);


/* Function definitions */
int64_t _1223_main(void){
    int64_t _1223_t1;
    int64_t _1223_t2;
    struct struct0 _1223_t0;
    int64_t _1224_x;
    int64_t _1224_y;
    struct struct0 _1223_t4;
    int64_t _1223_t6;
    uint8_t _1223_t8;
    int64_t _1223_$retval;
    int64_t _1223_t9;
    uint8_t _1223_t11;
    _1223_t1 = 1;
    _1223_t2 = 2;
    _1223_t0 = (struct struct0) {_1223_t1, _1223_t2};
    _1224_x = _1223_t0._0;
    _1224_y = _1223_t0._1;
    _1223_t4 = (struct struct0) {_1224_x, _1224_y};
    _1224_y = _1223_t4._0;
    _1224_x = _1223_t4._1;
    _1223_t6 = 1;
    _1223_t8 = _1224_y==_1223_t6;
    if (_1223_t8) {
        goto BB1389;
    } else {
        goto BB1396;
    }
BB1389:
    _1223_t9 = 2;
    _1223_t11 = _1224_x==_1223_t9;
    if (_1223_t11) {
        goto BB1392;
    } else {
        goto BB1396;
    }
BB1396:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1392:
    _1223_$retval = 159;
    return _1223_$retval;
}


int main(void) {
  printf("%ld",_1223_main());
  return 0;
}
