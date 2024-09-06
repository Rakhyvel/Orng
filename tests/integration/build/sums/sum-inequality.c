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
int64_t _1576_main(void);


/* Function definitions */
int64_t _1576_main(void){
    int64_t _1576_t0;
    struct struct0 _1577_x;
    uint64_t _1576_t10;
    int64_t _1576_$retval;
    _1576_t0 = 211;
    _1577_x = (struct struct0) {.tag=0, ._0=_1576_t0};
    _1576_t10 = 0;
    $tag_check(_1576_t10, 0, "tests/integration/sums/sum-inequality.orng:4:20:\n    if x != .none {\n                  ^");
    _1576_$retval = _1577_x._0;
    return _1576_$retval;
}


int main(void) {
  printf("%ld",_1576_main());
  return 0;
}
