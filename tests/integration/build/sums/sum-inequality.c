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
int64_t _1503_main(void);


/* Function definitions */
int64_t _1503_main(void){
    int64_t _1503_t0;
    struct struct0 _1504_x;
    uint64_t _1503_t9;
    int64_t _1503_$retval;
    _1503_t0 = 211;
    _1504_x = (struct struct0) {.tag=0, ._0=_1503_t0};
    _1503_t9 = 0;
    $tag_check(_1503_t9, 0, "tests/integration/sums/sum-inequality.orng:4:20:\n    if x != .none {\n                  ^");
    _1503_$retval = _1504_x._0;
    return _1503_$retval;
}


int main(void) {
  printf("%ld",_1503_main());
  return 0;
}
