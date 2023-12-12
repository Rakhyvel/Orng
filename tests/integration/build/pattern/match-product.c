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
int64_t _937_main(void);

/* Function definitions */
int64_t _937_main(void) {
    int64_t _937_t2;
    int64_t _937_t3;
    int64_t _937_t4;
    struct0 _937_t1;
    int64_t _937_t5;
    uint8_t _937_t6;
    int64_t _940_x;
    int64_t _940_y;
    int64_t _937_t7;
    int64_t _937_t8;
    int64_t _937_$retval;
    _937_t2 = 100;
    _937_t3 = 60;
    _937_t4 = 8;
    _937_t1 = (struct0) {_937_t2, _937_t3, _937_t4};
    _937_t5 = 100;
    _937_t6 = _937_t1._0 == _937_t5;
    if (_937_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _940_x = _937_t1._1;
    _940_y = _937_t1._2;
    _937_t7 = 100;
    _937_t8 = $add_int64_t(_937_t7, _940_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _937_$retval = $add_int64_t(_937_t8, _940_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _937_$retval;
BB7:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_937_main());
  return 0;
}
