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
int64_t _791_main(void);

/* Function definitions */
int64_t _791_main(void) {
    int64_t _791_t0;
    struct0 _792_x;
    uint8_t _791_t5;
    int64_t _791_t12;
    int64_t _791_t2;
    uint64_t _791_t9;
    uint64_t _791_t10;
    uint8_t _791_t11;
    int64_t _791_$retval;
    uint64_t _791_t6;
    uint64_t _791_t7;
    uint8_t _791_t8;
    uint32_t _799_c;
    uint8_t _795_b;
    _791_t0 = 172;
    _792_x = (struct0) {.tag=0, ._0=_791_t0};
    _791_t5 = 1;
    if (_791_t5) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _791_t2 = _792_x._0;
    goto BB5;
BB6:
    _791_t6 = 1;
    _791_t7 = _792_x.tag;
    _791_t8 = _791_t7 == _791_t6;
    if (_791_t8) {
        goto BB8;
    } else {
        goto BB14;
    }
BB5:
    _791_$retval = _791_t2;
    return _791_$retval;
BB8:
    _795_b = _792_x._1;
    if (_795_b) {
        goto BB9;
    } else {
        goto BB12;
    }
BB14:
    _791_t9 = 2;
    _791_t10 = _792_x.tag;
    _791_t11 = _791_t10 == _791_t9;
    if (_791_t11) {
        goto BB16;
    } else {
        goto BB19;
    }
BB9:
    _791_t12 = 10;
    goto BB11;
BB12:
    _791_t12 = 3;
    goto BB11;
BB16:
    _799_c = _792_x._2;
    (void)_799_c;
    _791_t2 = 4;
    goto BB5;
BB19:
    $lines[$line_idx++] = "tests/integration/pattern/match-inject-infer.orng:10:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
BB11:
    _791_t2 = _791_t12;
    goto BB5;
}

int main(void) {
  printf("%ld",_791_main());
  return 0;
}
