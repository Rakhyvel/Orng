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
int64_t _1106_main(void);

/* Function definitions */
int64_t _1106_main(void){
    int64_t _1106_t0;
    struct struct0 _1107_x;
    int64_t _1106_t3;
    uint64_t _1106_t5;
    int64_t _1106_$retval;
    _1106_t0 = 4;
    _1107_x = (struct struct0) {.tag=0, ._0=_1106_t0};
    _1107_x = (struct struct0) {.tag=1};
    _1106_t3 = 113;
    _1107_x = (struct struct0) {.tag=0, ._0=_1106_t3};
    _1106_t5 = 0;
    $tag_check(_1106_t5, 0, "tests/integration/optional/optional.orng:2:3:\nfn main() -> Int {\n ^");
    _1106_$retval = _1107_x._0;
    return _1106_$retval;
}

int main(void) {
  printf("%ld",_1106_main());
  return 0;
}
