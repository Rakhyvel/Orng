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
int64_t _551_main(void);


/* Function definitions */
int64_t _551_main(void){
    int64_t _551_t0;
    struct struct0 _552_x;
    uint64_t _551_t3;
    int64_t _551_t4;
    uint8_t _551_t6;
    int64_t _551_t2;
    int64_t _551_$retval;
    _551_t0 = 0;
    _552_x = (struct struct0) {.tag=0, ._0=_551_t0};
    _551_t3 = 0;
    _551_t4 = 0;
    $tag_check(_551_t3, 0, "tests/integration/default/default-sum.orng:3:10:\n    let x: (a: Int | b | c)\n        ^");
    _551_t6 = _552_x._0==_551_t4;
    if (_551_t6) {
        goto BB650;
    } else {
        goto BB654;
    }
BB650:
    _551_t2 = 133;
    goto BB653;
BB654:
    _551_t2 = 0;
    goto BB653;
BB653:
    _551_$retval = _551_t2;
    return _551_$retval;
}


int main(void) {
  printf("%ld",_551_main());
  return 0;
}
