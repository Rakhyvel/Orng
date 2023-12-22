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
int64_t _1226_main(void);

/* Function definitions */
int64_t _1226_main(void){
    int64_t _1226_t2;
    int64_t _1226_t3;
    int64_t _1226_t4;
    struct0 _1226_t1;
    int64_t _1226_t5;
    uint8_t _1226_t6;
    int64_t _1229_x;
    int64_t _1229_y;
    int64_t _1226_t7;
    int64_t _1226_t8;
    int64_t _1226_$retval;
    _1226_t2 = 100;
    _1226_t3 = 60;
    _1226_t4 = 8;
    _1226_t1 = (struct0) {_1226_t2, _1226_t3, _1226_t4};
    _1226_t5 = 100;
    _1226_t6 = _1226_t1._0 == _1226_t5;
    if (_1226_t6) {
        goto BB1511;
    } else {
        goto BB1515;
    }
BB1511:
    _1229_x = _1226_t1._1;
    _1229_y = _1226_t1._2;
    _1226_t7 = 100;
    _1226_t8 = $add_int64_t(_1226_t7, _1229_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _1226_$retval = $add_int64_t(_1226_t8, _1229_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _1226_$retval;
BB1515:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1226_main());
  return 0;
}
