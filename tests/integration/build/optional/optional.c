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
int64_t _1208_main(void);


/* Function definitions */
int64_t _1208_main(void){
    int64_t _1208_t0;
    struct struct0 _1209_x;
    int64_t _1208_t5;
    uint64_t _1208_t7;
    int64_t _1208_$retval;
    _1208_t0 = 4;
    _1209_x = (struct struct0) {.tag=0, ._0=_1208_t0};
    _1209_x = (struct struct0) {.tag=1};
    _1208_t5 = 113;
    _1209_x = (struct struct0) {.tag=0, ._0=_1208_t5};
    _1208_t7 = 0;
    $tag_check(_1208_t7, 0, "tests/integration/optional/optional.orng:2:8:\nfn main() -> Int {\n      ^");
    _1208_$retval = _1209_x._0;
    return _1208_$retval;
}


int main(void) {
  printf("%ld",_1208_main());
  return 0;
}
