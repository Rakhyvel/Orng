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
int64_t _1134_main(void);


/* Function definitions */
int64_t _1134_main(void){
    int64_t _1134_t2;
    struct struct0 _1135_y;
    int64_t _1134_t5;
    int64_t _1134_t9;
    int64_t _1134_$retval;
    _1134_t2 = 100;
    _1135_y = (struct struct0) {.tag=0, ._0=_1134_t2};
    _1134_t5 = _1135_y._0;
    _1134_t9 = 14;
    _1134_$retval = $add_int64_t(_1134_t5, _1134_t9, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _1134_$retval;
}


int main(void) {
  printf("%ld",_1134_main());
  return 0;
}
