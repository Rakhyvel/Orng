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
    int64_t _4;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _1300_main(void);

/* Function definitions */
int64_t _1300_main(void) {
    int64_t _1300_t1;
    int64_t _1300_t2;
    int64_t _1300_t3;
    int64_t _1300_t4;
    int64_t _1300_t5;
    struct0 _1301_x;
    int64_t _1300_t7;
    int64_t* _1300_t8;
    int64_t _1300_t9;
    struct1 _1301_y;
    int64_t _1300_t10;
    int64_t _1300_t11;
    int64_t _1300_$retval;
    _1300_t1 = 1;
    _1300_t2 = 2;
    _1300_t3 = 3;
    _1300_t4 = 4;
    _1300_t5 = 5;
    _1301_x = (struct0) {_1300_t1, _1300_t2, _1300_t3, _1300_t4, _1300_t5};
    _1300_t7 = 0;
    _1300_t8 = ((int64_t*)&_1301_x + _1300_t7);
    _1300_t9 = 5;
    _1301_y = (struct1) {_1300_t8, _1300_t9};
    _1300_t10 = 2;
    _1300_t11 = 77;
    _1300_$retval = $add_int64_t(*((int64_t*)_1301_y._0 + _1300_t10), _1300_t11, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    return _1300_$retval;
}

int main(void) {
  printf("%ld",_1300_main());
  return 0;
}
