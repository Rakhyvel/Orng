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
int64_t _714_main(void);

/* Function definitions */
int64_t _714_main(void) {
    struct0 _715_x;
    int64_t _714_t1;
    struct0 _715_y;
    uint64_t _714_t4;
    int64_t _714_t3;
    uint64_t _714_t8;
    int64_t _714_t7;
    int64_t _714_$retval;
    _715_x = (struct0) {.tag=0};
    _714_t1 = 100;
    _715_y = (struct0) {.tag=1, ._1=_714_t1};
    _714_t4 = 1;
    if (_714_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _714_t3 = _715_y._1;
    goto BB2;
BB7:
    _714_t3 = -10;
    goto BB2;
BB2:
    _714_t8 = _715_x.tag;
    if (_714_t8) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _714_t7 = _715_x._1;
    goto BB4;
BB6:
    _714_t7 = 14;
    goto BB4;
BB4:
    _714_$retval = $add_int64_t(_714_t3, _714_t7, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _714_$retval;
}

int main(void) {
  printf("%ld",_714_main());
  return 0;
}
