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
int64_t _802_main(void);

/* Function definitions */
int64_t _802_main(void) {
    int64_t _802_t0;
    struct0 _803_x;
    uint8_t _802_t5;
    int64_t _802_t12;
    int64_t _802_t2;
    uint64_t _802_t9;
    uint64_t _802_t10;
    uint8_t _802_t11;
    int64_t _802_$retval;
    uint64_t _802_t6;
    uint64_t _802_t7;
    uint8_t _802_t8;
    uint32_t _810_c;
    uint8_t _806_b;
    _802_t0 = 171;
    _803_x = (struct0) {.tag=0, ._0=_802_t0};
    _802_t5 = 1;
    if (_802_t5) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _802_t2 = _803_x._0;
    goto BB5;
BB6:
    _802_t6 = 1;
    _802_t7 = _803_x.tag;
    _802_t8 = _802_t7 == _802_t6;
    if (_802_t8) {
        goto BB8;
    } else {
        goto BB14;
    }
BB5:
    _802_$retval = _802_t2;
    return _802_$retval;
BB8:
    _806_b = _803_x._1;
    if (_806_b) {
        goto BB9;
    } else {
        goto BB12;
    }
BB14:
    _802_t9 = 2;
    _802_t10 = _803_x.tag;
    _802_t11 = _802_t10 == _802_t9;
    if (_802_t11) {
        goto BB16;
    } else {
        goto BB19;
    }
BB9:
    _802_t12 = 10;
    goto BB11;
BB12:
    _802_t12 = 3;
    goto BB11;
BB16:
    _810_c = _803_x._2;
    (void)_810_c;
    _802_t2 = 4;
    goto BB5;
BB19:
    $lines[$line_idx++] = "tests/integration/pattern/match-inject.orng:10:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
BB11:
    _802_t2 = _802_t12;
    goto BB5;
}

int main(void) {
  printf("%ld",_802_main());
  return 0;
}
