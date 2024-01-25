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
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
};

/* Function forward definitions */
int64_t _1483_main(void);


/* Function definitions */
int64_t _1483_main(void){
    int64_t _1483_t0;
    struct struct0 _1484_x;
    uint64_t _1483_t3;
    int64_t _1483_t4;
    uint8_t _1483_t6;
    int64_t _1483_$retval;
    _1483_t0 = 0;
    _1484_x = (struct struct0) {.tag=0, ._0=_1483_t0};
    _1483_t3 = 0;
    _1483_t4 = 0;
    $tag_check(_1483_t3, 0, "tests/integration/sums/inferred-no-val.orng:3:10:\n    let x: (a: Int | b: Int) = .a\n        ^");
    _1483_t6 = _1484_x._0==_1483_t4;
    if (_1483_t6) {
        goto BB1741;
    } else {
        goto BB1745;
    }
BB1741:
    _1483_$retval = 280;
    return _1483_$retval;
BB1745:
    $lines[$line_idx++] = "tests/integration/sums/inferred-no-val.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1483_main());
  return 0;
}
