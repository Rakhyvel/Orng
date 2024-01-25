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
int64_t _1520_main(void);


/* Function definitions */
int64_t _1520_main(void){
    int64_t _1520_t0;
    struct struct0 _1521_x;
    uint64_t _1520_t8;
    int64_t _1520_$retval;
    _1520_t0 = 211;
    _1521_x = (struct struct0) {.tag=0, ._0=_1520_t0};
    _1520_t8 = 0;
    $tag_check(_1520_t8, 0, "tests/integration/sums/sum-inequality.orng:4:20:\n    if x != .none {\n                  ^");
    _1520_$retval = _1521_x._0;
    return _1520_$retval;
}


int main(void) {
  printf("%ld",_1520_main());
  return 0;
}
