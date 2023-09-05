/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1693788378428127183
#define ORNG_1693788378428127183

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
    struct0 _2_t1;
    int64_t _2_t5;
    int64_t _2_t6;
    struct0 _2_t4;
    struct1 _2_t0;
    int64_t _3_x;
    int64_t _3_y;
    int64_t _3_a;
    int64_t _3_b;
    int64_t _2_t13;
    int64_t _2_t14;
    int64_t _2_$retval;
BB0:
    _2_t2 = 100;
    _2_t3 = 20;
    _2_t1 = (struct0) {_2_t2, _2_t3};
    _2_t5 = 20;
    _2_t6 = 2;
    _2_t4 = (struct0) {_2_t5, _2_t6};
    _2_t0 = (struct1) {_2_t1, _2_t4};
    _3_x = (&((&_2_t0)->_0))->_0;
    _3_y = (&((&_2_t0)->_0))->_1;
    _3_a = (&((&_2_t0)->_1))->_0;
    _3_b = (&((&_2_t0)->_1))->_1;
    _2_t13 = _3_x + _3_y;
    _2_t14 = _2_t13 + _3_a;
    _2_$retval = _2_t14 + _3_b;
    return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
