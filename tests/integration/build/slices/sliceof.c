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
int64_t _1011_main(void);

/* Function definitions */
int64_t _1011_main(void) {
    int64_t _1011_t1;
    int64_t _1011_t2;
    int64_t _1011_t3;
    int64_t _1011_t4;
    int64_t _1011_t5;
    struct0 _1012_x;
    int64_t _1011_t7;
    int64_t* _1011_t8;
    int64_t _1011_t9;
    struct1 _1012_y;
    int64_t _1011_t10;
    int64_t _1011_t11;
    int64_t _1011_$retval;
    _1011_t1 = 1;
    _1011_t2 = 2;
    _1011_t3 = 3;
    _1011_t4 = 4;
    _1011_t5 = 5;
    _1012_x = (struct0) {_1011_t1, _1011_t2, _1011_t3, _1011_t4, _1011_t5};
    _1011_t7 = 0;
    _1011_t8 = ((int64_t*)&_1012_x + _1011_t7);
    _1011_t9 = 5;
    _1012_y = (struct1) {_1011_t8, _1011_t9};
    _1011_t10 = 2;
    _1011_t11 = 77;
    _1011_$retval = $add_int64_t(*((int64_t*)_1012_y._0 + _1011_t10), _1011_t11, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    return _1011_$retval;
}

int main(void) {
  printf("%ld",_1011_main());
  return 0;
}
