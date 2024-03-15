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
int64_t _572_main(void);


/* Function definitions */
int64_t _572_main(void){
    int64_t _572_t0;
    struct struct0 _573_x;
    uint64_t _572_t3;
    int64_t _572_$retval;
    _572_t0 = 134;
    _573_x = (struct struct0) {.tag=0, ._0=_572_t0};
    _572_t3 = 0;
    $tag_check(_572_t3, 0, "tests/integration/default/default-sum-init.orng:2:3:\nfn main() -> Int {\n ^");
    _572_$retval = _573_x._0;
    return _572_$retval;
}


int main(void) {
  printf("%ld",_572_main());
  return 0;
}
