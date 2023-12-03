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
int64_t _976_main(void);

/* Function definitions */
int64_t _976_main(void) {
    int64_t _976_t1;
    int64_t _976_t2;
    int64_t _976_t3;
    int64_t _976_t4;
    int64_t _976_t5;
    struct0 _977_x;
    int64_t _976_t7;
    int64_t* _976_t8;
    int64_t _976_t9;
    struct1 _977_y;
    int64_t _976_t11;
    int64_t _976_t12;
    int64_t _976_$retval;
    _976_t1 = 1;
    _976_t2 = 2;
    _976_t3 = 3;
    _976_t4 = 4;
    _976_t5 = 5;
    _977_x = (struct0) {_976_t1, _976_t2, _976_t3, _976_t4, _976_t5};
    _976_t7 = 0;
    _976_t8 = ((int64_t*)&_977_x + _976_t7);
    _976_t9 = 5;
    _977_y = (struct1) {_976_t8, _976_t9};
    _976_t11 = 2;
    *((int64_t*)_977_y._0 + _976_t11) = 81;
    _976_t12 = 2;
    _976_$retval = *((int64_t*)_977_y._0 + _976_t12);
    return _976_$retval;
}

int main(void) {
  printf("%ld",_976_main());
  return 0;
}
