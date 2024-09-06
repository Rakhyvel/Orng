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
int64_t _1194_main(void);


/* Function definitions */
int64_t _1194_main(void){
    int64_t _1194_t0;
    struct struct0 _1195_x;
    int64_t _1194_t5;
    uint64_t _1194_t7;
    int64_t _1194_$retval;
    _1194_t0 = 4;
    _1195_x = (struct struct0) {.tag=0, ._0=_1194_t0};
    _1195_x = (struct struct0) {.tag=1};
    _1194_t5 = 113;
    _1195_x = (struct struct0) {.tag=0, ._0=_1194_t5};
    _1194_t7 = 0;
    $tag_check(_1194_t7, 0, "tests/integration/optional/optional.orng:2:8:\nfn main() -> Int {\n      ^");
    _1194_$retval = _1195_x._0;
    return _1194_$retval;
}


int main(void) {
  printf("%ld",_1194_main());
  return 0;
}
