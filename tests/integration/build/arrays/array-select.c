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
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
    struct0 _2;
} struct1;

/* Function forward definitions */
int64_t _54_main(void);

/* Function definitions */
int64_t _54_main(void) {
    int64_t _54_t2;
    int64_t _54_t3;
    struct0 _54_t1;
    int64_t _54_t5;
    int64_t _54_t6;
    struct0 _54_t4;
    int64_t _54_t8;
    int64_t _54_t9;
    struct0 _54_t7;
    struct1 _55_x;
    int64_t _54_t11;
    int64_t _54_t12;
    int64_t _54_$retval;
    _54_t2 = 1;
    _54_t3 = 2;
    _54_t1 = (struct0) {_54_t2, _54_t3};
    _54_t5 = 3;
    _54_t6 = 4;
    _54_t4 = (struct0) {_54_t5, _54_t6};
    _54_t8 = 5;
    _54_t9 = 6;
    _54_t7 = (struct0) {_54_t8, _54_t9};
    _55_x = (struct1) {_54_t1, _54_t4, _54_t7};
    _54_t11 = 1;
    (*((struct0*)&_55_x + _54_t11))._0 = 73;
    _54_t12 = 1;
    _54_$retval = (*((struct0*)&_55_x + _54_t12))._0;
    return _54_$retval;
}

int main(void) {
  printf("%ld",_54_main());
  return 0;
}
