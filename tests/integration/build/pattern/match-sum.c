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
int64_t _864_main(void);

/* Function definitions */
int64_t _864_main(void) {
    struct0 _865_x;
    uint8_t _864_t4;
    int64_t _864_t1;
    uint64_t _864_t8;
    uint64_t _864_t9;
    uint8_t _864_t10;
    int64_t _864_$retval;
    uint64_t _864_t5;
    uint64_t _864_t6;
    uint8_t _864_t7;
    _865_x = (struct0) {.tag=1};
    _864_t4 = 0;
    if (_864_t4) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _864_t1 = 168;
    goto BB5;
BB6:
    _864_t5 = 1;
    _864_t6 = _865_x.tag;
    _864_t7 = _864_t6 == _864_t5;
    if (_864_t7) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _864_$retval = _864_t1;
    return _864_$retval;
BB8:
    _864_t1 = 169;
    goto BB5;
BB9:
    _864_t8 = 2;
    _864_t9 = _865_x.tag;
    _864_t10 = _864_t9 == _864_t8;
    if (_864_t10) {
        goto BB11;
    } else {
        goto BB13;
    }
BB11:
    _864_t1 = 170;
    goto BB5;
BB13:
    $lines[$line_idx++] = "tests/integration/pattern/match-sum.orng:10:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_864_main());
  return 0;
}
