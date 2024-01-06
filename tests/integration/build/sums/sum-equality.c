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
int64_t _1464_main(void);

/* Function definitions */
int64_t _1464_main(void){
    int64_t _1464_t0;
    struct struct0 _1465_x;
    uint64_t _1464_t10;
    int64_t _1464_$retval;
    _1464_t0 = 210;
    _1465_x = (struct struct0) {.tag=0, ._0=_1464_t0};
    _1464_t10 = 0;
    $tag_check(_1464_t10, 0, "tests/integration/sums/sum-equality.orng:4:7:\n    if x == .none {\n     ^");
    _1464_$retval = _1465_x._0;
    return _1464_$retval;
}

int main(void) {
  printf("%ld",_1464_main());
  return 0;
}
