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
int64_t _780_main(void);

/* Function definitions */
int64_t _780_main(void) {
    int64_t _780_t2;
    struct0 _781_y;
    int64_t _780_t4;
    int64_t _780_t8;
    int64_t _780_$retval;
    _780_t2 = 100;
    _781_y = (struct0) {.tag=1, ._1=_780_t2};
    _780_t4 = _781_y._1;
    _780_t8 = 14;
    _780_$retval = $add_int64_t(_780_t4, _780_t8, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _780_$retval;
}

int main(void) {
  printf("%ld",_780_main());
  return 0;
}
