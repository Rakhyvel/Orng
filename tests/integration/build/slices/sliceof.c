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
int64_t _921_main(void);

/* Function definitions */
int64_t _921_main(void) {
    int64_t _921_t1;
    int64_t _921_t2;
    int64_t _921_t3;
    int64_t _921_t4;
    int64_t _921_t5;
    struct0 _922_x;
    int64_t _921_t7;
    int64_t* _921_t8;
    int64_t _921_t9;
    struct1 _922_y;
    int64_t _921_t10;
    int64_t _921_t11;
    int64_t _921_$retval;
    _921_t1 = 1;
    _921_t2 = 2;
    _921_t3 = 3;
    _921_t4 = 4;
    _921_t5 = 5;
    _922_x = (struct0) {_921_t1, _921_t2, _921_t3, _921_t4, _921_t5};
    _921_t7 = 0;
    _921_t8 = ((int64_t*)&_922_x + _921_t7);
    _921_t9 = 5;
    _922_y = (struct1) {_921_t8, _921_t9};
    _921_t10 = 2;
    _921_t11 = 77;
    _921_$retval = $add_int64_t(*((int64_t*)_922_y._0 + _921_t10), _921_t11, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    return _921_$retval;
}

int main(void) {
  printf("%ld",_921_main());
  return 0;
}
