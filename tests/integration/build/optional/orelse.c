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
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1098_main(void);

/* Function definitions */
int64_t _1098_main(void){
    int64_t _1098_t1;
    struct0 _1099_y;
    int64_t _1098_t3;
    int64_t _1098_t7;
    int64_t _1098_$retval;
    _1098_t1 = 100;
    _1099_y = (struct0) {.tag=1, ._1=_1098_t1};
    _1098_t3 = _1099_y._1;
    _1098_t7 = 14;
    _1098_$retval = $add_int64_t(_1098_t3, _1098_t7, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _1098_$retval;
}

int main(void) {
  printf("%ld",_1098_main());
  return 0;
}
