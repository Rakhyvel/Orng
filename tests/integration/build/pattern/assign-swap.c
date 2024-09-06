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
int64_t _1218_main(void);


/* Function definitions */
int64_t _1218_main(void){
    int64_t _1218_t1;
    int64_t _1218_t2;
    struct struct0 _1218_t0;
    int64_t _1219_x;
    int64_t _1219_y;
    struct struct0 _1218_t4;
    int64_t _1218_t6;
    uint8_t _1218_t8;
    int64_t _1218_$retval;
    int64_t _1218_t9;
    uint8_t _1218_t11;
    _1218_t1 = 1;
    _1218_t2 = 2;
    _1218_t0 = (struct struct0) {_1218_t1, _1218_t2};
    _1219_x = _1218_t0._0;
    _1219_y = _1218_t0._1;
    _1218_t4 = (struct struct0) {_1219_x, _1219_y};
    _1219_y = _1218_t4._0;
    _1219_x = _1218_t4._1;
    _1218_t6 = 1;
    _1218_t8 = _1219_y==_1218_t6;
    if (_1218_t8) {
        goto BB1385;
    } else {
        goto BB1392;
    }
BB1385:
    _1218_t9 = 2;
    _1218_t11 = _1219_x==_1218_t9;
    if (_1218_t11) {
        goto BB1388;
    } else {
        goto BB1392;
    }
BB1392:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1388:
    _1218_$retval = 159;
    return _1218_$retval;
}


int main(void) {
  printf("%ld",_1218_main());
  return 0;
}
