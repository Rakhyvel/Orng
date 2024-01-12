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
int64_t _1124_main(void);

/* Function definitions */
int64_t _1124_main(void){
    int64_t _1124_t1;
    struct struct0 _1125_y;
    int64_t _1124_t3;
    int64_t _1124_t7;
    int64_t _1124_$retval;
    _1124_t1 = 100;
    _1125_y = (struct struct0) {.tag=0, ._0=_1124_t1};
    _1124_t3 = _1125_y._0;
    _1124_t7 = 14;
    _1124_$retval = $add_int64_t(_1124_t3, _1124_t7, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _1124_$retval;
}

int main(void) {
  printf("%ld",_1124_main());
  return 0;
}
