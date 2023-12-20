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
        double _1;
    };
} struct0;

/* Function forward definitions */
int64_t _493_main(void);

/* Function definitions */
int64_t _493_main(void){
    int64_t _493_t0;
    struct0 _494_x;
    uint64_t _493_t2;
    int64_t _493_$retval;
    _493_t0 = 139;
    _494_x = (struct0) {.tag=0, ._0=_493_t0};
    _493_t2 = 0;
    $tag_check(_493_t2, 0, "tests/integration/default/default-error.orng:2:3:\nfn main() -> Int {\n ^");
    _493_$retval = _494_x._0;
    return _493_$retval;
}

int main(void) {
  printf("%ld",_493_main());
  return 0;
}
