/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

/* Function forward definitions */
int64_t _546_main(void);

/* Function definitions */
int64_t _546_main(void){
    int64_t _546_t0;
    struct struct0 _547_x;
    uint64_t _546_t2;
    int64_t _546_$retval;
    _546_t0 = 134;
    _547_x = (struct struct0) {.tag=0, ._0=_546_t0};
    _546_t2 = 0;
    $tag_check(_546_t2, 0, "tests/integration/default/default-sum-init.orng:2:3:\nfn main() -> Int {\n ^");
    _546_$retval = _547_x._0;
    return _546_$retval;
}

int main(void) {
  printf("%ld",_546_main());
  return 0;
}
