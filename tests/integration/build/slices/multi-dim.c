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
int64_t _1254_main(void);

/* Function definitions */
int64_t _1254_main(void) {
    int64_t _1254_t1;
    int64_t _1254_t2;
    int64_t _1254_t3;
    struct0 _1255_x;
    int64_t _1254_t6;
    int64_t* _1254_t7;
    int64_t _1254_t8;
    struct1 _1254_t5;
    int64_t _1254_t10;
    int64_t* _1254_t11;
    int64_t _1254_t12;
    struct1 _1254_t9;
    int64_t _1254_t14;
    int64_t* _1254_t15;
    int64_t _1254_t16;
    struct1 _1254_t13;
    struct2 _1255_y;
    int64_t _1254_t18;
    struct1* _1254_t19;
    int64_t _1254_t20;
    struct3 _1255_z;
    int64_t _1254_t22;
    int64_t _1254_t23;
    int64_t _1254_t24;
    int64_t _1254_t25;
    int64_t _1254_$retval;
    _1254_t1 = 1;
    _1254_t2 = 2;
    _1254_t3 = 3;
    _1255_x = (struct0) {_1254_t1, _1254_t2, _1254_t3};
    _1254_t6 = 0;
    _1254_t7 = ((int64_t*)&_1255_x + _1254_t6);
    _1254_t8 = 3;
    _1254_t5 = (struct1) {_1254_t7, _1254_t8};
    _1254_t10 = 0;
    _1254_t11 = ((int64_t*)&_1255_x + _1254_t10);
    _1254_t12 = 3;
    _1254_t9 = (struct1) {_1254_t11, _1254_t12};
    _1254_t14 = 0;
    _1254_t15 = ((int64_t*)&_1255_x + _1254_t14);
    _1254_t16 = 3;
    _1254_t13 = (struct1) {_1254_t15, _1254_t16};
    _1255_y = (struct2) {_1254_t5, _1254_t9, _1254_t13};
    _1254_t18 = 0;
    _1254_t19 = ((struct1*)&_1255_y + _1254_t18);
    _1254_t20 = 3;
    _1255_z = (struct3) {_1254_t19, _1254_t20};
    _1254_t22 = 2;
    _1254_t23 = 1;
    *((int64_t*)(*((struct1*)_1255_z._0 + _1254_t23))._0 + _1254_t22) = 82;
    _1254_t24 = 2;
    _1254_t25 = 1;
    _1254_$retval = *((int64_t*)(*((struct1*)_1255_z._0 + _1254_t25))._0 + _1254_t24);
    return _1254_$retval;
}

int main(void) {
  printf("%ld",_1254_main());
  return 0;
}
