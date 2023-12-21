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
int64_t _1431_main(void);

/* Function definitions */
int64_t _1431_main(void){
    int64_t _1431_t0;
    struct0 _1432_x;
    uint64_t _1431_t10;
    int64_t _1431_$retval;
    _1431_t0 = 210;
    _1432_x = (struct0) {.tag=1, ._1=_1431_t0};
    _1431_t10 = 1;
    $tag_check(_1431_t10, 1, "tests/integration/sums/sum-equality.orng:4:7:\n    if x == .none {\n     ^");
    _1431_$retval = _1432_x._1;
    return _1431_$retval;
}

int main(void) {
  printf("%ld",_1431_main());
  return 0;
}
