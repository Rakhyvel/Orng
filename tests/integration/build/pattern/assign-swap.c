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
int64_t _1155_main(void);


/* Function definitions */
int64_t _1155_main(void){
    int64_t _1155_t1;
    int64_t _1155_t2;
    struct struct0 _1155_t0;
    int64_t _1156_x;
    int64_t _1156_y;
    struct struct0 _1155_t3;
    int64_t _1155_t5;
    uint8_t _1155_t7;
    int64_t _1155_$retval;
    int64_t _1155_t8;
    uint8_t _1155_t10;
    _1155_t1 = 1;
    _1155_t2 = 2;
    _1155_t0 = (struct struct0) {_1155_t1, _1155_t2};
    _1156_x = _1155_t0._0;
    _1156_y = _1155_t0._1;
    _1155_t3 = (struct struct0) {_1156_x, _1156_y};
    _1156_y = _1155_t3._0;
    _1156_x = _1155_t3._1;
    _1155_t5 = 1;
    _1155_t7 = _1156_y==_1155_t5;
    if (_1155_t7) {
        goto BB1351;
    } else {
        goto BB1358;
    }
BB1351:
    _1155_t8 = 2;
    _1155_t10 = _1156_x==_1155_t8;
    if (_1155_t10) {
        goto BB1354;
    } else {
        goto BB1358;
    }
BB1358:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB1354:
    _1155_$retval = 159;
    return _1155_$retval;
}


int main(void) {
  printf("%ld",_1155_main());
  return 0;
}
