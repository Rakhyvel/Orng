/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _1124_main(void);

/* Function definitions */
int64_t _1124_main(void){
    int64_t _1124_t1;
    int64_t _1124_t2;
    struct0 _1124_t0;
    int64_t _1125_x;
    int64_t _1125_y;
    struct0 _1124_t3;
    int64_t _1124_t6;
    uint8_t _1124_t8;
    uint8_t _1124_t10;
    uint8_t _1124_t5;
    int64_t _1124_t9;
    uint8_t _1124_t11;
    int64_t _1124_$retval;
    _1124_t1 = 1;
    _1124_t2 = 2;
    _1124_t0 = (struct0) {_1124_t1, _1124_t2};
    _1125_x = _1124_t0._0;
    _1125_y = _1124_t0._1;
    _1124_t3 = (struct0) {_1125_x, _1125_y};
    _1125_y = _1124_t3._0;
    _1125_x = _1124_t3._1;
    _1124_t6 = 1;
    _1124_t8 = _1125_y == _1124_t6;
    if (_1124_t8) {
        goto BB1357;
    } else {
        goto BB1367;
    }
BB1357:
    _1124_t9 = 2;
    _1124_t11 = _1125_x == _1124_t9;
    if (_1124_t11) {
        goto BB1358;
    } else {
        goto BB1366;
    }
BB1367:
    _1124_t5 = 0;
    goto BB1365;
BB1358:
    _1124_t10 = 1;
    goto BB1359;
BB1366:
    _1124_t10 = 0;
    goto BB1359;
BB1365:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1359:
    _1124_t5 = _1124_t10;
    goto BB1360;
BB1360:
    if (_1124_t5) {
        goto BB1361;
    } else {
        goto BB1365;
    }
BB1361:
    _1124_$retval = 159;
    return _1124_$retval;
}

int main(void) {
  printf("%ld",_1124_main());
  return 0;
}
