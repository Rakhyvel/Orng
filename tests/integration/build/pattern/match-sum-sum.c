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
int64_t _1270_main(void);

/* Function definitions */
int64_t _1270_main(void){
    int64_t _1270_t1;
    struct0 _1270_t2;
    struct1 _1271_x;
    struct0 _1284_y;
    uint64_t _1270_t19;
    uint64_t _1270_t20;
    uint8_t _1270_t21;
    uint64_t _1270_t22;
    uint64_t _1270_t23;
    uint8_t _1270_t24;
    int64_t _1270_$retval;
    int64_t _1270_t18;
    _1270_t1 = 173;
    _1270_t2 = (struct0) {.tag=0, ._0=_1270_t1};
    _1271_x = (struct1) {.tag=1, ._1=_1270_t2};
    _1284_y = _1271_x._1;
    _1270_t19 = 0;
    _1270_t20 = _1284_y.tag;
    _1270_t21 = _1270_t20 == _1270_t19;
    if (_1270_t21) {
        goto BB20;
    } else {
        goto BB22;
    }
BB20:
    _1270_t18 = _1284_y._0;
    goto BB21;
BB22:
    _1270_t22 = 1;
    _1270_t23 = _1284_y.tag;
    _1270_t24 = _1270_t23 == _1270_t22;
    if (_1270_t24) {
        goto BB24;
    } else {
        goto BB26;
    }
BB21:
    _1270_$retval = _1270_t18;
    return _1270_$retval;
BB24:
    _1270_t18 = _1284_y._1;
    goto BB21;
BB26:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:32:\n            else => unreachable\n                              ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_1270_main());
  return 0;
}
