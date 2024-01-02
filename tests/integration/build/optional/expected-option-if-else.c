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
int64_t _1066_main(void);

/* Function definitions */
int64_t _1066_main(void){
    int64_t _1066_t0;
    struct struct0 _1067_x;
    uint64_t _1066_t2;
    int64_t _1066_$retval;
    _1066_t0 = 125;
    _1067_x = (struct struct0) {.tag=0, ._0=_1066_t0};
    _1066_t2 = 0;
    $tag_check(_1066_t2, 0, "tests/integration/optional/expected-option-if-else.orng:2:3:\nfn main() -> Int {\n ^");
    _1066_$retval = _1067_x._0;
    return _1066_$retval;
}

int main(void) {
  printf("%ld",_1066_main());
  return 0;
}
