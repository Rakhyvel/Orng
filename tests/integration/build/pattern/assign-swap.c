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
int64_t _1229_main(void);


/* Function definitions */
int64_t _1229_main(void){
    int64_t _1229_t1;
    int64_t _1229_t2;
    struct struct0 _1229_t0;
    int64_t _1230_x;
    int64_t _1230_y;
    struct struct0 _1229_t4;
    int64_t _1229_t6;
    uint8_t _1229_t8;
    int64_t _1229_$retval;
    int64_t _1229_t9;
    uint8_t _1229_t11;
    _1229_t1 = 1;
    _1229_t2 = 2;
    _1229_t0 = (struct struct0) {_1229_t1, _1229_t2};
    _1230_x = _1229_t0._0;
    _1230_y = _1229_t0._1;
    _1229_t4 = (struct struct0) {_1230_x, _1230_y};
    _1230_y = _1229_t4._0;
    _1230_x = _1229_t4._1;
    _1229_t6 = 1;
    _1229_t8 = _1230_y==_1229_t6;
    if (_1229_t8) {
        goto BB1398;
    } else {
        goto BB1405;
    }
BB1398:
    _1229_t9 = 2;
    _1229_t11 = _1230_x==_1229_t9;
    if (_1229_t11) {
        goto BB1401;
    } else {
        goto BB1405;
    }
BB1405:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1401:
    _1229_$retval = 159;
    return _1229_$retval;
}


int main(void) {
  printf("%ld",_1229_main());
  return 0;
}
