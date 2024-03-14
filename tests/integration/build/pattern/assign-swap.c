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
};

/* Function forward definitions */
int64_t _1185_main(void);


/* Function definitions */
int64_t _1185_main(void){
    int64_t _1185_t1;
    int64_t _1185_t2;
    struct struct0 _1185_t0;
    int64_t _1186_x;
    int64_t _1186_y;
    struct struct0 _1185_t4;
    int64_t _1185_t6;
    uint8_t _1185_t8;
    int64_t _1185_$retval;
    int64_t _1185_t9;
    uint8_t _1185_t11;
    _1185_t1 = 1;
    _1185_t2 = 2;
    _1185_t0 = (struct struct0) {_1185_t1, _1185_t2};
    _1186_x = _1185_t0._0;
    _1186_y = _1185_t0._1;
    _1185_t4 = (struct struct0) {_1186_x, _1186_y};
    _1186_y = _1185_t4._0;
    _1186_x = _1185_t4._1;
    _1185_t6 = 1;
    _1185_t8 = _1186_y==_1185_t6;
    if (_1185_t8) {
        goto BB1367;
    } else {
        goto BB1374;
    }
BB1367:
    _1185_t9 = 2;
    _1185_t11 = _1186_x==_1185_t9;
    if (_1185_t11) {
        goto BB1370;
    } else {
        goto BB1374;
    }
BB1374:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1370:
    _1185_$retval = 159;
    return _1185_$retval;
}


int main(void) {
  printf("%ld",_1185_main());
  return 0;
}
