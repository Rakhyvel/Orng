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
int64_t _1237_main(void);


/* Function definitions */
int64_t _1237_main(void){
    int64_t _1237_t1;
    int64_t _1237_t2;
    struct struct0 _1237_t0;
    int64_t _1238_x;
    int64_t _1238_y;
    struct struct0 _1237_t4;
    int64_t _1237_t6;
    uint8_t _1237_t8;
    int64_t _1237_$retval;
    int64_t _1237_t9;
    uint8_t _1237_t11;
    _1237_t1 = 1;
    _1237_t2 = 2;
    _1237_t0 = (struct struct0) {_1237_t1, _1237_t2};
    _1238_x = _1237_t0._0;
    _1238_y = _1237_t0._1;
    _1237_t4 = (struct struct0) {_1238_x, _1238_y};
    _1238_y = _1237_t4._0;
    _1238_x = _1237_t4._1;
    _1237_t6 = 1;
    _1237_t8 = _1238_y==_1237_t6;
    if (_1237_t8) {
        goto BB1408;
    } else {
        goto BB1415;
    }
BB1408:
    _1237_t9 = 2;
    _1237_t11 = _1238_x==_1237_t9;
    if (_1237_t11) {
        goto BB1411;
    } else {
        goto BB1415;
    }
BB1415:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1411:
    _1237_$retval = 159;
    return _1237_$retval;
}


int main(void) {
  printf("%ld",_1237_main());
  return 0;
}
