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
int64_t _1135_main(void);

/* Function definitions */
int64_t _1135_main(void){
    int64_t _1135_t1;
    int64_t _1135_t2;
    struct struct0 _1135_t0;
    int64_t _1136_x;
    int64_t _1136_y;
    struct struct0 _1135_t3;
    int64_t _1135_t5;
    uint8_t _1135_t7;
    int64_t _1135_$retval;
    int64_t _1135_t8;
    uint8_t _1135_t10;
    _1135_t1 = 1;
    _1135_t2 = 2;
    _1135_t0 = (struct struct0) {_1135_t1, _1135_t2};
    _1136_x = _1135_t0._0;
    _1136_y = _1135_t0._1;
    _1135_t3 = (struct struct0) {_1136_x, _1136_y};
    _1136_y = _1135_t3._0;
    _1136_x = _1135_t3._1;
    _1135_t5 = 1;
    _1135_t7 = _1136_y==_1135_t5;
    if (_1135_t7) {
        goto BB1331;
    } else {
        goto BB1338;
    }
BB1331:
    _1135_t8 = 2;
    _1135_t10 = _1136_x==_1135_t8;
    if (_1135_t10) {
        goto BB1334;
    } else {
        goto BB1338;
    }
BB1338:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1334:
    _1135_$retval = 159;
    return _1135_$retval;
}

int main(void) {
  printf("%ld",_1135_main());
  return 0;
}
