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
int64_t _1050_main(void);

/* Function definitions */
int64_t _1050_main(void){
    int64_t _1050_t0;
    struct0 _1051_x;
    uint64_t _1050_t2;
    int64_t _1050_$retval;
    _1050_t0 = 125;
    _1051_x = (struct0) {.tag=0, ._0=_1050_t0};
    _1050_t2 = 0;
    $tag_check(_1050_t2, 0, "tests/integration/optional/expected-option-if-else.orng:2:3:\nfn main() -> Int {\n ^");
    _1050_$retval = _1051_x._0;
    return _1050_$retval;
}

int main(void) {
  printf("%ld",_1050_main());
  return 0;
}
