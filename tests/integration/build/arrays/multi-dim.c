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
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
    struct0 _2;
} struct1;

/* Function forward definitions */
int64_t _103_main(void);

/* Function definitions */
int64_t _103_main(void) {
    int64_t _103_t2;
    int64_t _103_t3;
    int64_t _103_t4;
    struct0 _103_t1;
    int64_t _103_t6;
    int64_t _103_t7;
    int64_t _103_t8;
    struct0 _103_t5;
    int64_t _103_t10;
    int64_t _103_t11;
    int64_t _103_t12;
    struct0 _103_t9;
    struct1 _104_x;
    int64_t _103_t13;
    int64_t _103_t14;
    int64_t _103_t15;
    int64_t _103_t17;
    int64_t _103_t18;
    int64_t _103_t19;
    int64_t _103_t20;
    int64_t _103_$retval;
    _103_t2 = 1;
    _103_t3 = 2;
    _103_t4 = 3;
    _103_t1 = (struct0) {_103_t2, _103_t3, _103_t4};
    _103_t6 = 4;
    _103_t7 = 5;
    _103_t8 = 68;
    _103_t5 = (struct0) {_103_t6, _103_t7, _103_t8};
    _103_t10 = 7;
    _103_t11 = 8;
    _103_t12 = 9;
    _103_t9 = (struct0) {_103_t10, _103_t11, _103_t12};
    _104_x = (struct1) {_103_t1, _103_t5, _103_t9};
    _103_t13 = 2;
    _103_t14 = 1;
    _103_t15 = 1;
    _103_t17 = 2;
    _103_t18 = 1;
    *((int64_t*)((struct0*)&_104_x + _103_t18) + _103_t17) = $add_int64_t(*((int64_t*)((struct0*)&_104_x + _103_t14) + _103_t13), _103_t15, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    _103_t19 = 2;
    _103_t20 = 1;
    _103_$retval = *((int64_t*)((struct0*)&_104_x + _103_t20) + _103_t19);
    return _103_$retval;
}

int main(void) {
  printf("%ld",_103_main());
  return 0;
}
