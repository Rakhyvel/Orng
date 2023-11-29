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
int64_t _108_main(void);

/* Function definitions */
int64_t _108_main(void) {
    int64_t _108_t2;
    int64_t _108_t3;
    int64_t _108_t4;
    struct0 _108_t1;
    int64_t _108_t6;
    int64_t _108_t7;
    int64_t _108_t8;
    struct0 _108_t5;
    struct1 _109_x;
    int64_t _108_t10;
    int64_t _108_t11;
    int64_t _108_$retval;
    _108_t2 = 1;
    _108_t3 = 2;
    _108_t4 = 3;
    _108_t1 = (struct0) {_108_t2, _108_t3, _108_t4};
    _108_t6 = 4;
    _108_t7 = 5;
    _108_t8 = 6;
    _108_t5 = (struct0) {_108_t6, _108_t7, _108_t8};
    _109_x = (struct1) {_108_t1, _108_t5};
    _108_t10 = 1;
    *((int64_t*)&_109_x._0 + _108_t10) = 72;
    _108_t11 = 1;
    _108_$retval = *((int64_t*)&_109_x._0 + _108_t11);
    return _108_$retval;
}

int main(void) {
  printf("%ld",_108_main());
  return 0;
}
