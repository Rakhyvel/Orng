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
int64_t _1578_main(void);


/* Function definitions */
int64_t _1578_main(void){
    int64_t _1578_t0;
    struct struct0 _1579_x;
    uint64_t _1578_t4;
    uint64_t _1578_t5;
    int64_t _1578_$retval;
    _1578_t0 = 4;
    _1579_x = (struct struct0) {.tag=0, ._0=_1578_t0};
    _1578_t4 = 0;
    $tag_check(_1578_t4, 0, "tests/integration/sums/re-assign.orng:6:16:\n    x.int = 103\n              ^");
    _1579_x._0 = 103;
    _1578_t5 = _1579_x.tag;
    $tag_check(_1578_t5, 0, "tests/integration/sums/re-assign.orng:4:8:\nfn main() -> Int {\n      ^");
    _1578_$retval = _1579_x._0;
    return _1578_$retval;
}


int main(void) {
  printf("%ld",_1578_main());
  return 0;
}
