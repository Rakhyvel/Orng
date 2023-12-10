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
    int64_t _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _815_main(void);

/* Function definitions */
int64_t _815_main(void) {
    int64_t _815_t1;
    int64_t _815_t2;
    int64_t _815_t3;
    struct0 _816_x;
    int64_t _815_t5;
    int64_t _815_t6;
    struct1 _815_t4;
    int64_t _815_t8;
    int64_t _815_t10;
    int64_t _815_t12;
    int64_t _815_t13;
    uint8_t _815_t14;
    int64_t _815_$retval;
    _815_t1 = 0;
    _815_t2 = 1;
    _815_t3 = 2;
    _816_x = (struct0) {_815_t1, _815_t2, _815_t3};
    _815_t5 = 1;
    _815_t6 = 0;
    _815_t4 = (struct1) {(*((int64_t*)&_816_x + _815_t5)), (*((int64_t*)&_816_x + _815_t6))};
    _815_t8 = 0;
    *((int64_t*)&_816_x + _815_t8) = _815_t4._0;
    _815_t10 = 1;
    *((int64_t*)&_816_x + _815_t10) = _815_t4._1;
    _815_t12 = 0;
    _815_t13 = 1;
    _815_t14 = *((int64_t*)&_816_x + _815_t12) > *((int64_t*)&_816_x + _815_t13);
    if (_815_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _815_$retval = 162;
    return _815_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/pattern/assign-index-product.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_815_main());
  return 0;
}
