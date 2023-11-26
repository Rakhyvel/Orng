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
int64_t _79_main(void);

/* Function definitions */
int64_t _79_main(void) {
    int64_t _79_t2;
    int64_t _79_t3;
    int64_t _79_t4;
    struct0 _79_t1;
    int64_t _79_t6;
    int64_t _79_t7;
    int64_t _79_t8;
    struct0 _79_t5;
    int64_t _79_t10;
    int64_t _79_t11;
    int64_t _79_t12;
    struct0 _79_t9;
    struct1 _80_x;
    int64_t _79_t13;
    int64_t _79_t14;
    int64_t _79_t15;
    int64_t _79_t17;
    int64_t _79_t18;
    int64_t _79_t19;
    int64_t _79_t20;
    int64_t _79_$retval;
    _79_t2 = 1;
    _79_t3 = 2;
    _79_t4 = 3;
    _79_t1 = (struct0) {_79_t2, _79_t3, _79_t4};
    _79_t6 = 4;
    _79_t7 = 5;
    _79_t8 = 68;
    _79_t5 = (struct0) {_79_t6, _79_t7, _79_t8};
    _79_t10 = 7;
    _79_t11 = 8;
    _79_t12 = 9;
    _79_t9 = (struct0) {_79_t10, _79_t11, _79_t12};
    _80_x = (struct1) {_79_t1, _79_t5, _79_t9};
    _79_t13 = 2;
    _79_t14 = 1;
    _79_t15 = 1;
    _79_t17 = 2;
    _79_t18 = 1;
    *((int64_t*)((struct0*)&_80_x + _79_t18) + _79_t17) = $add_int64_t(*((int64_t*)((struct0*)&_80_x + _79_t14) + _79_t13), _79_t15, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    _79_t19 = 2;
    _79_t20 = 1;
    _79_$retval = *((int64_t*)((struct0*)&_80_x + _79_t20) + _79_t19);
    return _79_$retval;
}

int main(void) {
  printf("%ld",_79_main());
  return 0;
}
