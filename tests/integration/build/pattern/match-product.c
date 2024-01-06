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
int64_t _1251_main(void);

/* Function definitions */
int64_t _1251_main(void){
    int64_t _1251_t2;
    int64_t _1251_t3;
    int64_t _1251_t4;
    struct struct0 _1251_t1;
    int64_t _1251_t5;
    uint8_t _1251_t6;
    int64_t _1254_x;
    int64_t _1254_y;
    int64_t _1251_t7;
    int64_t _1251_t8;
    int64_t _1251_$retval;
    _1251_t2 = 100;
    _1251_t3 = 60;
    _1251_t4 = 8;
    _1251_t1 = (struct struct0) {_1251_t2, _1251_t3, _1251_t4};
    _1251_t5 = 100;
    _1251_t6 = _1251_t1._0==_1251_t5;
    if (_1251_t6) {
        goto BB1487;
    } else {
        goto BB1491;
    }
BB1487:
    _1254_x = _1251_t1._1;
    _1254_y = _1251_t1._2;
    _1251_t7 = 100;
    _1251_t8 = $add_int64_t(_1251_t7, _1254_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _1251_$retval = $add_int64_t(_1251_t8, _1254_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _1251_$retval;
BB1491:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:35:\n        _           => unreachable\n                                 ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1251_main());
  return 0;
}
