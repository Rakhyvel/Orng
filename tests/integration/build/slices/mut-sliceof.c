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
    int64_t _3;
    int64_t _4;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _36_main(void);

/* Function definitions */
int64_t _36_main(void) {
    int64_t _36_t1;
    int64_t _36_t2;
    int64_t _36_t3;
    int64_t _36_t4;
    int64_t _36_t5;
    struct0 _37_x;
    int64_t _36_t7;
    int64_t* _36_t8;
    int64_t _36_t9;
    struct1 _37_y;
    int64_t _36_t11;
    int64_t _36_t12;
    int64_t _36_$retval;
    _36_t1 = 1;
    _36_t2 = 2;
    _36_t3 = 3;
    _36_t4 = 4;
    _36_t5 = 5;
    _37_x = (struct0) {_36_t1, _36_t2, _36_t3, _36_t4, _36_t5};
    _36_t7 = 0;
    _36_t8 = ((int64_t*)&_37_x + _36_t7);
    _36_t9 = 5;
    _37_y = (struct1) {_36_t8, _36_t9};
    _36_t11 = 2;
    *((int64_t*)_37_y._0 + _36_t11) = 81;
    _36_t12 = 2;
    _36_$retval = *((int64_t*)_37_y._0 + _36_t12);
    return _36_$retval;
}

int main(void) {
  printf("%ld",_36_main());
  return 0;
}
