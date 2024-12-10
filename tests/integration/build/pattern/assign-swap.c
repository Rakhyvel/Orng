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
int64_t _1257_main(void);


/* Function definitions */
int64_t _1257_main(void){
    int64_t _1257_t1;
    int64_t _1257_t2;
    struct struct0 _1257_t0;
    int64_t _1258_x;
    int64_t _1258_y;
    struct struct0 _1257_t4;
    int64_t _1257_t6;
    uint8_t _1257_t8;
    int64_t _1257_$retval;
    int64_t _1257_t9;
    uint8_t _1257_t11;
    _1257_t1 = 1;
    _1257_t2 = 2;
    _1257_t0 = (struct struct0) {_1257_t1, _1257_t2};
    _1258_x = _1257_t0._0;
    _1258_y = _1257_t0._1;
    _1257_t4 = (struct struct0) {_1258_x, _1258_y};
    _1258_y = _1257_t4._0;
    _1258_x = _1257_t4._1;
    _1257_t6 = 1;
    _1257_t8 = _1258_y==_1257_t6;
    if (_1257_t8) {
        goto BB1427;
    } else {
        goto BB1434;
    }
BB1427:
    _1257_t9 = 2;
    _1257_t11 = _1258_x==_1257_t9;
    if (_1257_t11) {
        goto BB1430;
    } else {
        goto BB1434;
    }
BB1434:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1430:
    _1257_$retval = 159;
    return _1257_$retval;
}


int main(void) {
  printf("%ld",_1257_main());
  return 0;
}
