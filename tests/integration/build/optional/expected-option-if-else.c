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
int64_t _1063_main(void);

/* Function definitions */
int64_t _1063_main(void){
    int64_t _1063_t0;
    struct struct0 _1064_x;
    uint64_t _1063_t2;
    int64_t _1063_$retval;
    _1063_t0 = 125;
    _1064_x = (struct struct0) {.tag=0, ._0=_1063_t0};
    _1063_t2 = 0;
    $tag_check(_1063_t2, 0, "tests/integration/optional/expected-option-if-else.orng:2:3:\nfn main() -> Int {\n ^");
    _1063_$retval = _1064_x._0;
    return _1063_$retval;
}

int main(void) {
  printf("%ld",_1063_main());
  return 0;
}
