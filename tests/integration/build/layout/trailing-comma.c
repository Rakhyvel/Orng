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
int64_t _774_main(void);

/* Function definitions */
int64_t _774_main(void) {
    int64_t _774_t1;
    int64_t _774_t2;
    int64_t _774_t3;
    int64_t _774_t4;
    struct0 _775_x;
    int64_t _774_t5;
    int64_t _774_t6;
    int64_t _774_t7;
    int64_t _774_t8;
    int64_t _774_t9;
    int64_t _774_t10;
    int64_t _774_$retval;
    _774_t1 = 100;
    _774_t2 = 100;
    _774_t3 = 3;
    _774_t4 = 4;
    _775_x = (struct0) {_774_t1, _774_t2, _774_t3, _774_t4};
    _774_t5 = 0;
    _774_t6 = 1;
    _774_t7 = $add_int64_t(*((int64_t*)&_775_x + _774_t5), *((int64_t*)&_775_x + _774_t6), "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _774_t8 = 2;
    _774_t9 = $add_int64_t(_774_t7, *((int64_t*)&_775_x + _774_t8), "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _774_t10 = 3;
    _774_$retval = $add_int64_t(_774_t9, *((int64_t*)&_775_x + _774_t10), "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _774_$retval;
}

int main(void) {
  printf("%ld",_774_main());
  return 0;
}
