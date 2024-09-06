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
int64_t _1186_main(void);


/* Function definitions */
int64_t _1186_main(void){
    int64_t _1186_t0;
    struct struct0 _1187_x;
    int64_t _1186_t5;
    uint64_t _1186_t7;
    int64_t _1186_$retval;
    _1186_t0 = 4;
    _1187_x = (struct struct0) {.tag=0, ._0=_1186_t0};
    _1187_x = (struct struct0) {.tag=1};
    _1186_t5 = 113;
    _1187_x = (struct struct0) {.tag=0, ._0=_1186_t5};
    _1186_t7 = 0;
    $tag_check(_1186_t7, 0, "tests/integration/optional/optional.orng:2:8:\nfn main() -> Int {\n      ^");
    _1186_$retval = _1187_x._0;
    return _1186_$retval;
}


int main(void) {
  printf("%ld",_1186_main());
  return 0;
}
