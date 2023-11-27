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
int64_t _938_main(void);

/* Function definitions */
int64_t _938_main(void) {
    int64_t _938_t1;
    int64_t _938_t2;
    int64_t _938_t3;
    struct0 _939_x;
    int64_t _938_t6;
    int64_t* _938_t7;
    int64_t _938_t8;
    struct1 _938_t5;
    int64_t _938_t10;
    int64_t* _938_t11;
    int64_t _938_t12;
    struct1 _938_t9;
    int64_t _938_t14;
    int64_t* _938_t15;
    int64_t _938_t16;
    struct1 _938_t13;
    struct2 _939_y;
    int64_t _938_t18;
    struct1* _938_t19;
    int64_t _938_t20;
    struct3 _939_z;
    int64_t _938_t22;
    int64_t _938_t23;
    int64_t _938_t24;
    int64_t _938_t25;
    int64_t _938_$retval;
    _938_t1 = 1;
    _938_t2 = 2;
    _938_t3 = 3;
    _939_x = (struct0) {_938_t1, _938_t2, _938_t3};
    _938_t6 = 0;
    _938_t7 = ((int64_t*)&_939_x + _938_t6);
    _938_t8 = 3;
    _938_t5 = (struct1) {_938_t7, _938_t8};
    _938_t10 = 0;
    _938_t11 = ((int64_t*)&_939_x + _938_t10);
    _938_t12 = 3;
    _938_t9 = (struct1) {_938_t11, _938_t12};
    _938_t14 = 0;
    _938_t15 = ((int64_t*)&_939_x + _938_t14);
    _938_t16 = 3;
    _938_t13 = (struct1) {_938_t15, _938_t16};
    _939_y = (struct2) {_938_t5, _938_t9, _938_t13};
    _938_t18 = 0;
    _938_t19 = ((struct1*)&_939_y + _938_t18);
    _938_t20 = 3;
    _939_z = (struct3) {_938_t19, _938_t20};
    _938_t22 = 2;
    _938_t23 = 1;
    *((int64_t*)(*((struct1*)_939_z._0 + _938_t23))._0 + _938_t22) = 82;
    _938_t24 = 2;
    _938_t25 = 1;
    _938_$retval = *((int64_t*)(*((struct1*)_939_z._0 + _938_t25))._0 + _938_t24);
    return _938_$retval;
}

int main(void) {
  printf("%ld",_938_main());
  return 0;
}
