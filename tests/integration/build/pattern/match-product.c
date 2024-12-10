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
int64_t _1368_main(void);


/* Function definitions */
int64_t _1368_main(void){
    int64_t _1368_t2;
    int64_t _1368_t3;
    int64_t _1368_t4;
    struct struct0 _1368_t1;
    int64_t _1368_t5;
    uint8_t _1368_t6;
    int64_t _1371_x;
    int64_t _1371_y;
    int64_t _1368_t7;
    int64_t _1368_t8;
    int64_t _1368_$retval;
    _1368_t2 = 100;
    _1368_t3 = 60;
    _1368_t4 = 8;
    _1368_t1 = (struct struct0) {_1368_t2, _1368_t3, _1368_t4};
    _1368_t5 = 100;
    _1368_t6 = _1368_t1._0==_1368_t5;
    if (_1368_t6) {
        goto BB1579;
    } else {
        goto BB1583;
    }
BB1579:
    _1371_x = _1368_t1._1;
    _1371_y = _1368_t1._2;
    _1368_t7 = 100;
    _1368_t8 = $add_int64_t(_1368_t7, _1371_x, "tests/integration/pattern/match-product.orng:4:29:\n        (100, x, y) => 100 + x + y\n                           ^");
    _1368_$retval = $add_int64_t(_1368_t8, _1371_y, "tests/integration/pattern/match-product.orng:4:33:\n        (100, x, y) => 100 + x + y\n                               ^");
    return _1368_$retval;
BB1583:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:35:\n        _           => unreachable\n                                 ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1368_main());
  return 0;
}
