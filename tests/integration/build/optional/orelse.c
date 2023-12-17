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
int64_t _1177_main(void);

/* Function definitions */
int64_t _1177_main(void){
    int64_t _1177_t2;
    struct0 _1178_y;
    int64_t _1177_t4;
    int64_t _1177_t8;
    int64_t _1177_$retval;
    _1177_t2 = 100;
    _1178_y = (struct0) {.tag=1, ._1=_1177_t2};
    _1177_t4 = _1178_y._1;
    _1177_t8 = 14;
    _1177_$retval = $add_int64_t(_1177_t4, _1177_t8, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _1177_$retval;
}

int main(void) {
  printf("%ld",_1177_main());
  return 0;
}
