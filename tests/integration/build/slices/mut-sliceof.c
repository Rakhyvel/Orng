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
int64_t _1289_main(void);

/* Function definitions */
int64_t _1289_main(void){
    int64_t _1289_t1;
    int64_t _1289_t2;
    int64_t _1289_t3;
    int64_t _1289_t4;
    int64_t _1289_t5;
    struct0 _1290_x;
    int64_t _1289_t7;
    int64_t* _1289_t8;
    int64_t _1289_t9;
    struct1 _1290_y;
    int64_t _1289_t11;
    int64_t _1289_t12;
    int64_t _1289_$retval;
    _1289_t1 = 1;
    _1289_t2 = 2;
    _1289_t3 = 3;
    _1289_t4 = 4;
    _1289_t5 = 5;
    _1290_x = (struct0) {_1289_t1, _1289_t2, _1289_t3, _1289_t4, _1289_t5};
    _1289_t7 = 0;
    _1289_t8 = ((int64_t*)&_1290_x + _1289_t7);
    _1289_t9 = 5;
    _1290_y = (struct1) {_1289_t8, _1289_t9};
    _1289_t11 = 2;
    *((int64_t*)_1290_y._0 + _1289_t11) = 81;
    _1289_t12 = 2;
    _1289_$retval = *((int64_t*)_1290_y._0 + _1289_t12);
    return _1289_$retval;
}

int main(void) {
  printf("%ld",_1289_main());
  return 0;
}
