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
int64_t _10_main(void);

/* Function definitions */
int64_t _10_main(void) {
    int64_t _10_t1;
    int64_t _10_t2;
    int64_t _10_t3;
    struct0 _11_x;
    int64_t _10_t5;
    int64_t _10_t6;
    struct1 _10_t4;
    int64_t _10_t8;
    int64_t _10_t10;
    int64_t _10_t12;
    int64_t _10_t13;
    uint8_t _10_t14;
    int64_t _10_$retval;
    _10_t1 = 0;
    _10_t2 = 1;
    _10_t3 = 2;
    _11_x = (struct0) {_10_t1, _10_t2, _10_t3};
    _10_t5 = 1;
    _10_t6 = 0;
    _10_t4 = (struct1) {(*((int64_t*)&_11_x + _10_t5)), (*((int64_t*)&_11_x + _10_t6))};
    _10_t8 = 0;
    *((int64_t*)&_11_x + _10_t8) = _10_t4._0;
    _10_t10 = 1;
    *((int64_t*)&_11_x + _10_t10) = _10_t4._1;
    _10_t12 = 0;
    _10_t13 = 1;
    _10_t14 = *((int64_t*)&_11_x + _10_t12) > *((int64_t*)&_11_x + _10_t13);
    if (_10_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _10_$retval = 162;
    return _10_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/pattern/assign-index-product.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_10_main());
  return 0;
}
