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
int64_t _1562_main(void);


/* Function definitions */
int64_t _1562_main(void){
    int64_t _1562_t0;
    struct struct0 _1563_x;
    uint64_t _1562_t12;
    int64_t _1562_$retval;
    _1562_t0 = 210;
    _1563_x = (struct struct0) {.tag=0, ._0=_1562_t0};
    _1562_t12 = 0;
    $tag_check(_1562_t12, 0, "tests/integration/sums/sum-equality.orng:4:7:\n    if x == .none {\n     ^");
    _1562_$retval = _1563_x._0;
    return _1562_$retval;
}


int main(void) {
  printf("%ld",_1562_main());
  return 0;
}
