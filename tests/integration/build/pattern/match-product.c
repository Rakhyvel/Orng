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
int64_t _1171_main(void);

/* Function definitions */
int64_t _1171_main(void) {
    int64_t _1171_t2;
    int64_t _1171_t3;
    int64_t _1171_t4;
    struct0 _1171_t1;
    int64_t _1171_t5;
    uint8_t _1171_t6;
    int64_t _1174_x;
    int64_t _1174_y;
    int64_t _1171_t7;
    int64_t _1171_t8;
    int64_t _1171_$retval;
    _1171_t2 = 100;
    _1171_t3 = 60;
    _1171_t4 = 8;
    _1171_t1 = (struct0) {_1171_t2, _1171_t3, _1171_t4};
    _1171_t5 = 100;
    _1171_t6 = _1171_t1._0 == _1171_t5;
    if (_1171_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1174_x = _1171_t1._1;
    _1174_y = _1171_t1._2;
    _1171_t7 = 100;
    _1171_t8 = $add_int64_t(_1171_t7, _1174_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _1171_$retval = $add_int64_t(_1171_t8, _1174_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _1171_$retval;
BB7:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1171_main());
  return 0;
}
