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
        double _1;
    };
};

/* Function forward definitions */
int64_t _502_main(void);

/* Function definitions */
int64_t _502_main(void){
    int64_t _502_t0;
    struct struct0 _503_x;
    uint64_t _502_t2;
    int64_t _502_$retval;
    _502_t0 = 139;
    _503_x = (struct struct0) {.tag=0, ._0=_502_t0};
    _502_t2 = 0;
    $tag_check(_502_t2, 0, "tests/integration/default/default-error.orng:2:3:\nfn main() -> Int {\n ^");
    _502_$retval = _503_x._0;
    return _502_$retval;
}

int main(void) {
  printf("%ld",_502_main());
  return 0;
}
