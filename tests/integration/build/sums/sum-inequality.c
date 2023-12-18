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
int64_t _1686_main(void);

/* Function definitions */
int64_t _1686_main(void){
    int64_t _1686_t0;
    struct0 _1687_x;
    uint64_t _1686_t8;
    int64_t _1686_$retval;
    _1686_t0 = 211;
    _1687_x = (struct0) {.tag=1, ._1=_1686_t0};
    _1686_t8 = 1;
    $tag_check(_1686_t8, 1, "tests/integration/sums/sum-inequality.orng:2:3:\nfn main() -> Int {\n ^");
    _1686_$retval = _1687_x._1;
    return _1686_$retval;
}

int main(void) {
  printf("%ld",_1686_main());
  return 0;
}
