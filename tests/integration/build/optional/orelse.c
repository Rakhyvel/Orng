/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

/* Function forward definitions */
int64_t _1192_main(void);


/* Function definitions */
int64_t _1192_main(void){
    int64_t _1192_t3;
    struct struct0 _1193_y;
    int64_t _1192_t6;
    int64_t _1192_t10;
    int64_t _1192_$retval;
    _1192_t3 = 100;
    _1193_y = (struct struct0) {.tag=0, ._0=_1192_t3};
    _1192_t6 = _1193_y._0;
    _1192_t10 = 14;
    _1192_$retval = $add_int64_t(_1192_t6, _1192_t10, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _1192_$retval;
}


int main(void) {
  printf("%ld",_1192_main());
  return 0;
}
