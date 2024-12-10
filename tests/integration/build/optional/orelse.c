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
int64_t _1231_main(void);


/* Function definitions */
int64_t _1231_main(void){
    int64_t _1231_t3;
    struct struct0 _1232_y;
    int64_t _1231_t6;
    int64_t _1231_t10;
    int64_t _1231_$retval;
    _1231_t3 = 100;
    _1232_y = (struct struct0) {.tag=0, ._0=_1231_t3};
    _1231_t6 = _1232_y._0;
    _1231_t10 = 14;
    _1231_$retval = $add_int64_t(_1231_t6, _1231_t10, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _1231_$retval;
}


int main(void) {
  printf("%ld",_1231_main());
  return 0;
}
