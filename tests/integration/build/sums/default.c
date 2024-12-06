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
        uint8_t _1;
    };
};

/* Function forward definitions */
int64_t _1530_main(void);


/* Function definitions */
int64_t _1530_main(void){
    int64_t _1530_t0;
    struct struct0 _1531_x;
    uint64_t _1530_t3;
    int64_t _1530_$retval;
    _1530_t0 = 102;
    _1531_x = (struct struct0) {.tag=0, ._0=_1530_t0};
    _1530_t3 = 0;
    $tag_check(_1530_t3, 0, "tests/integration/sums/default.orng:4:8:\nfn main() -> Int {\n      ^");
    _1530_$retval = _1531_x._0;
    return _1530_$retval;
}


int main(void) {
  printf("%ld",_1530_main());
  return 0;
}
