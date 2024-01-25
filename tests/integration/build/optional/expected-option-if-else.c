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
int64_t _1113_main(void);


/* Function definitions */
int64_t _1113_main(void){
    int64_t _1113_t0;
    struct struct0 _1114_x;
    uint64_t _1113_t2;
    int64_t _1113_$retval;
    _1113_t0 = 125;
    _1114_x = (struct struct0) {.tag=0, ._0=_1113_t0};
    _1113_t2 = 0;
    $tag_check(_1113_t2, 0, "tests/integration/optional/expected-option-if-else.orng:2:3:\nfn main() -> Int {\n ^");
    _1113_$retval = _1114_x._0;
    return _1113_$retval;
}


int main(void) {
  printf("%ld",_1113_main());
  return 0;
}
