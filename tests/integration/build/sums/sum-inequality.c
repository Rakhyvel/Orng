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
int64_t _1445_main(void);

/* Function definitions */
int64_t _1445_main(void){
    int64_t _1445_t0;
    struct0 _1446_x;
    uint64_t _1445_t8;
    int64_t _1445_$retval;
    _1445_t0 = 211;
    _1446_x = (struct0) {.tag=0, ._0=_1445_t0};
    _1445_t8 = 0;
    $tag_check(_1445_t8, 0, "tests/integration/sums/sum-inequality.orng:4:20:\n    if x != .none {\n                  ^");
    _1445_$retval = _1446_x._0;
    return _1445_$retval;
}

int main(void) {
  printf("%ld",_1445_main());
  return 0;
}
