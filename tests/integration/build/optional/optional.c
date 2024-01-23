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
int64_t _1126_main(void);


/* Function definitions */
int64_t _1126_main(void){
    int64_t _1126_t0;
    struct struct0 _1127_x;
    int64_t _1126_t3;
    uint64_t _1126_t5;
    int64_t _1126_$retval;
    _1126_t0 = 4;
    _1127_x = (struct struct0) {.tag=0, ._0=_1126_t0};
    _1127_x = (struct struct0) {.tag=1};
    _1126_t3 = 113;
    _1127_x = (struct struct0) {.tag=0, ._0=_1126_t3};
    _1126_t5 = 0;
    $tag_check(_1126_t5, 0, "tests/integration/optional/optional.orng:2:3:\nfn main() -> Int {\n ^");
    _1126_$retval = _1127_x._0;
    return _1126_$retval;
}


int main(void) {
  printf("%ld",_1126_main());
  return 0;
}
