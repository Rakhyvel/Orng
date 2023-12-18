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
int64_t _575_main(void);

/* Function definitions */
int64_t _575_main(void){
    int64_t _575_t0;
    struct0 _576_x;
    uint64_t _575_t2;
    int64_t _575_$retval;
    _575_t0 = 139;
    _576_x = (struct0) {.tag=0, ._0=_575_t0};
    _575_t2 = 0;
    $tag_check(_575_t2, 0, "tests/integration/default/default-error.orng:2:3:\nfn main() -> Int {\n ^");
    _575_$retval = _576_x._0;
    return _575_$retval;
}

int main(void) {
  printf("%ld",_575_main());
  return 0;
}
