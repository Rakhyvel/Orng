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
        uint8_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1658_main(void);

/* Function definitions */
int64_t _1658_main(void){
    int64_t _1658_t0;
    struct0 _1659_x;
    uint64_t _1658_t2;
    int64_t _1658_$retval;
    _1658_t0 = 104;
    _1659_x = (struct0) {.tag=0, ._0=_1658_t0};
    _1658_t2 = 0;
    $tag_check(_1658_t2, 0, "tests/integration/sums/namespace.orng:4:3:\nfn main() -> Int {\n ^");
    _1658_$retval = _1659_x._0;
    return _1658_$retval;
}

int main(void) {
  printf("%ld",_1658_main());
  return 0;
}
