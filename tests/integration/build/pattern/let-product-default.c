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

/* Function forward definitions */
int64_t _789_main(void);

/* Function definitions */
int64_t _789_main(void) {
    int64_t _789_t1;
    int64_t _789_t2;
    struct0 _789_t0;
    int64_t _790_a;
    int64_t _790_b;
    int64_t _789_t4;
    int64_t _789_t5;
    uint8_t _789_t7;
    int64_t _789_t3;
    int64_t _789_$retval;
    _789_t1 = 0;
    _789_t2 = 0;
    _789_t0 = (struct0) {_789_t1, _789_t2};
    _790_a = _789_t0._0;
    _790_b = _789_t0._1;
    _789_t4 = $add_int64_t(_790_a, _790_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _789_t5 = 0;
    _789_t7 = _789_t4 == _789_t5;
    if (_789_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _789_t3 = 160;
    goto BB6;
BB7:
    _789_t3 = 61;
    goto BB6;
BB6:
    _789_$retval = _789_t3;
    return _789_$retval;
}

int main(void) {
  printf("%ld",_789_main());
  return 0;
}
