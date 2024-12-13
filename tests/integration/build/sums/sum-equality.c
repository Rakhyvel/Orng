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
int64_t _1603_main(void);


/* Function definitions */
int64_t _1603_main(void){
    int64_t _1603_t0;
    struct struct0 _1604_x;
    uint64_t _1603_t12;
    int64_t _1603_$retval;
    _1603_t0 = 210;
    _1604_x = (struct struct0) {.tag=0, ._0=_1603_t0};
    _1603_t12 = 0;
    $tag_check(_1603_t12, 0, "tests/integration/sums/sum-equality.orng:4:7:\n    if x == .none {\n     ^");
    _1603_$retval = _1604_x._0;
    return _1603_$retval;
}


int main(void) {
  printf("%ld",_1603_main());
  return 0;
}
