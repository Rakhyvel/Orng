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
int64_t _1132_main(void);

/* Function definitions */
int64_t _1132_main(void){
    int64_t _1132_t1;
    int64_t _1132_t2;
    struct struct0 _1132_t0;
    int64_t _1133_x;
    int64_t _1133_y;
    struct struct0 _1132_t3;
    int64_t _1132_t5;
    uint8_t _1132_t7;
    int64_t _1132_$retval;
    int64_t _1132_t8;
    uint8_t _1132_t10;
    _1132_t1 = 1;
    _1132_t2 = 2;
    _1132_t0 = (struct struct0) {_1132_t1, _1132_t2};
    _1133_x = _1132_t0._0;
    _1133_y = _1132_t0._1;
    _1132_t3 = (struct struct0) {_1133_x, _1133_y};
    _1133_y = _1132_t3._0;
    _1133_x = _1132_t3._1;
    _1132_t5 = 1;
    _1132_t7 = _1133_y==_1132_t5;
    if (_1132_t7) {
        goto BB1339;
    } else {
        goto BB1346;
    }
BB1339:
    _1132_t8 = 2;
    _1132_t10 = _1133_x==_1132_t8;
    if (_1132_t10) {
        goto BB1342;
    } else {
        goto BB1346;
    }
BB1346:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1342:
    _1132_$retval = 159;
    return _1132_$retval;
}

int main(void) {
  printf("%ld",_1132_main());
  return 0;
}
