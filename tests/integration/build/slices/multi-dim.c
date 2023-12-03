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
int64_t _973_main(void);

/* Function definitions */
int64_t _973_main(void) {
    int64_t _973_t1;
    int64_t _973_t2;
    int64_t _973_t3;
    struct0 _974_x;
    int64_t _973_t6;
    int64_t* _973_t7;
    int64_t _973_t8;
    struct1 _973_t5;
    int64_t _973_t10;
    int64_t* _973_t11;
    int64_t _973_t12;
    struct1 _973_t9;
    int64_t _973_t14;
    int64_t* _973_t15;
    int64_t _973_t16;
    struct1 _973_t13;
    struct2 _974_y;
    int64_t _973_t18;
    struct1* _973_t19;
    int64_t _973_t20;
    struct3 _974_z;
    int64_t _973_t22;
    int64_t _973_t23;
    int64_t _973_t24;
    int64_t _973_t25;
    int64_t _973_$retval;
    _973_t1 = 1;
    _973_t2 = 2;
    _973_t3 = 3;
    _974_x = (struct0) {_973_t1, _973_t2, _973_t3};
    _973_t6 = 0;
    _973_t7 = ((int64_t*)&_974_x + _973_t6);
    _973_t8 = 3;
    _973_t5 = (struct1) {_973_t7, _973_t8};
    _973_t10 = 0;
    _973_t11 = ((int64_t*)&_974_x + _973_t10);
    _973_t12 = 3;
    _973_t9 = (struct1) {_973_t11, _973_t12};
    _973_t14 = 0;
    _973_t15 = ((int64_t*)&_974_x + _973_t14);
    _973_t16 = 3;
    _973_t13 = (struct1) {_973_t15, _973_t16};
    _974_y = (struct2) {_973_t5, _973_t9, _973_t13};
    _973_t18 = 0;
    _973_t19 = ((struct1*)&_974_y + _973_t18);
    _973_t20 = 3;
    _974_z = (struct3) {_973_t19, _973_t20};
    _973_t22 = 2;
    _973_t23 = 1;
    *((int64_t*)(*((struct1*)_974_z._0 + _973_t23))._0 + _973_t22) = 82;
    _973_t24 = 2;
    _973_t25 = 1;
    _973_$retval = *((int64_t*)(*((struct1*)_974_z._0 + _973_t25))._0 + _973_t24);
    return _973_$retval;
}

int main(void) {
  printf("%ld",_973_main());
  return 0;
}
