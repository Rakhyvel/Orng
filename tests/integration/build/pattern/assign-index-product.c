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
int64_t _1035_main(void);

/* Function definitions */
int64_t _1035_main(void) {
    int64_t _1035_t1;
    int64_t _1035_t2;
    int64_t _1035_t3;
    struct0 _1036_x;
    int64_t _1035_t5;
    int64_t _1035_t6;
    struct1 _1035_t4;
    int64_t _1035_t8;
    int64_t _1035_t10;
    int64_t _1035_t12;
    int64_t _1035_t13;
    uint8_t _1035_t14;
    int64_t _1035_$retval;
    _1035_t1 = 0;
    _1035_t2 = 1;
    _1035_t3 = 2;
    _1036_x = (struct0) {_1035_t1, _1035_t2, _1035_t3};
    _1035_t5 = 1;
    _1035_t6 = 0;
    _1035_t4 = (struct1) {(*((int64_t*)&_1036_x + _1035_t5)), (*((int64_t*)&_1036_x + _1035_t6))};
    _1035_t8 = 0;
    *((int64_t*)&_1036_x + _1035_t8) = _1035_t4._0;
    _1035_t10 = 1;
    *((int64_t*)&_1036_x + _1035_t10) = _1035_t4._1;
    _1035_t12 = 0;
    _1035_t13 = 1;
    _1035_t14 = *((int64_t*)&_1036_x + _1035_t12) > *((int64_t*)&_1036_x + _1035_t13);
    if (_1035_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1035_$retval = 162;
    return _1035_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/pattern/assign-index-product.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1035_main());
  return 0;
}
