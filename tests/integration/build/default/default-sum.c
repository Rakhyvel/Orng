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
    };
} struct0;

/* Function forward definitions */
int64_t _647_main(void);

/* Function definitions */
int64_t _647_main(void){
    int64_t _647_t0;
    struct0 _648_x;
    uint64_t _647_t3;
    int64_t _647_t4;
    uint8_t _647_t6;
    int64_t _647_t2;
    int64_t _647_$retval;
    _647_t0 = 0;
    _648_x = (struct0) {.tag=0, ._0=_647_t0};
    _647_t3 = 0;
    _647_t4 = 0;
    $tag_check(_647_t3, 0, "tests/integration/default/default-sum.orng:3:10:\n    let x: (a: Int | b | c)\n        ^");
    _647_t6 = _648_x._0 == _647_t4;
    if (_647_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _647_t2 = 133;
    goto BB6;
BB7:
    _647_t2 = 0;
    goto BB6;
BB6:
    _647_$retval = _647_t2;
    return _647_$retval;
}

int main(void) {
  printf("%ld",_647_main());
  return 0;
}
