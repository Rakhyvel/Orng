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
int64_t _1165_main(void);


/* Function definitions */
int64_t _1165_main(void){
    int64_t _1165_t10;
    struct struct0 _1166_x;
    uint64_t _1165_t13;
    int64_t _1165_$retval;
    goto BB1335;
BB1335:
    _1165_t10 = 128;
    _1166_x = (struct struct0) {.tag=0, ._0=_1165_t10};
    _1165_t13 = 0;
    $tag_check(_1165_t13, 0, "tests/integration/optional/expected-option-match-else.orng:2:8:\nfn main() -> Int {\n      ^");
    _1165_$retval = _1166_x._0;
    return _1165_$retval;
}


int main(void) {
  printf("%ld",_1165_main());
  return 0;
}
