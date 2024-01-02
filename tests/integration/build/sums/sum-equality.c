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
int64_t _1459_main(void);

/* Function definitions */
int64_t _1459_main(void){
    int64_t _1459_t0;
    struct struct0 _1460_x;
    uint64_t _1459_t10;
    int64_t _1459_$retval;
    _1459_t0 = 210;
    _1460_x = (struct struct0) {.tag=0, ._0=_1459_t0};
    _1459_t10 = 0;
    $tag_check(_1459_t10, 0, "tests/integration/sums/sum-equality.orng:4:7:\n    if x == .none {\n     ^");
    _1459_$retval = _1460_x._0;
    return _1459_$retval;
}

int main(void) {
  printf("%ld",_1459_main());
  return 0;
}
