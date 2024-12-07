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
int64_t _1538_main(void);


/* Function definitions */
int64_t _1538_main(void){
    int64_t _1538_t0;
    struct struct0 _1539_x;
    uint64_t _1538_t3;
    int64_t _1538_$retval;
    _1538_t0 = 102;
    _1539_x = (struct struct0) {.tag=0, ._0=_1538_t0};
    _1538_t3 = 0;
    $tag_check(_1538_t3, 0, "tests/integration/sums/default.orng:4:8:\nfn main() -> Int {\n      ^");
    _1538_$retval = _1539_x._0;
    return _1538_$retval;
}


int main(void) {
  printf("%ld",_1538_main());
  return 0;
}
