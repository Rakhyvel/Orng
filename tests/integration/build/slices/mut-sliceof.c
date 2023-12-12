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
int64_t _1027_main(void);

/* Function definitions */
int64_t _1027_main(void) {
    int64_t _1027_t1;
    int64_t _1027_t2;
    int64_t _1027_t3;
    int64_t _1027_t4;
    int64_t _1027_t5;
    struct0 _1028_x;
    int64_t _1027_t7;
    int64_t* _1027_t8;
    int64_t _1027_t9;
    struct1 _1028_y;
    int64_t _1027_t11;
    int64_t _1027_t12;
    int64_t _1027_$retval;
    _1027_t1 = 1;
    _1027_t2 = 2;
    _1027_t3 = 3;
    _1027_t4 = 4;
    _1027_t5 = 5;
    _1028_x = (struct0) {_1027_t1, _1027_t2, _1027_t3, _1027_t4, _1027_t5};
    _1027_t7 = 0;
    _1027_t8 = ((int64_t*)&_1028_x + _1027_t7);
    _1027_t9 = 5;
    _1028_y = (struct1) {_1027_t8, _1027_t9};
    _1027_t11 = 2;
    *((int64_t*)_1028_y._0 + _1027_t11) = 81;
    _1027_t12 = 2;
    _1027_$retval = *((int64_t*)_1028_y._0 + _1027_t12);
    return _1027_$retval;
}

int main(void) {
  printf("%ld",_1027_main());
  return 0;
}
