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
int64_t _1242_main(void);


/* Function definitions */
int64_t _1242_main(void){
    int64_t _1242_t1;
    int64_t _1242_t2;
    struct struct0 _1242_t0;
    int64_t _1243_x;
    int64_t _1243_y;
    struct struct0 _1242_t4;
    int64_t _1242_t6;
    uint8_t _1242_t8;
    int64_t _1242_$retval;
    int64_t _1242_t9;
    uint8_t _1242_t11;
    _1242_t1 = 1;
    _1242_t2 = 2;
    _1242_t0 = (struct struct0) {_1242_t1, _1242_t2};
    _1243_x = _1242_t0._0;
    _1243_y = _1242_t0._1;
    _1242_t4 = (struct struct0) {_1243_x, _1243_y};
    _1243_y = _1242_t4._0;
    _1243_x = _1242_t4._1;
    _1242_t6 = 1;
    _1242_t8 = _1243_y==_1242_t6;
    if (_1242_t8) {
        goto BB1411;
    } else {
        goto BB1418;
    }
BB1411:
    _1242_t9 = 2;
    _1242_t11 = _1243_x==_1242_t9;
    if (_1242_t11) {
        goto BB1414;
    } else {
        goto BB1418;
    }
BB1418:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1414:
    _1242_$retval = 159;
    return _1242_$retval;
}


int main(void) {
  printf("%ld",_1242_main());
  return 0;
}
