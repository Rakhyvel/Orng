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
int64_t _959_main(void);

/* Function definitions */
int64_t _959_main(void) {
    int64_t _959_t2;
    int64_t _959_t3;
    int64_t _959_t4;
    struct0 _959_t1;
    int64_t _959_t5;
    uint8_t _959_t6;
    int64_t _962_x;
    int64_t _962_y;
    int64_t _959_t7;
    int64_t _959_t8;
    int64_t _959_$retval;
    _959_t2 = 100;
    _959_t3 = 60;
    _959_t4 = 8;
    _959_t1 = (struct0) {_959_t2, _959_t3, _959_t4};
    _959_t5 = 100;
    _959_t6 = _959_t1._0 == _959_t5;
    if (_959_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _962_x = _959_t1._1;
    _962_y = _959_t1._2;
    _959_t7 = 100;
    _959_t8 = $add_int64_t(_959_t7, _962_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _959_$retval = $add_int64_t(_959_t8, _962_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _959_$retval;
BB7:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_959_main());
  return 0;
}
