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
int64_t _87_main(void);

/* Function definitions */
int64_t _87_main(void) {
    int64_t _87_t0;
    struct0 _88_x;
    uint8_t _87_t5;
    int64_t _87_t12;
    int64_t _87_t2;
    uint64_t _87_t9;
    uint64_t _87_t10;
    uint8_t _87_t11;
    int64_t _87_$retval;
    uint64_t _87_t6;
    uint64_t _87_t7;
    uint8_t _87_t8;
    uint32_t _95_c;
    uint8_t _91_b;
    _87_t0 = 171;
    _88_x = (struct0) {.tag=0, ._0=_87_t0};
    _87_t5 = 1;
    if (_87_t5) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _87_t2 = _88_x._0;
    goto BB5;
BB6:
    _87_t6 = 1;
    _87_t7 = _88_x.tag;
    _87_t8 = _87_t7 == _87_t6;
    if (_87_t8) {
        goto BB8;
    } else {
        goto BB14;
    }
BB5:
    _87_$retval = _87_t2;
    return _87_$retval;
BB8:
    _91_b = _88_x._1;
    if (_91_b) {
        goto BB9;
    } else {
        goto BB12;
    }
BB14:
    _87_t9 = 2;
    _87_t10 = _88_x.tag;
    _87_t11 = _87_t10 == _87_t9;
    if (_87_t11) {
        goto BB16;
    } else {
        goto BB19;
    }
BB9:
    _87_t12 = 10;
    goto BB11;
BB12:
    _87_t12 = 3;
    goto BB11;
BB16:
    _95_c = _88_x._2;
    (void)_95_c;
    _87_t2 = 4;
    goto BB5;
BB19:
    $lines[$line_idx++] = "tests/integration/pattern/match-inject.orng:10:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
BB11:
    _87_t2 = _87_t12;
    goto BB5;
}

int main(void) {
  printf("%ld",_87_main());
  return 0;
}
