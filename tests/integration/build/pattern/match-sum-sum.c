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
int64_t _883_main(void);

/* Function definitions */
int64_t _883_main(void) {
    int64_t _883_t0;
    struct0 _883_t1;
    struct1 _884_x;
    struct0 _890_y;
    uint64_t _883_t18;
    uint64_t _883_t19;
    uint8_t _883_t20;
    uint64_t _883_t21;
    uint64_t _883_t22;
    uint8_t _883_t23;
    int64_t _883_$retval;
    int64_t _883_t17;
    _883_t0 = 173;
    _883_t1 = (struct0) {.tag=0, ._0=_883_t0};
    _884_x = (struct1) {.tag=1, ._1=_883_t1};
    _890_y = _884_x._1;
    _883_t18 = 0;
    _883_t19 = _890_y.tag;
    _883_t20 = _883_t19 == _883_t18;
    if (_883_t20) {
        goto BB20;
    } else {
        goto BB22;
    }
BB20:
    _883_t17 = _890_y._0;
    goto BB21;
BB22:
    _883_t21 = 1;
    _883_t22 = _890_y.tag;
    _883_t23 = _883_t22 == _883_t21;
    if (_883_t23) {
        goto BB24;
    } else {
        goto BB26;
    }
BB21:
    _883_$retval = _883_t17;
    return _883_$retval;
BB24:
    _883_t17 = _890_y._1;
    goto BB21;
BB26:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum-sum.orng:15:32:\n            else => unreachable\n                              ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_883_main());
  return 0;
}
