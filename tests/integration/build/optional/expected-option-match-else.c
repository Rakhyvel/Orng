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
int64_t _1124_main(void);


/* Function definitions */
int64_t _1124_main(void){
    int64_t _1124_t10;
    struct struct0 _1125_x;
    uint64_t _1124_t12;
    int64_t _1124_$retval;
    _1124_t10 = 128;
    _1125_x = (struct struct0) {.tag=0, ._0=_1124_t10};
    _1124_t12 = 0;
    $tag_check(_1124_t12, 0, "tests/integration/optional/expected-option-match-else.orng:2:3:\nfn main() -> Int {\n ^");
    _1124_$retval = _1125_x._0;
    return _1124_$retval;
}


int main(void) {
  printf("%ld",_1124_main());
  return 0;
}
