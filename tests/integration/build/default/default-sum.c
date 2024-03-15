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
int64_t _577_main(void);


/* Function definitions */
int64_t _577_main(void){
    int64_t _577_t0;
    struct struct0 _578_x;
    uint64_t _577_t4;
    int64_t _577_t5;
    uint8_t _577_t7;
    int64_t _577_t3;
    int64_t _577_$retval;
    _577_t0 = 0;
    _578_x = (struct struct0) {.tag=0, ._0=_577_t0};
    _577_t4 = 0;
    _577_t5 = 0;
    $tag_check(_577_t4, 0, "tests/integration/default/default-sum.orng:3:10:\n    let x: (a: Int | b | c)\n        ^");
    _577_t7 = _578_x._0==_577_t5;
    if (_577_t7) {
        goto BB662;
    } else {
        goto BB666;
    }
BB662:
    _577_t3 = 133;
    goto BB665;
BB666:
    _577_t3 = 0;
    goto BB665;
BB665:
    _577_$retval = _577_t3;
    return _577_$retval;
}


int main(void) {
  printf("%ld",_577_main());
  return 0;
}
