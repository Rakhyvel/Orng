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
int64_t _842_main(void);

/* Function definitions */
int64_t _842_main(void) {
    int64_t _842_t1;
    int64_t _842_t2;
    int64_t _842_t3;
    struct0 _843_x;
    int64_t _842_t5;
    int64_t _842_t6;
    struct1 _842_t4;
    int64_t _842_t8;
    int64_t _842_t10;
    int64_t _842_t12;
    int64_t _842_t13;
    uint8_t _842_t14;
    int64_t _842_$retval;
    _842_t1 = 0;
    _842_t2 = 1;
    _842_t3 = 2;
    _843_x = (struct0) {_842_t1, _842_t2, _842_t3};
    _842_t5 = 1;
    _842_t6 = 0;
    _842_t4 = (struct1) {(*((int64_t*)&_843_x + _842_t5)), (*((int64_t*)&_843_x + _842_t6))};
    _842_t8 = 0;
    *((int64_t*)&_843_x + _842_t8) = _842_t4._0;
    _842_t10 = 1;
    *((int64_t*)&_843_x + _842_t10) = _842_t4._1;
    _842_t12 = 0;
    _842_t13 = 1;
    _842_t14 = *((int64_t*)&_843_x + _842_t12) > *((int64_t*)&_843_x + _842_t13);
    if (_842_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _842_$retval = 162;
    return _842_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/pattern/assign-index-product.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_842_main());
  return 0;
}
