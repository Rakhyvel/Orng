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
        uint8_t _1;
    };
};

/* Function forward definitions */
int64_t _1463_main(void);


/* Function definitions */
int64_t _1463_main(void){
    int64_t _1463_t0;
    struct struct0 _1464_x;
    uint64_t _1463_t2;
    int64_t _1463_$retval;
    _1463_t0 = 102;
    _1464_x = (struct struct0) {.tag=0, ._0=_1463_t0};
    _1463_t2 = 0;
    $tag_check(_1463_t2, 0, "tests/integration/sums/default.orng:4:3:\nfn main() -> Int {\n ^");
    _1463_$retval = _1464_x._0;
    return _1463_$retval;
}


int main(void) {
  printf("%ld",_1463_main());
  return 0;
}
