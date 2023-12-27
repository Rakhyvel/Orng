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
    int64_t _1124_t5;
    uint8_t _1124_t7;
    int64_t _1124_$retval;
    int64_t _1124_t8;
    uint8_t _1124_t10;
    _1124_t1 = 1;
    _1124_t2 = 2;
    _1124_t0 = (struct0) {_1124_t1, _1124_t2};
    _1125_x = _1124_t0._0;
    _1125_y = _1124_t0._1;
    _1124_t3 = (struct0) {_1125_x, _1125_y};
    _1125_y = _1124_t3._0;
    _1125_x = _1124_t3._1;
    _1124_t5 = 1;
    _1124_t7 = _1125_y==_1124_t5;
    if (_1124_t7) {
        goto BB1342;
    } else {
        goto BB1349;
    }
BB1342:
    _1124_t8 = 2;
    _1124_t10 = _1125_x==_1124_t8;
    if (_1124_t10) {
        goto BB1345;
    } else {
        goto BB1349;
    }
BB1349:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1345:
    _1124_$retval = 159;
    return _1124_$retval;
}

int main(void) {
  printf("%ld",_1124_main());
  return 0;
}
