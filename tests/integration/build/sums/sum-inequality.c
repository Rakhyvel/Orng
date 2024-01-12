/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

/* Function forward definitions */
int64_t _1488_main(void);

/* Function definitions */
int64_t _1488_main(void){
    int64_t _1488_t0;
    struct struct0 _1489_x;
    uint64_t _1488_t8;
    int64_t _1488_$retval;
    _1488_t0 = 211;
    _1489_x = (struct struct0) {.tag=0, ._0=_1488_t0};
    _1488_t8 = 0;
    $tag_check(_1488_t8, 0, "tests/integration/sums/sum-inequality.orng:4:20:\n    if x != .none {\n                  ^");
    _1488_$retval = _1489_x._0;
    return _1488_$retval;
}

int main(void) {
  printf("%ld",_1488_main());
  return 0;
}
