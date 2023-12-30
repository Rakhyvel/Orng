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
int64_t _1106_main(void);

/* Function definitions */
int64_t _1106_main(void){
    int64_t _1106_t1;
    struct0 _1107_y;
    int64_t _1106_t3;
    int64_t _1106_t7;
    int64_t _1106_$retval;
    _1106_t1 = 100;
    _1107_y = (struct0) {.tag=0, ._0=_1106_t1};
    _1106_t3 = _1107_y._0;
    _1106_t7 = 14;
    _1106_$retval = $add_int64_t(_1106_t3, _1106_t7, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _1106_$retval;
}

int main(void) {
  printf("%ld",_1106_main());
  return 0;
}
