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
int64_t _1681_main(void);

/* Function definitions */
int64_t _1681_main(void){
    int64_t _1681_t0;
    struct0 _1682_x;
    uint64_t _1681_t11;
    int64_t _1681_$retval;
    _1681_t0 = 210;
    _1682_x = (struct0) {.tag=1, ._1=_1681_t0};
    _1681_t11 = 1;
    $tag_check(_1681_t11, 1, "tests/integration/sums/sum-equality.orng:2:3:\nfn main() -> Int {\n ^");
    _1681_$retval = _1682_x._1;
    return _1681_$retval;
}

int main(void) {
  printf("%ld",_1681_main());
  return 0;
}
