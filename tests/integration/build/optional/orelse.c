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
int64_t _1139_main(void);


/* Function definitions */
int64_t _1139_main(void){
    int64_t _1139_t2;
    struct struct0 _1140_y;
    int64_t _1139_t5;
    int64_t _1139_t9;
    int64_t _1139_$retval;
    _1139_t2 = 100;
    _1140_y = (struct struct0) {.tag=0, ._0=_1139_t2};
    _1139_t5 = _1140_y._0;
    _1139_t9 = 14;
    _1139_$retval = $add_int64_t(_1139_t5, _1139_t9, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _1139_$retval;
}


int main(void) {
  printf("%ld",_1139_main());
  return 0;
}
