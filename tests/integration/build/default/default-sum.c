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
int64_t _599_main(void);


/* Function definitions */
int64_t _599_main(void){
    int64_t _599_t0;
    struct struct0 _600_x;
    uint64_t _599_t4;
    int64_t _599_t5;
    uint8_t _599_t7;
    int64_t _599_t3;
    int64_t _599_$retval;
    _599_t0 = 0;
    _600_x = (struct struct0) {.tag=0, ._0=_599_t0};
    _599_t4 = 0;
    _599_t5 = 0;
    $tag_check(_599_t4, 0, "tests/integration/default/default-sum.orng:3:10:\n    let x: (a: Int | b | c)\n        ^");
    _599_t7 = _600_x._0==_599_t5;
    if (_599_t7) {
        goto BB683;
    } else {
        goto BB687;
    }
BB683:
    _599_t3 = 133;
    goto BB686;
BB687:
    _599_t3 = 0;
    goto BB686;
BB686:
    _599_$retval = _599_t3;
    return _599_$retval;
}


int main(void) {
  printf("%ld",_599_main());
  return 0;
}
