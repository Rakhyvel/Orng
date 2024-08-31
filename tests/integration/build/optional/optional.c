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
int64_t _1136_main(void);


/* Function definitions */
int64_t _1136_main(void){
    int64_t _1136_t0;
    struct struct0 _1137_x;
    int64_t _1136_t4;
    uint64_t _1136_t6;
    int64_t _1136_$retval;
    _1136_t0 = 4;
    _1137_x = (struct struct0) {.tag=0, ._0=_1136_t0};
    _1137_x = (struct struct0) {.tag=1};
    _1136_t4 = 113;
    _1137_x = (struct struct0) {.tag=0, ._0=_1136_t4};
    _1136_t6 = 0;
    $tag_check(_1136_t6, 0, "tests/integration/optional/optional.orng:2:3:\nfn main() -> Int {\n ^");
    _1136_$retval = _1137_x._0;
    return _1136_$retval;
}


int main(void) {
  printf("%ld",_1136_main());
  return 0;
}
