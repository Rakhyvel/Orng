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
int64_t _1156_main(void);


/* Function definitions */
int64_t _1156_main(void){
    int64_t _1156_t0;
    struct struct0 _1157_x;
    int64_t _1156_t4;
    uint64_t _1156_t6;
    int64_t _1156_$retval;
    _1156_t0 = 4;
    _1157_x = (struct struct0) {.tag=0, ._0=_1156_t0};
    _1157_x = (struct struct0) {.tag=1};
    _1156_t4 = 113;
    _1157_x = (struct struct0) {.tag=0, ._0=_1156_t4};
    _1156_t6 = 0;
    $tag_check(_1156_t6, 0, "tests/integration/optional/optional.orng:2:3:\nfn main() -> Int {\n ^");
    _1156_$retval = _1157_x._0;
    return _1156_$retval;
}


int main(void) {
  printf("%ld",_1156_main());
  return 0;
}
