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
int64_t _571_main(void);


/* Function definitions */
int64_t _571_main(void){
    int64_t _571_t0;
    struct struct0 _572_x;
    uint64_t _571_t2;
    int64_t _571_$retval;
    _571_t0 = 117;
    _572_x = (struct struct0) {.tag=1, ._1=_571_t0};
    _571_t2 = 1;
    $tag_check(_571_t2, 1, "tests/integration/errors/error.orng:2:3:\nfn main() -> Int {\n ^");
    _571_$retval = _572_x._1;
    return _571_$retval;
}


int main(void) {
  printf("%ld",_571_main());
  return 0;
}
