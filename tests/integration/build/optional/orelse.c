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
int64_t _43_main(void);

/* Function definitions */
int64_t _43_main(void) {
    struct0 _44_x;
    int64_t _43_t1;
    struct0 _44_y;
    uint64_t _43_t4;
    int64_t _43_t3;
    uint64_t _43_t8;
    int64_t _43_t7;
    int64_t _43_$retval;
    _44_x = (struct0) {.tag=0};
    _43_t1 = 100;
    _44_y = (struct0) {.tag=1, ._1=_43_t1};
    _43_t4 = 1;
    if (_43_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _43_t3 = _44_y._1;
    goto BB2;
BB7:
    _43_t3 = -10;
    goto BB2;
BB2:
    _43_t8 = _44_x.tag;
    if (_43_t8) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _43_t7 = _44_x._1;
    goto BB4;
BB6:
    _43_t7 = 14;
    goto BB4;
BB4:
    _43_$retval = $add_int64_t(_43_t3, _43_t7, "tests/integration/optional/orelse.orng:5:21:\n    (y orelse -10) + (x orelse 14)\n                   ^");
    return _43_$retval;
}

int main(void) {
  printf("%ld",_43_main());
  return 0;
}
