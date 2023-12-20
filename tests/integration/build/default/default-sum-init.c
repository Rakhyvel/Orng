/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
    };
} struct0;

/* Function forward definitions */
int64_t _537_main(void);

/* Function definitions */
int64_t _537_main(void){
    int64_t _537_t0;
    struct0 _538_x;
    uint64_t _537_t2;
    int64_t _537_$retval;
    _537_t0 = 134;
    _538_x = (struct0) {.tag=0, ._0=_537_t0};
    _537_t2 = 0;
    $tag_check(_537_t2, 0, "tests/integration/default/default-sum-init.orng:2:3:\nfn main() -> Int {\n ^");
    _537_$retval = _538_x._0;
    return _537_$retval;
}

int main(void) {
  printf("%ld",_537_main());
  return 0;
}
