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
int64_t _997_main(void);

/* Function definitions */
int64_t _997_main(void) {
    int64_t _997_t1;
    int64_t _997_t2;
    int64_t _997_t3;
    struct0 _998_x;
    int64_t _997_t6;
    int64_t* _997_t7;
    int64_t _997_t8;
    struct1 _997_t5;
    int64_t _997_t10;
    int64_t* _997_t11;
    int64_t _997_t12;
    struct1 _997_t9;
    int64_t _997_t14;
    int64_t* _997_t15;
    int64_t _997_t16;
    struct1 _997_t13;
    struct2 _998_y;
    int64_t _997_t18;
    struct1* _997_t19;
    int64_t _997_t20;
    struct3 _998_z;
    int64_t _997_t22;
    int64_t _997_t23;
    int64_t _997_t24;
    int64_t _997_t25;
    int64_t _997_$retval;
    _997_t1 = 1;
    _997_t2 = 2;
    _997_t3 = 3;
    _998_x = (struct0) {_997_t1, _997_t2, _997_t3};
    _997_t6 = 0;
    _997_t7 = ((int64_t*)&_998_x + _997_t6);
    _997_t8 = 3;
    _997_t5 = (struct1) {_997_t7, _997_t8};
    _997_t10 = 0;
    _997_t11 = ((int64_t*)&_998_x + _997_t10);
    _997_t12 = 3;
    _997_t9 = (struct1) {_997_t11, _997_t12};
    _997_t14 = 0;
    _997_t15 = ((int64_t*)&_998_x + _997_t14);
    _997_t16 = 3;
    _997_t13 = (struct1) {_997_t15, _997_t16};
    _998_y = (struct2) {_997_t5, _997_t9, _997_t13};
    _997_t18 = 0;
    _997_t19 = ((struct1*)&_998_y + _997_t18);
    _997_t20 = 3;
    _998_z = (struct3) {_997_t19, _997_t20};
    _997_t22 = 2;
    _997_t23 = 1;
    *((int64_t*)(*((struct1*)_998_z._0 + _997_t23))._0 + _997_t22) = 82;
    _997_t24 = 2;
    _997_t25 = 1;
    _997_$retval = *((int64_t*)(*((struct1*)_998_z._0 + _997_t25))._0 + _997_t24);
    return _997_$retval;
}

int main(void) {
  printf("%ld",_997_main());
  return 0;
}
