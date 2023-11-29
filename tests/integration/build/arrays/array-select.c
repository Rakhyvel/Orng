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
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
    struct0 _2;
} struct1;

/* Function forward definitions */
int64_t _76_main(void);

/* Function definitions */
int64_t _76_main(void) {
    int64_t _76_t2;
    int64_t _76_t3;
    struct0 _76_t1;
    int64_t _76_t5;
    int64_t _76_t6;
    struct0 _76_t4;
    int64_t _76_t8;
    int64_t _76_t9;
    struct0 _76_t7;
    struct1 _77_x;
    int64_t _76_t11;
    int64_t _76_t12;
    int64_t _76_$retval;
    _76_t2 = 1;
    _76_t3 = 2;
    _76_t1 = (struct0) {_76_t2, _76_t3};
    _76_t5 = 3;
    _76_t6 = 4;
    _76_t4 = (struct0) {_76_t5, _76_t6};
    _76_t8 = 5;
    _76_t9 = 6;
    _76_t7 = (struct0) {_76_t8, _76_t9};
    _77_x = (struct1) {_76_t1, _76_t4, _76_t7};
    _76_t11 = 1;
    (*((struct0*)&_77_x + _76_t11))._0 = 73;
    _76_t12 = 1;
    _76_$retval = (*((struct0*)&_77_x + _76_t12))._0;
    return _76_$retval;
}

int main(void) {
  printf("%ld",_76_main());
  return 0;
}
