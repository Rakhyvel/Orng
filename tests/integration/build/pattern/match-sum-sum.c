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
        int64_t _0;
        int64_t _1;
    };
} struct0;

typedef struct {
    uint64_t tag;
    union {
        struct0 _0;
        struct0 _1;
    };
} struct1;

/* Function forward definitions */
int64_t _942_main(void);

/* Function definitions */
int64_t _942_main(void) {
    int64_t _942_t1;
    struct0 _942_t2;
    struct1 _943_x;
    struct0 _949_y;
    uint64_t _942_t19;
    uint64_t _942_t20;
    uint8_t _942_t21;
    uint64_t _942_t22;
    uint64_t _942_t23;
    uint8_t _942_t24;
    int64_t _942_$retval;
    int64_t _942_t18;
    _942_t1 = 173;
    _942_t2 = (struct0) {.tag=0, ._0=_942_t1};
    _943_x = (struct1) {.tag=1, ._1=_942_t2};
    _949_y = _943_x._1;
    _942_t19 = 0;
    _942_t20 = _949_y.tag;
    _942_t21 = _942_t20 == _942_t19;
    if (_942_t21) {
        goto BB20;
    } else {
        goto BB22;
    }
BB20:
    _942_t18 = _949_y._0;
    goto BB21;
BB22:
    _942_t22 = 1;
    _942_t23 = _949_y.tag;
    _942_t24 = _942_t23 == _942_t22;
    if (_942_t24) {
        goto BB24;
    } else {
        goto BB26;
    }
BB21:
    _942_$retval = _942_t18;
    return _942_$retval;
BB24:
    _942_t18 = _949_y._1;
    goto BB21;
BB26:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:32:\n            else => unreachable\n                              ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_942_main());
  return 0;
}
