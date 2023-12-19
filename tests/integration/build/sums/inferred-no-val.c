/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1663_main(void);

/* Function definitions */
int64_t _1663_main(void){
    int64_t _1663_t0;
    struct0 _1664_x;
    uint64_t _1663_t3;
    int64_t _1663_t4;
    uint8_t _1663_t6;
    int64_t _1663_$retval;
    _1663_t0 = 0;
    _1664_x = (struct0) {.tag=0, ._0=_1663_t0};
    _1663_t3 = 0;
    _1663_t4 = 0;
    $tag_check(_1663_t3, 0, "tests/integration/sums/inferred-no-val.orng:3:10:\n    let x: (a: Int | b: Int) = .a\n        ^");
    _1663_t6 = _1664_x._0 == _1663_t4;
    if (_1663_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1663_$retval = 280;
    return _1663_$retval;
BB7:
    $lines[$line_idx++] = "tests/integration/sums/inferred-no-val.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1663_main());
  return 0;
}
