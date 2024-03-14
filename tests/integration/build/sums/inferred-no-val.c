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
int64_t _1491_main(void);


/* Function definitions */
int64_t _1491_main(void){
    int64_t _1491_t0;
    struct struct0 _1492_x;
    uint64_t _1491_t4;
    int64_t _1491_t5;
    uint8_t _1491_t7;
    int64_t _1491_$retval;
    _1491_t0 = 0;
    _1492_x = (struct struct0) {.tag=0, ._0=_1491_t0};
    _1491_t4 = 0;
    _1491_t5 = 0;
    $tag_check(_1491_t4, 0, "tests/integration/sums/inferred-no-val.orng:3:10:\n    let x: (a: Int | b: Int) = .a\n        ^");
    _1491_t7 = _1492_x._0==_1491_t5;
    if (_1491_t7) {
        goto BB1739;
    } else {
        goto BB1743;
    }
BB1739:
    _1491_$retval = 280;
    return _1491_$retval;
BB1743:
    $lines[$line_idx++] = "tests/integration/sums/inferred-no-val.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1491_main());
  return 0;
}
