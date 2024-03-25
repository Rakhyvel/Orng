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
int64_t _1466_main(void);


/* Function definitions */
int64_t _1466_main(void){
    int64_t _1466_t0;
    struct struct0 _1467_x;
    uint64_t _1466_t4;
    int64_t _1466_t5;
    uint8_t _1466_t7;
    int64_t _1466_$retval;
    _1466_t0 = 0;
    _1467_x = (struct struct0) {.tag=0, ._0=_1466_t0};
    _1466_t4 = 0;
    _1466_t5 = 0;
    $tag_check(_1466_t4, 0, "tests/integration/sums/inferred-no-val.orng:3:10:\n    let x: (a: Int | b: Int) = .a\n        ^");
    _1466_t7 = _1467_x._0==_1466_t5;
    if (_1466_t7) {
        goto BB1692;
    } else {
        goto BB1696;
    }
BB1692:
    _1466_$retval = 280;
    return _1466_$retval;
BB1696:
    $lines[$line_idx++] = "tests/integration/sums/inferred-no-val.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1466_main());
  return 0;
}
