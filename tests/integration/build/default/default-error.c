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
        double _1;
    };
};

/* Function forward definitions */
int64_t _529_main(void);


/* Function definitions */
int64_t _529_main(void){
    int64_t _529_t0;
    struct struct0 _530_x;
    uint64_t _529_t2;
    int64_t _529_$retval;
    _529_t0 = 139;
    _530_x = (struct struct0) {.tag=0, ._0=_529_t0};
    _529_t2 = 0;
    $tag_check(_529_t2, 0, "tests/integration/default/default-error.orng:2:3:\nfn main() -> Int {\n ^");
    _529_$retval = _530_x._0;
    return _529_$retval;
}


int main(void) {
  printf("%ld",_529_main());
  return 0;
}
