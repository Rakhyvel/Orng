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
int64_t _602_main(void);


/* Function definitions */
int64_t _602_main(void){
    int64_t _602_t0;
    struct struct0 _603_x;
    uint64_t _602_t3;
    int64_t _602_$retval;
    _602_t0 = 117;
    _603_x = (struct struct0) {.tag=1, ._1=_602_t0};
    _602_t3 = 1;
    $tag_check(_602_t3, 1, "tests/integration/errors/error.orng:2:8:\nfn main() -> Int {\n      ^");
    _602_$retval = _603_x._1;
    return _602_$retval;
}


int main(void) {
  printf("%ld",_602_main());
  return 0;
}
