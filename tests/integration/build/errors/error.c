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
int64_t _13_main(void);


/* Function definitions */
int64_t _13_main(void){
    int64_t _13_t0;
    struct struct0 _14_x;
    uint64_t _13_t3;
    int64_t _13_$retval;
    _13_t0 = 117;
    _14_x = (struct struct0) {.tag=1, ._1=_13_t0};
    _13_t3 = 1;
    $tag_check(_13_t3, 1, "tests/integration/errors/error.orng:2:3:\nfn main() -> Int {\n ^");
    _13_$retval = _14_x._1;
    return _13_$retval;
}


int main(void) {
  printf("%ld",_13_main());
  return 0;
}
