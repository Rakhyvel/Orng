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
int64_t _1095_main(void);

/* Function definitions */
int64_t _1095_main(void){
    int64_t _1095_t0;
    struct0 _1096_x;
    int64_t _1095_t3;
    uint64_t _1095_t5;
    int64_t _1095_$retval;
    _1095_t0 = 4;
    _1096_x = (struct0) {.tag=0, ._0=_1095_t0};
    _1096_x = (struct0) {.tag=1};
    _1095_t3 = 113;
    _1096_x = (struct0) {.tag=0, ._0=_1095_t3};
    _1095_t5 = 0;
    $tag_check(_1095_t5, 0, "tests/integration/optional/optional.orng:2:3:\nfn main() -> Int {\n ^");
    _1095_$retval = _1096_x._0;
    return _1095_$retval;
}

int main(void) {
  printf("%ld",_1095_main());
  return 0;
}
