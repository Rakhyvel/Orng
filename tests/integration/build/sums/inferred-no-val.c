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
int64_t _1408_main(void);

/* Function definitions */
int64_t _1408_main(void){
    int64_t _1408_t0;
    struct0 _1409_x;
    uint64_t _1408_t3;
    int64_t _1408_t4;
    uint8_t _1408_t6;
    int64_t _1408_$retval;
    _1408_t0 = 0;
    _1409_x = (struct0) {.tag=0, ._0=_1408_t0};
    _1408_t3 = 0;
    _1408_t4 = 0;
    $tag_check(_1408_t3, 0, "tests/integration/sums/inferred-no-val.orng:3:10:\n    let x: (a: Int | b: Int) = .a\n        ^");
    _1408_t6 = _1409_x._0 == _1408_t4;
    if (_1408_t6) {
        goto BB1727;
    } else {
        goto BB1731;
    }
BB1727:
    _1408_$retval = 280;
    return _1408_$retval;
BB1731:
    $lines[$line_idx++] = "tests/integration/sums/inferred-no-val.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1408_main());
  return 0;
}
