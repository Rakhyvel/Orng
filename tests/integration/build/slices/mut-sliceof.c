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
int64_t _910_main(void);

/* Function definitions */
int64_t _910_main(void) {
    int64_t _910_t1;
    int64_t _910_t2;
    int64_t _910_t3;
    int64_t _910_t4;
    int64_t _910_t5;
    struct0 _911_x;
    int64_t _910_t7;
    int64_t* _910_t8;
    int64_t _910_t9;
    struct1 _911_y;
    int64_t _910_t11;
    int64_t _910_t12;
    int64_t _910_$retval;
    _910_t1 = 1;
    _910_t2 = 2;
    _910_t3 = 3;
    _910_t4 = 4;
    _910_t5 = 5;
    _911_x = (struct0) {_910_t1, _910_t2, _910_t3, _910_t4, _910_t5};
    _910_t7 = 0;
    _910_t8 = ((int64_t*)&_911_x + _910_t7);
    _910_t9 = 5;
    _911_y = (struct1) {_910_t8, _910_t9};
    _910_t11 = 2;
    *((int64_t*)_911_y._0 + _910_t11) = 81;
    _910_t12 = 2;
    _910_$retval = *((int64_t*)_911_y._0 + _910_t12);
    return _910_$retval;
}

int main(void) {
  printf("%ld",_910_main());
  return 0;
}
