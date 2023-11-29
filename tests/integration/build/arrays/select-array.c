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
} struct1;

/* Function forward definitions */
int64_t _83_main(void);

/* Function definitions */
int64_t _83_main(void) {
    int64_t _83_t2;
    int64_t _83_t3;
    int64_t _83_t4;
    struct0 _83_t1;
    int64_t _83_t6;
    int64_t _83_t7;
    int64_t _83_t8;
    struct0 _83_t5;
    struct1 _84_x;
    int64_t _83_t10;
    int64_t _83_t11;
    int64_t _83_$retval;
    _83_t2 = 1;
    _83_t3 = 2;
    _83_t4 = 3;
    _83_t1 = (struct0) {_83_t2, _83_t3, _83_t4};
    _83_t6 = 4;
    _83_t7 = 5;
    _83_t8 = 6;
    _83_t5 = (struct0) {_83_t6, _83_t7, _83_t8};
    _84_x = (struct1) {_83_t1, _83_t5};
    _83_t10 = 1;
    *((int64_t*)&_84_x._0 + _83_t10) = 72;
    _83_t11 = 1;
    _83_$retval = *((int64_t*)&_84_x._0 + _83_t11);
    return _83_$retval;
}

int main(void) {
  printf("%ld",_83_main());
  return 0;
}
