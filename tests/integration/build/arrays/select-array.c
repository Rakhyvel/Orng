/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1694151997587961858
#define ORNG_1694151997587961858

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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
    struct1 _3_x;
    int64_t _2_t9;
    struct0 _2_t10;
    int64_t _2_t11;
    struct0 _2_t16;
    int64_t _2_t17;
    int64_t _2_t18;
    int64_t _2_$retval;
BB0:
    _2_t2 = 1;
    _2_t3 = 2;
    _2_t4 = 3;
    _2_t1 = (struct0) {_2_t2, _2_t3, _2_t4};
    _2_t6 = 4;
    _2_t7 = 5;
    _2_t8 = 6;
    _2_t5 = (struct0) {_2_t6, _2_t7, _2_t8};
    _3_x = (struct1) {_2_t1, _2_t5};
    _2_t9 = 72;
    _2_t10 = (&_3_x)->_0;
    _2_t11 = 1;
    *(((int64_t*)(&((&_3_x)->_0)))+_2_t11) = _2_t9;
    _2_t16 = (&_3_x)->_0;
    _2_t17 = 1;
    _2_t18 = *(((int64_t*)(&((&_3_x)->_0)))+_2_t17);
    _2_$retval = _2_t18;
    return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
