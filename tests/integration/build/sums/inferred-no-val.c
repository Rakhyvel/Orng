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
int64_t _1441_main(void);

/* Function definitions */
int64_t _1441_main(void){
    int64_t _1441_t0;
    struct struct0 _1442_x;
    uint64_t _1441_t3;
    int64_t _1441_t4;
    uint8_t _1441_t6;
    int64_t _1441_$retval;
    _1441_t0 = 0;
    _1442_x = (struct struct0) {.tag=0, ._0=_1441_t0};
    _1441_t3 = 0;
    _1441_t4 = 0;
    $tag_check(_1441_t3, 0, "tests/integration/sums/inferred-no-val.orng:3:10:\n    let x: (a: Int | b: Int) = .a\n        ^");
    _1441_t6 = _1442_x._0==_1441_t4;
    if (_1441_t6) {
        goto BB1703;
    } else {
        goto BB1707;
    }
BB1703:
    _1441_$retval = 280;
    return _1441_$retval;
BB1707:
    $lines[$line_idx++] = "tests/integration/sums/inferred-no-val.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1441_main());
  return 0;
}
