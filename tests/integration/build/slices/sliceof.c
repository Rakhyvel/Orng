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
int64_t _47_main(void);

/* Function definitions */
int64_t _47_main(void) {
    int64_t _47_t1;
    int64_t _47_t2;
    int64_t _47_t3;
    int64_t _47_t4;
    int64_t _47_t5;
    struct0 _48_x;
    int64_t _47_t7;
    int64_t* _47_t8;
    int64_t _47_t9;
    struct1 _48_y;
    int64_t _47_t10;
    int64_t _47_t11;
    int64_t _47_$retval;
    _47_t1 = 1;
    _47_t2 = 2;
    _47_t3 = 3;
    _47_t4 = 4;
    _47_t5 = 5;
    _48_x = (struct0) {_47_t1, _47_t2, _47_t3, _47_t4, _47_t5};
    _47_t7 = 0;
    _47_t8 = ((int64_t*)&_48_x + _47_t7);
    _47_t9 = 5;
    _48_y = (struct1) {_47_t8, _47_t9};
    _47_t10 = 2;
    _47_t11 = 77;
    _47_$retval = $add_int64_t(*((int64_t*)_48_y._0 + _47_t10), _47_t11, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    return _47_$retval;
}

int main(void) {
  printf("%ld",_47_main());
  return 0;
}
