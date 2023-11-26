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
int64_t _907_main(void);

/* Function definitions */
int64_t _907_main(void) {
    int64_t _907_t1;
    int64_t _907_t2;
    int64_t _907_t3;
    struct0 _908_x;
    int64_t _907_t6;
    int64_t* _907_t7;
    int64_t _907_t8;
    struct1 _907_t5;
    int64_t _907_t10;
    int64_t* _907_t11;
    int64_t _907_t12;
    struct1 _907_t9;
    int64_t _907_t14;
    int64_t* _907_t15;
    int64_t _907_t16;
    struct1 _907_t13;
    struct2 _908_y;
    int64_t _907_t18;
    struct1* _907_t19;
    int64_t _907_t20;
    struct3 _908_z;
    int64_t _907_t22;
    int64_t _907_t23;
    int64_t _907_t24;
    int64_t _907_t25;
    int64_t _907_$retval;
    _907_t1 = 1;
    _907_t2 = 2;
    _907_t3 = 3;
    _908_x = (struct0) {_907_t1, _907_t2, _907_t3};
    _907_t6 = 0;
    _907_t7 = ((int64_t*)&_908_x + _907_t6);
    _907_t8 = 3;
    _907_t5 = (struct1) {_907_t7, _907_t8};
    _907_t10 = 0;
    _907_t11 = ((int64_t*)&_908_x + _907_t10);
    _907_t12 = 3;
    _907_t9 = (struct1) {_907_t11, _907_t12};
    _907_t14 = 0;
    _907_t15 = ((int64_t*)&_908_x + _907_t14);
    _907_t16 = 3;
    _907_t13 = (struct1) {_907_t15, _907_t16};
    _908_y = (struct2) {_907_t5, _907_t9, _907_t13};
    _907_t18 = 0;
    _907_t19 = ((struct1*)&_908_y + _907_t18);
    _907_t20 = 3;
    _908_z = (struct3) {_907_t19, _907_t20};
    _907_t22 = 2;
    _907_t23 = 1;
    *((int64_t*)(*((struct1*)_908_z._0 + _907_t23))._0 + _907_t22) = 82;
    _907_t24 = 2;
    _907_t25 = 1;
    _907_$retval = *((int64_t*)(*((struct1*)_908_z._0 + _907_t25))._0 + _907_t24);
    return _907_$retval;
}

int main(void) {
  printf("%ld",_907_main());
  return 0;
}
