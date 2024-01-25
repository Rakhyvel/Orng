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
int64_t _573_main(void);


/* Function definitions */
int64_t _573_main(void){
    int64_t _573_t0;
    struct struct0 _574_x;
    uint64_t _573_t2;
    int64_t _573_$retval;
    _573_t0 = 134;
    _574_x = (struct struct0) {.tag=0, ._0=_573_t0};
    _573_t2 = 0;
    $tag_check(_573_t2, 0, "tests/integration/default/default-sum-init.orng:2:3:\nfn main() -> Int {\n ^");
    _573_$retval = _574_x._0;
    return _573_$retval;
}


int main(void) {
  printf("%ld",_573_main());
  return 0;
}
