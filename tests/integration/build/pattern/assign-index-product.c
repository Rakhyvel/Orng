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
int64_t _833_main(void);

/* Function definitions */
int64_t _833_main(void) {
    int64_t _833_t1;
    int64_t _833_t2;
    int64_t _833_t3;
    struct0 _834_x;
    int64_t _833_t5;
    int64_t _833_t6;
    struct1 _833_t4;
    int64_t _833_t8;
    int64_t _833_t10;
    int64_t _833_t12;
    int64_t _833_t13;
    uint8_t _833_t14;
    int64_t _833_$retval;
    _833_t1 = 0;
    _833_t2 = 1;
    _833_t3 = 2;
    _834_x = (struct0) {_833_t1, _833_t2, _833_t3};
    _833_t5 = 1;
    _833_t6 = 0;
    _833_t4 = (struct1) {(*((int64_t*)&_834_x + _833_t5)), (*((int64_t*)&_834_x + _833_t6))};
    _833_t8 = 0;
    *((int64_t*)&_834_x + _833_t8) = _833_t4._0;
    _833_t10 = 1;
    *((int64_t*)&_834_x + _833_t10) = _833_t4._1;
    _833_t12 = 0;
    _833_t13 = 1;
    _833_t14 = *((int64_t*)&_834_x + _833_t12) > *((int64_t*)&_834_x + _833_t13);
    if (_833_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _833_$retval = 162;
    return _833_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/pattern/assign-index-product.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_833_main());
  return 0;
}
