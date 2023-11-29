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
int64_t _140_main(void);

/* Function definitions */
int64_t _140_main(void) {
    int64_t _140_t2;
    int64_t _140_t3;
    int64_t _140_t4;
    struct0 _140_t1;
    int64_t _140_t6;
    int64_t _140_t7;
    int64_t _140_t8;
    struct0 _140_t5;
    int64_t _140_t10;
    int64_t _140_t11;
    int64_t _140_t12;
    struct0 _140_t9;
    struct1 _141_x;
    int64_t _140_t13;
    int64_t _140_t14;
    int64_t _140_t15;
    int64_t _140_t17;
    int64_t _140_t18;
    int64_t _140_t19;
    int64_t _140_t20;
    int64_t _140_$retval;
    _140_t2 = 1;
    _140_t3 = 2;
    _140_t4 = 3;
    _140_t1 = (struct0) {_140_t2, _140_t3, _140_t4};
    _140_t6 = 4;
    _140_t7 = 5;
    _140_t8 = 68;
    _140_t5 = (struct0) {_140_t6, _140_t7, _140_t8};
    _140_t10 = 7;
    _140_t11 = 8;
    _140_t12 = 9;
    _140_t9 = (struct0) {_140_t10, _140_t11, _140_t12};
    _141_x = (struct1) {_140_t1, _140_t5, _140_t9};
    _140_t13 = 2;
    _140_t14 = 1;
    _140_t15 = 1;
    _140_t17 = 2;
    _140_t18 = 1;
    *((int64_t*)((struct0*)&_141_x + _140_t18) + _140_t17) = $add_int64_t(*((int64_t*)((struct0*)&_141_x + _140_t14) + _140_t13), _140_t15, "tests/integration/arrays/multi-dim.orng:8:15:\n    x[1][2] += 1 // nice\n             ^");
    _140_t19 = 2;
    _140_t20 = 1;
    _140_$retval = *((int64_t*)((struct0*)&_141_x + _140_t20) + _140_t19);
    return _140_$retval;
}

int main(void) {
  printf("%ld",_140_main());
  return 0;
}
