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

/* Function forward definitions */
int64_t _929_main(void);

/* Function definitions */
int64_t _929_main(void) {
    int64_t _929_t2;
    int64_t _929_t3;
    int64_t _929_t4;
    struct0 _929_t1;
    int64_t _929_t5;
    uint8_t _929_t6;
    int64_t _932_x;
    int64_t _932_y;
    int64_t _929_t7;
    int64_t _929_t8;
    int64_t _929_$retval;
    _929_t2 = 100;
    _929_t3 = 60;
    _929_t4 = 8;
    _929_t1 = (struct0) {_929_t2, _929_t3, _929_t4};
    _929_t5 = 100;
    _929_t6 = _929_t1._0 == _929_t5;
    if (_929_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _932_x = _929_t1._1;
    _932_y = _929_t1._2;
    _929_t7 = 100;
    _929_t8 = $add_int64_t(_929_t7, _932_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _929_$retval = $add_int64_t(_929_t8, _932_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _929_$retval;
BB7:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_929_main());
  return 0;
}
