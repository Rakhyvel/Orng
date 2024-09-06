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
int64_t _585_main(void);


/* Function definitions */
int64_t _585_main(void){
    int64_t _585_t0;
    struct struct0 _586_x;
    uint64_t _585_t4;
    int64_t _585_t5;
    uint8_t _585_t7;
    int64_t _585_t3;
    int64_t _585_$retval;
    _585_t0 = 0;
    _586_x = (struct struct0) {.tag=0, ._0=_585_t0};
    _585_t4 = 0;
    _585_t5 = 0;
    $tag_check(_585_t4, 0, "tests/integration/default/default-sum.orng:3:10:\n    let x: (a: Int | b | c)\n        ^");
    _585_t7 = _586_x._0==_585_t5;
    if (_585_t7) {
        goto BB668;
    } else {
        goto BB672;
    }
BB668:
    _585_t3 = 133;
    goto BB671;
BB672:
    _585_t3 = 0;
    goto BB671;
BB671:
    _585_$retval = _585_t3;
    return _585_$retval;
}


int main(void) {
  printf("%ld",_585_main());
  return 0;
}
