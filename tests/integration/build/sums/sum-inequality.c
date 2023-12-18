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
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1696_main(void);

/* Function definitions */
int64_t _1696_main(void){
    int64_t _1696_t0;
    struct0 _1697_x;
    uint64_t _1696_t8;
    int64_t _1696_$retval;
    _1696_t0 = 211;
    _1697_x = (struct0) {.tag=1, ._1=_1696_t0};
    _1696_t8 = 1;
    $tag_check(_1696_t8, 1, "tests/integration/sums/sum-inequality.orng:2:3:\nfn main() -> Int {\n ^");
    _1696_$retval = _1697_x._1;
    return _1696_$retval;
}

int main(void) {
  printf("%ld",_1696_main());
  return 0;
}
