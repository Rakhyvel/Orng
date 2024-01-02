/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1246_main(void);

/* Function definitions */
int64_t _1246_main(void){
    int64_t _1246_t2;
    int64_t _1246_t3;
    int64_t _1246_t4;
    struct struct0 _1246_t1;
    int64_t _1246_t5;
    uint8_t _1246_t6;
    int64_t _1249_x;
    int64_t _1249_y;
    int64_t _1246_t7;
    int64_t _1246_t8;
    int64_t _1246_$retval;
    _1246_t2 = 100;
    _1246_t3 = 60;
    _1246_t4 = 8;
    _1246_t1 = (struct struct0) {_1246_t2, _1246_t3, _1246_t4};
    _1246_t5 = 100;
    _1246_t6 = _1246_t1._0==_1246_t5;
    if (_1246_t6) {
        goto BB1483;
    } else {
        goto BB1487;
    }
BB1483:
    _1249_x = _1246_t1._1;
    _1249_y = _1246_t1._2;
    _1246_t7 = 100;
    _1246_t8 = $add_int64_t(_1246_t7, _1249_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _1246_$retval = $add_int64_t(_1246_t8, _1249_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _1246_$retval;
BB1487:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:35:\n        _           => unreachable\n                                 ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1246_main());
  return 0;
}
