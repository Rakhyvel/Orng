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
int64_t _144_main(void);

/* Function definitions */
int64_t _144_main(void) {
    int64_t _144_t2;
    int64_t _144_t3;
    int64_t _144_t4;
    struct0 _144_t1;
    int64_t _144_t6;
    int64_t _144_t7;
    int64_t _144_t8;
    struct0 _144_t5;
    struct1 _145_x;
    int64_t _144_t10;
    int64_t _144_t11;
    int64_t _144_$retval;
    _144_t2 = 1;
    _144_t3 = 2;
    _144_t4 = 3;
    _144_t1 = (struct0) {_144_t2, _144_t3, _144_t4};
    _144_t6 = 4;
    _144_t7 = 5;
    _144_t8 = 6;
    _144_t5 = (struct0) {_144_t6, _144_t7, _144_t8};
    _145_x = (struct1) {_144_t1, _144_t5};
    _144_t10 = 1;
    *((int64_t*)&_145_x._0 + _144_t10) = 72;
    _144_t11 = 1;
    _144_$retval = *((int64_t*)&_145_x._0 + _144_t11);
    return _144_$retval;
}

int main(void) {
  printf("%ld",_144_main());
  return 0;
}
