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
int64_t _1360_main(void);

/* Function definitions */
int64_t _1360_main(void){
    int64_t _1360_t1;
    int64_t _1360_t2;
    int64_t _1360_t3;
    int64_t _1360_t4;
    int64_t _1360_t5;
    struct0 _1361_x;
    int64_t _1360_t7;
    int64_t* _1360_t8;
    int64_t _1360_t9;
    struct1 _1361_y;
    int64_t _1360_t11;
    int64_t _1360_t12;
    int64_t _1360_$retval;
    _1360_t1 = 1;
    _1360_t2 = 2;
    _1360_t3 = 3;
    _1360_t4 = 4;
    _1360_t5 = 5;
    _1361_x = (struct0) {_1360_t1, _1360_t2, _1360_t3, _1360_t4, _1360_t5};
    _1360_t7 = 0;
    _1360_t8 = ((int64_t*)&_1361_x + _1360_t7);
    _1360_t9 = 5;
    _1361_y = (struct1) {_1360_t8, _1360_t9};
    _1360_t11 = 2;
    *((int64_t*)_1361_y._0 + _1360_t11) = 81;
    _1360_t12 = 2;
    _1360_$retval = *((int64_t*)_1361_y._0 + _1360_t12);
    return _1360_$retval;
}

int main(void) {
  printf("%ld",_1360_main());
  return 0;
}
