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
int64_t _1259_main(void);


/* Function definitions */
int64_t _1259_main(void){
    int64_t _1259_t1;
    int64_t _1259_t2;
    struct struct0 _1259_t0;
    int64_t _1260_x;
    int64_t _1260_y;
    struct struct0 _1259_t4;
    int64_t _1259_t6;
    uint8_t _1259_t8;
    int64_t _1259_$retval;
    int64_t _1259_t9;
    uint8_t _1259_t11;
    _1259_t1 = 1;
    _1259_t2 = 2;
    _1259_t0 = (struct struct0) {_1259_t1, _1259_t2};
    _1260_x = _1259_t0._0;
    _1260_y = _1259_t0._1;
    _1259_t4 = (struct struct0) {_1260_x, _1260_y};
    _1260_y = _1259_t4._0;
    _1260_x = _1259_t4._1;
    _1259_t6 = 1;
    _1259_t8 = _1260_y==_1259_t6;
    if (_1259_t8) {
        goto BB1429;
    } else {
        goto BB1436;
    }
BB1429:
    _1259_t9 = 2;
    _1259_t11 = _1260_x==_1259_t9;
    if (_1259_t11) {
        goto BB1432;
    } else {
        goto BB1436;
    }
BB1436:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1432:
    _1259_$retval = 159;
    return _1259_$retval;
}


int main(void) {
  printf("%ld",_1259_main());
  return 0;
}
