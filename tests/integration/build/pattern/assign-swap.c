/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1150_main(void);

/* Function definitions */
int64_t _1150_main(void){
    int64_t _1150_t1;
    int64_t _1150_t2;
    struct struct0 _1150_t0;
    int64_t _1151_x;
    int64_t _1151_y;
    struct struct0 _1150_t3;
    int64_t _1150_t5;
    uint8_t _1150_t7;
    int64_t _1150_$retval;
    int64_t _1150_t8;
    uint8_t _1150_t10;
    _1150_t1 = 1;
    _1150_t2 = 2;
    _1150_t0 = (struct struct0) {_1150_t1, _1150_t2};
    _1151_x = _1150_t0._0;
    _1151_y = _1150_t0._1;
    _1150_t3 = (struct struct0) {_1151_x, _1151_y};
    _1151_y = _1150_t3._0;
    _1151_x = _1150_t3._1;
    _1150_t5 = 1;
    _1150_t7 = _1151_y==_1150_t5;
    if (_1150_t7) {
        goto BB1347;
    } else {
        goto BB1354;
    }
BB1347:
    _1150_t8 = 2;
    _1150_t10 = _1151_x==_1150_t8;
    if (_1150_t10) {
        goto BB1350;
    } else {
        goto BB1354;
    }
BB1354:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1350:
    _1150_$retval = 159;
    return _1150_$retval;
}

int main(void) {
  printf("%ld",_1150_main());
  return 0;
}
