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
int64_t _1456_main(void);


/* Function definitions */
int64_t _1456_main(void){
    int64_t _1456_t0;
    struct struct0 _1457_x;
    uint64_t _1456_t3;
    int64_t _1456_t4;
    uint8_t _1456_t6;
    int64_t _1456_$retval;
    _1456_t0 = 0;
    _1457_x = (struct struct0) {.tag=0, ._0=_1456_t0};
    _1456_t3 = 0;
    _1456_t4 = 0;
    $tag_check(_1456_t3, 0, "tests/integration/sums/inferred-no-val.orng:3:10:\n    let x: (a: Int | b: Int) = .a\n        ^");
    _1456_t6 = _1457_x._0==_1456_t4;
    if (_1456_t6) {
        goto BB1719;
    } else {
        goto BB1723;
    }
BB1719:
    _1456_$retval = 280;
    return _1456_$retval;
BB1723:
    $lines[$line_idx++] = "tests/integration/sums/inferred-no-val.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1456_main());
  return 0;
}
