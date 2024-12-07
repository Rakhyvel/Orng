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
int64_t _1568_main(void);


/* Function definitions */
int64_t _1568_main(void){
    int64_t _1568_t0;
    struct struct0 _1569_x;
    uint64_t _1568_t3;
    int64_t _1568_$retval;
    _1568_t0 = 104;
    _1569_x = (struct struct0) {.tag=0, ._0=_1568_t0};
    _1568_t3 = 0;
    $tag_check(_1568_t3, 0, "tests/integration/sums/namespace.orng:4:8:\nfn main() -> Int {\n      ^");
    _1568_$retval = _1569_x._0;
    return _1568_$retval;
}


int main(void) {
  printf("%ld",_1568_main());
  return 0;
}
