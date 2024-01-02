/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
};

/* Function forward definitions */
int64_t _1436_main(void);

/* Function definitions */
int64_t _1436_main(void){
    int64_t _1436_t0;
    struct struct0 _1437_x;
    uint64_t _1436_t3;
    int64_t _1436_t4;
    uint8_t _1436_t6;
    int64_t _1436_$retval;
    _1436_t0 = 0;
    _1437_x = (struct struct0) {.tag=0, ._0=_1436_t0};
    _1436_t3 = 0;
    _1436_t4 = 0;
    $tag_check(_1436_t3, 0, "tests/integration/sums/inferred-no-val.orng:3:10:\n    let x: (a: Int | b: Int) = .a\n        ^");
    _1436_t6 = _1437_x._0==_1436_t4;
    if (_1436_t6) {
        goto BB1699;
    } else {
        goto BB1703;
    }
BB1699:
    _1436_$retval = 280;
    return _1436_$retval;
BB1703:
    $lines[$line_idx++] = "tests/integration/sums/inferred-no-val.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1436_main());
  return 0;
}
