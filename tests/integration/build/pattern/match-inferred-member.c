/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
} struct0;

/* Function forward definitions */
int64_t _784_main(void);

/* Function definitions */
int64_t _784_main(void) {
    struct0 _785_x;
    uint8_t _784_t4;
    int64_t _784_t1;
    uint64_t _784_t8;
    uint64_t _784_t9;
    uint8_t _784_t10;
    int64_t _784_$retval;
    uint64_t _784_t5;
    uint64_t _784_t6;
    uint8_t _784_t7;
    _785_x = (struct0) {.tag=2};
    _784_t4 = 0;
    if (_784_t4) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _784_t1 = 168;
    goto BB5;
BB6:
    _784_t5 = 1;
    _784_t6 = _785_x.tag;
    _784_t7 = _784_t6 == _784_t5;
    if (_784_t7) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _784_$retval = _784_t1;
    return _784_$retval;
BB8:
    _784_t1 = 169;
    goto BB5;
BB9:
    _784_t8 = 2;
    _784_t9 = _785_x.tag;
    _784_t10 = _784_t9 == _784_t8;
    if (_784_t10) {
        goto BB11;
    } else {
        goto BB13;
    }
BB11:
    _784_t1 = 170;
    goto BB5;
BB13:
    $lines[$line_idx++] = "tests/integration/pattern/match-inferred-member.orng:10:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_784_main());
  return 0;
}
