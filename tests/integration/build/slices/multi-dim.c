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
    int64_t* _0;
    int64_t _1;
} struct1;

typedef struct {
    struct1 _0;
    struct1 _1;
    struct1 _2;
} struct2;

typedef struct {
    struct1* _0;
    int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _33_main(void);

/* Function definitions */
int64_t _33_main(void) {
    int64_t _33_t1;
    int64_t _33_t2;
    int64_t _33_t3;
    struct0 _34_x;
    int64_t _33_t6;
    int64_t* _33_t7;
    int64_t _33_t8;
    struct1 _33_t5;
    int64_t _33_t10;
    int64_t* _33_t11;
    int64_t _33_t12;
    struct1 _33_t9;
    int64_t _33_t14;
    int64_t* _33_t15;
    int64_t _33_t16;
    struct1 _33_t13;
    struct2 _34_y;
    int64_t _33_t18;
    struct1* _33_t19;
    int64_t _33_t20;
    struct3 _34_z;
    int64_t _33_t22;
    int64_t _33_t23;
    int64_t _33_t24;
    int64_t _33_t25;
    int64_t _33_$retval;
    _33_t1 = 1;
    _33_t2 = 2;
    _33_t3 = 3;
    _34_x = (struct0) {_33_t1, _33_t2, _33_t3};
    _33_t6 = 0;
    _33_t7 = ((int64_t*)&_34_x + _33_t6);
    _33_t8 = 3;
    _33_t5 = (struct1) {_33_t7, _33_t8};
    _33_t10 = 0;
    _33_t11 = ((int64_t*)&_34_x + _33_t10);
    _33_t12 = 3;
    _33_t9 = (struct1) {_33_t11, _33_t12};
    _33_t14 = 0;
    _33_t15 = ((int64_t*)&_34_x + _33_t14);
    _33_t16 = 3;
    _33_t13 = (struct1) {_33_t15, _33_t16};
    _34_y = (struct2) {_33_t5, _33_t9, _33_t13};
    _33_t18 = 0;
    _33_t19 = ((struct1*)&_34_y + _33_t18);
    _33_t20 = 3;
    _34_z = (struct3) {_33_t19, _33_t20};
    _33_t22 = 2;
    _33_t23 = 1;
    *((int64_t*)(*((struct1*)_34_z._0 + _33_t23))._0 + _33_t22) = 82;
    _33_t24 = 2;
    _33_t25 = 1;
    _33_$retval = *((int64_t*)(*((struct1*)_34_z._0 + _33_t25))._0 + _33_t24);
    return _33_$retval;
}

int main(void) {
  printf("%ld",_33_main());
  return 0;
}
