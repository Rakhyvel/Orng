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
int64_t _580_main(void);


/* Function definitions */
int64_t _580_main(void){
    int64_t _580_t0;
    struct struct0 _581_x;
    uint64_t _580_t3;
    int64_t _580_$retval;
    _580_t0 = 134;
    _581_x = (struct struct0) {.tag=0, ._0=_580_t0};
    _580_t3 = 0;
    $tag_check(_580_t3, 0, "tests/integration/default/default-sum-init.orng:2:8:\nfn main() -> Int {\n      ^");
    _580_$retval = _581_x._0;
    return _580_$retval;
}


int main(void) {
  printf("%ld",_580_main());
  return 0;
}
