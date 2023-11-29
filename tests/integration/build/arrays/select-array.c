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
int64_t _146_main(void);

/* Function definitions */
int64_t _146_main(void) {
    int64_t _146_t2;
    int64_t _146_t3;
    int64_t _146_t4;
    struct0 _146_t1;
    int64_t _146_t6;
    int64_t _146_t7;
    int64_t _146_t8;
    struct0 _146_t5;
    struct1 _147_x;
    int64_t _146_t10;
    int64_t _146_t11;
    int64_t _146_$retval;
    _146_t2 = 1;
    _146_t3 = 2;
    _146_t4 = 3;
    _146_t1 = (struct0) {_146_t2, _146_t3, _146_t4};
    _146_t6 = 4;
    _146_t7 = 5;
    _146_t8 = 6;
    _146_t5 = (struct0) {_146_t6, _146_t7, _146_t8};
    _147_x = (struct1) {_146_t1, _146_t5};
    _146_t10 = 1;
    *((int64_t*)&_147_x._0 + _146_t10) = 72;
    _146_t11 = 1;
    _146_$retval = *((int64_t*)&_147_x._0 + _146_t11);
    return _146_$retval;
}

int main(void) {
  printf("%ld",_146_main());
  return 0;
}
