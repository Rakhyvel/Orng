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
int64_t _745_main(void);

/* Function definitions */
int64_t _745_main(void) {
    int64_t _745_t1;
    struct0 _746_y;
    int64_t _745_t3;
    int64_t _745_t7;
    int64_t _745_$retval;
    _745_t1 = 100;
    _746_y = (struct0) {.tag=1, ._1=_745_t1};
    _745_t3 = _746_y._1;
    _745_t7 = 14;
    _745_$retval = $add_int64_t(_745_t3, _745_t7, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _745_$retval;
}

int main(void) {
  printf("%ld",_745_main());
  return 0;
}
