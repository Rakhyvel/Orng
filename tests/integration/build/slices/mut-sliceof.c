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
int64_t _941_main(void);

/* Function definitions */
int64_t _941_main(void) {
    int64_t _941_t1;
    int64_t _941_t2;
    int64_t _941_t3;
    int64_t _941_t4;
    int64_t _941_t5;
    struct0 _942_x;
    int64_t _941_t7;
    int64_t* _941_t8;
    int64_t _941_t9;
    struct1 _942_y;
    int64_t _941_t11;
    int64_t _941_t12;
    int64_t _941_$retval;
    _941_t1 = 1;
    _941_t2 = 2;
    _941_t3 = 3;
    _941_t4 = 4;
    _941_t5 = 5;
    _942_x = (struct0) {_941_t1, _941_t2, _941_t3, _941_t4, _941_t5};
    _941_t7 = 0;
    _941_t8 = ((int64_t*)&_942_x + _941_t7);
    _941_t9 = 5;
    _942_y = (struct1) {_941_t8, _941_t9};
    _941_t11 = 2;
    *((int64_t*)_942_y._0 + _941_t11) = 81;
    _941_t12 = 2;
    _941_$retval = *((int64_t*)_942_y._0 + _941_t12);
    return _941_$retval;
}

int main(void) {
  printf("%ld",_941_main());
  return 0;
}
