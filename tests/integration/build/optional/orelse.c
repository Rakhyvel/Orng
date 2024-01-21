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
int64_t _1129_main(void);

/* Function definitions */
int64_t _1129_main(void){
    int64_t _1129_t1;
    struct struct0 _1130_y;
    int64_t _1129_t3;
    int64_t _1129_t7;
    int64_t _1129_$retval;
    _1129_t1 = 100;
    _1130_y = (struct struct0) {.tag=0, ._0=_1129_t1};
    _1129_t3 = _1130_y._0;
    _1129_t7 = 14;
    _1129_$retval = $add_int64_t(_1129_t3, _1129_t7, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _1129_$retval;
}

int main(void) {
  printf("%ld",_1129_main());
  return 0;
}
