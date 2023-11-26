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
        uint8_t _1;
        uint32_t _2;
    };
} struct0;

/* Function forward definitions */
int64_t _76_main(void);

/* Function definitions */
int64_t _76_main(void) {
    int64_t _76_t0;
    struct0 _77_x;
    uint8_t _76_t5;
    int64_t _76_t12;
    int64_t _76_t2;
    uint64_t _76_t9;
    uint64_t _76_t10;
    uint8_t _76_t11;
    int64_t _76_$retval;
    uint64_t _76_t6;
    uint64_t _76_t7;
    uint8_t _76_t8;
    uint32_t _84_c;
    uint8_t _80_b;
    _76_t0 = 172;
    _77_x = (struct0) {.tag=0, ._0=_76_t0};
    _76_t5 = 1;
    if (_76_t5) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _76_t2 = _77_x._0;
    goto BB5;
BB6:
    _76_t6 = 1;
    _76_t7 = _77_x.tag;
    _76_t8 = _76_t7 == _76_t6;
    if (_76_t8) {
        goto BB8;
    } else {
        goto BB14;
    }
BB5:
    _76_$retval = _76_t2;
    return _76_$retval;
BB8:
    _80_b = _77_x._1;
    if (_80_b) {
        goto BB9;
    } else {
        goto BB12;
    }
BB14:
    _76_t9 = 2;
    _76_t10 = _77_x.tag;
    _76_t11 = _76_t10 == _76_t9;
    if (_76_t11) {
        goto BB16;
    } else {
        goto BB19;
    }
BB9:
    _76_t12 = 10;
    goto BB11;
BB12:
    _76_t12 = 3;
    goto BB11;
BB16:
    _84_c = _77_x._2;
    (void)_84_c;
    _76_t2 = 4;
    goto BB5;
BB19:
    $lines[$line_idx++] = "tests/integration/pattern/match-inject-infer.orng:10:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
BB11:
    _76_t2 = _76_t12;
    goto BB5;
}

int main(void) {
  printf("%ld",_76_main());
  return 0;
}
