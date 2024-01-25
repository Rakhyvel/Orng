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
int64_t _1182_main(void);


/* Function definitions */
int64_t _1182_main(void){
    int64_t _1182_t1;
    int64_t _1182_t2;
    struct struct0 _1182_t0;
    int64_t _1183_x;
    int64_t _1183_y;
    struct struct0 _1182_t3;
    int64_t _1182_t5;
    uint8_t _1182_t7;
    int64_t _1182_$retval;
    int64_t _1182_t8;
    uint8_t _1182_t10;
    _1182_t1 = 1;
    _1182_t2 = 2;
    _1182_t0 = (struct struct0) {_1182_t1, _1182_t2};
    _1183_x = _1182_t0._0;
    _1183_y = _1182_t0._1;
    _1182_t3 = (struct struct0) {_1183_x, _1183_y};
    _1183_y = _1182_t3._0;
    _1183_x = _1182_t3._1;
    _1182_t5 = 1;
    _1182_t7 = _1183_y==_1182_t5;
    if (_1182_t7) {
        goto BB1373;
    } else {
        goto BB1380;
    }
BB1373:
    _1182_t8 = 2;
    _1182_t10 = _1183_x==_1182_t8;
    if (_1182_t10) {
        goto BB1376;
    } else {
        goto BB1380;
    }
BB1380:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1376:
    _1182_$retval = 159;
    return _1182_$retval;
}


int main(void) {
  printf("%ld",_1182_main());
  return 0;
}
