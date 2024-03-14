/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1296_main(void);


/* Function definitions */
int64_t _1296_main(void){
    int64_t _1296_t2;
    int64_t _1296_t3;
    int64_t _1296_t4;
    struct struct0 _1296_t1;
    int64_t _1296_t5;
    uint8_t _1296_t6;
    int64_t _1299_x;
    int64_t _1299_y;
    int64_t _1296_t7;
    int64_t _1296_t8;
    int64_t _1296_$retval;
    _1296_t2 = 100;
    _1296_t3 = 60;
    _1296_t4 = 8;
    _1296_t1 = (struct struct0) {_1296_t2, _1296_t3, _1296_t4};
    _1296_t5 = 100;
    _1296_t6 = _1296_t1._0==_1296_t5;
    if (_1296_t6) {
        goto BB1519;
    } else {
        goto BB1523;
    }
BB1519:
    _1299_x = _1296_t1._1;
    _1299_y = _1296_t1._2;
    _1296_t7 = 100;
    _1296_t8 = $add_int64_t(_1296_t7, _1299_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _1296_$retval = $add_int64_t(_1296_t8, _1299_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _1296_$retval;
BB1523:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:35:\n        _           => unreachable\n                                 ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1296_main());
  return 0;
}
