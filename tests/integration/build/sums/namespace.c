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
int64_t _1531_main(void);


/* Function definitions */
int64_t _1531_main(void){
    int64_t _1531_t0;
    struct struct0 _1532_x;
    uint64_t _1531_t3;
    int64_t _1531_$retval;
    _1531_t0 = 104;
    _1532_x = (struct struct0) {.tag=0, ._0=_1531_t0};
    _1531_t3 = 0;
    $tag_check(_1531_t3, 0, "tests/integration/sums/namespace.orng:4:8:\nfn main() -> Int {\n      ^");
    _1531_$retval = _1532_x._0;
    return _1531_$retval;
}


int main(void) {
  printf("%ld",_1531_main());
  return 0;
}
