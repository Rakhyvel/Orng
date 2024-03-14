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
int64_t _578_main(void);


/* Function definitions */
int64_t _578_main(void){
    int64_t _578_t0;
    struct struct0 _579_x;
    uint64_t _578_t4;
    int64_t _578_t5;
    uint8_t _578_t7;
    int64_t _578_t3;
    int64_t _578_$retval;
    _578_t0 = 0;
    _579_x = (struct struct0) {.tag=0, ._0=_578_t0};
    _578_t4 = 0;
    _578_t5 = 0;
    $tag_check(_578_t4, 0, "tests/integration/default/default-sum.orng:3:10:\n    let x: (a: Int | b | c)\n        ^");
    _578_t7 = _579_x._0==_578_t5;
    if (_578_t7) {
        goto BB665;
    } else {
        goto BB669;
    }
BB665:
    _578_t3 = 133;
    goto BB668;
BB669:
    _578_t3 = 0;
    goto BB668;
BB668:
    _578_$retval = _578_t3;
    return _578_$retval;
}


int main(void) {
  printf("%ld",_578_main());
  return 0;
}
