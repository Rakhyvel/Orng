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
int64_t _1092_main(void);

/* Function definitions */
int64_t _1092_main(void){
    int64_t _1092_t10;
    struct struct0 _1093_x;
    uint64_t _1092_t12;
    int64_t _1092_$retval;
    _1092_t10 = 128;
    _1093_x = (struct struct0) {.tag=0, ._0=_1092_t10};
    _1092_t12 = 0;
    $tag_check(_1092_t12, 0, "tests/integration/optional/expected-option-match-else.orng:2:3:\nfn main() -> Int {\n ^");
    _1092_$retval = _1093_x._0;
    return _1092_$retval;
}

int main(void) {
  printf("%ld",_1092_main());
  return 0;
}
