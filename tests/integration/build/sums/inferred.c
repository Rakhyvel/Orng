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
        uint8_t _1;
    };
};

/* Function forward definitions */
int64_t _1442_main(void);

/* Function definitions */
int64_t _1442_main(void){
    int64_t _1442_t0;
    struct struct0 _1443_x;
    uint64_t _1442_t2;
    int64_t _1442_$retval;
    _1442_t0 = 101;
    _1443_x = (struct struct0) {.tag=0, ._0=_1442_t0};
    _1442_t2 = 0;
    $tag_check(_1442_t2, 0, "tests/integration/sums/inferred.orng:2:3:\nfn main() -> Int {\n ^");
    _1442_$retval = _1443_x._0;
    return _1442_$retval;
}

int main(void) {
  printf("%ld",_1442_main());
  return 0;
}
