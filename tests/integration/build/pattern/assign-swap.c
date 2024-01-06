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
int64_t _1140_main(void);

/* Function definitions */
int64_t _1140_main(void){
    int64_t _1140_t1;
    int64_t _1140_t2;
    struct struct0 _1140_t0;
    int64_t _1141_x;
    int64_t _1141_y;
    struct struct0 _1140_t3;
    int64_t _1140_t5;
    uint8_t _1140_t7;
    int64_t _1140_$retval;
    int64_t _1140_t8;
    uint8_t _1140_t10;
    _1140_t1 = 1;
    _1140_t2 = 2;
    _1140_t0 = (struct struct0) {_1140_t1, _1140_t2};
    _1141_x = _1140_t0._0;
    _1141_y = _1140_t0._1;
    _1140_t3 = (struct struct0) {_1141_x, _1141_y};
    _1141_y = _1140_t3._0;
    _1141_x = _1140_t3._1;
    _1140_t5 = 1;
    _1140_t7 = _1141_y==_1140_t5;
    if (_1140_t7) {
        goto BB1335;
    } else {
        goto BB1342;
    }
BB1335:
    _1140_t8 = 2;
    _1140_t10 = _1141_x==_1140_t8;
    if (_1140_t10) {
        goto BB1338;
    } else {
        goto BB1342;
    }
BB1342:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1338:
    _1140_$retval = 159;
    return _1140_$retval;
}

int main(void) {
  printf("%ld",_1140_main());
  return 0;
}
