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
    int64_t _2;
    int64_t _3;
} struct0;

/* Function forward definitions */
int64_t _8_main(void);

/* Function definitions */
int64_t _8_main(void) {
    int64_t _8_t1;
    int64_t _8_t2;
    int64_t _8_t3;
    int64_t _8_t4;
    struct0 _9_x;
    int64_t _8_t5;
    int64_t _8_t6;
    int64_t _8_t7;
    int64_t _8_t8;
    int64_t _8_t9;
    int64_t _8_t10;
    int64_t _8_$retval;
    _8_t1 = 100;
    _8_t2 = 100;
    _8_t3 = 3;
    _8_t4 = 4;
    _9_x = (struct0) {_8_t1, _8_t2, _8_t3, _8_t4};
    _8_t5 = 0;
    _8_t6 = 1;
    _8_t7 = $add_int64_t(*((int64_t*)&_9_x + _8_t5), *((int64_t*)&_9_x + _8_t6), "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _8_t8 = 2;
    _8_t9 = $add_int64_t(_8_t7, *((int64_t*)&_9_x + _8_t8), "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _8_t10 = 3;
    _8_$retval = $add_int64_t(_8_t9, *((int64_t*)&_9_x + _8_t10), "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _8_$retval;
}

int main(void) {
  printf("%ld",_8_main());
  return 0;
}
