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
        uint32_t _0;
        int64_t _1;
    };
};

/* Function forward definitions */
int64_t _598_main(void);


/* Function definitions */
int64_t _598_main(void){
    int64_t _598_t0;
    struct struct0 _599_x;
    uint64_t _598_t3;
    int64_t _598_$retval;
    _598_t0 = 117;
    _599_x = (struct struct0) {.tag=1, ._1=_598_t0};
    _598_t3 = 1;
    $tag_check(_598_t3, 1, "tests/integration/errors/error.orng:2:3:\nfn main() -> Int {\n ^");
    _598_$retval = _599_x._1;
    return _598_$retval;
}


int main(void) {
  printf("%ld",_598_main());
  return 0;
}
