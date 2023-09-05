/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681445729255
#define ORNG_1691899681445729255

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

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

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_t4;
    struct0 _2_t1;
    int64_t _2_t6;
    int64_t _2_t7;
    int64_t _2_t8;
    struct0 _2_t5;
    int64_t _2_t10;
    int64_t _2_t11;
    int64_t _2_t12;
    struct0 _2_t9;
    struct1 _3_x;
    int64_t _2_t13;
    struct0 _2_t14;
    int64_t _2_t19;
    int64_t _2_t20;
    int64_t _2_t25;
    int64_t _2_t26;
    int64_t _2_t27;
    struct0 _2_t28;
    int64_t _2_t33;
    int64_t _2_t38;
    struct0 _2_t39;
    int64_t _2_t44;
    int64_t _2_t45;
    int64_t _2_$retval;
BB0:
    _2_t2 = 1;
    _2_t3 = 2;
    _2_t4 = 3;
    _2_t1 = (struct0) {_2_t2, _2_t3, _2_t4};
    _2_t6 = 4;
    _2_t7 = 5;
    _2_t8 = 68;
    _2_t5 = (struct0) {_2_t6, _2_t7, _2_t8};
    _2_t10 = 7;
    _2_t11 = 8;
    _2_t12 = 9;
    _2_t9 = (struct0) {_2_t10, _2_t11, _2_t12};
    _3_x = (struct1) {_2_t1, _2_t5, _2_t9};
    _2_t13 = 1;
    _2_t14 = *(((struct0*)(&_3_x))+_2_t13);
    _2_t19 = 2;
    _2_t20 = *(((int64_t*)((((struct0*)(&_3_x))+_2_t13)))+_2_t19);
    _2_t25 = 1;
    _2_t26 = _2_t20 + _2_t25;
    _2_t27 = 1;
    _2_t28 = *(((struct0*)(&_3_x))+_2_t27);
    _2_t33 = 2;
    *(((int64_t*)((((struct0*)(&_3_x))+_2_t27)))+_2_t33) = _2_t26;
    _2_t38 = 1;
    _2_t39 = *(((struct0*)(&_3_x))+_2_t38);
    _2_t44 = 2;
    _2_t45 = *(((int64_t*)((((struct0*)(&_3_x))+_2_t38)))+_2_t44);
    _2_$retval = _2_t45;
    return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
