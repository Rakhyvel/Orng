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
int64_t _1086_main(void);

/* Function definitions */
int64_t _1086_main(void){
    int64_t _1086_t0;
    struct struct0 _1087_x;
    uint64_t _1086_t2;
    int64_t _1086_$retval;
    _1086_t0 = 125;
    _1087_x = (struct struct0) {.tag=0, ._0=_1086_t0};
    _1086_t2 = 0;
    $tag_check(_1086_t2, 0, "tests/integration/optional/expected-option-if-else.orng:2:3:\nfn main() -> Int {\n ^");
    _1086_$retval = _1087_x._0;
    return _1086_$retval;
}

int main(void) {
  printf("%ld",_1086_main());
  return 0;
}
