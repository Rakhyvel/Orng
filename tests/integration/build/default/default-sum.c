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
    };
};

/* Function forward definitions */
int64_t _597_main(void);


/* Function definitions */
int64_t _597_main(void){
    int64_t _597_t0;
    struct struct0 _598_x;
    uint64_t _597_t4;
    int64_t _597_t5;
    uint8_t _597_t7;
    int64_t _597_t3;
    int64_t _597_$retval;
    _597_t0 = 0;
    _598_x = (struct struct0) {.tag=0, ._0=_597_t0};
    _597_t4 = 0;
    _597_t5 = 0;
    $tag_check(_597_t4, 0, "tests/integration/default/default-sum.orng:3:10:\n    let x: (a: Int | b | c)\n        ^");
    _597_t7 = _598_x._0==_597_t5;
    if (_597_t7) {
        goto BB681;
    } else {
        goto BB685;
    }
BB681:
    _597_t3 = 133;
    goto BB684;
BB685:
    _597_t3 = 0;
    goto BB684;
BB684:
    _597_$retval = _597_t3;
    return _597_$retval;
}


int main(void) {
  printf("%ld",_597_main());
  return 0;
}
