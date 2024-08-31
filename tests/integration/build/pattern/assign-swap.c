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
int64_t _1165_main(void);


/* Function definitions */
int64_t _1165_main(void){
    int64_t _1165_t1;
    int64_t _1165_t2;
    struct struct0 _1165_t0;
    int64_t _1166_x;
    int64_t _1166_y;
    struct struct0 _1165_t4;
    int64_t _1165_t6;
    uint8_t _1165_t8;
    int64_t _1165_$retval;
    int64_t _1165_t9;
    uint8_t _1165_t11;
    _1165_t1 = 1;
    _1165_t2 = 2;
    _1165_t0 = (struct struct0) {_1165_t1, _1165_t2};
    _1166_x = _1165_t0._0;
    _1166_y = _1165_t0._1;
    _1165_t4 = (struct struct0) {_1166_x, _1166_y};
    _1166_y = _1165_t4._0;
    _1166_x = _1165_t4._1;
    _1165_t6 = 1;
    _1165_t8 = _1166_y==_1165_t6;
    if (_1165_t8) {
        goto BB1324;
    } else {
        goto BB1331;
    }
BB1324:
    _1165_t9 = 2;
    _1165_t11 = _1166_x==_1165_t9;
    if (_1165_t11) {
        goto BB1327;
    } else {
        goto BB1331;
    }
BB1331:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1327:
    _1165_$retval = 159;
    return _1165_$retval;
}


int main(void) {
  printf("%ld",_1165_main());
  return 0;
}
