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
        int32_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _247_f(struct0 _247_x);
int64_t _244_main(void);

/* Function definitions */
int64_t _247_f(struct0 _247_x){
    uint64_t _247_t1;
    uint64_t _247_t2;
    uint8_t _247_t3;
    int64_t _247_t0;
    uint64_t _247_t4;
    uint64_t _247_t5;
    uint8_t _247_t6;
    int64_t _247_$retval;
    _247_t1 = 1;
    _247_t2 = _247_x.tag;
    _247_t3 = _247_t2 == _247_t1;
    if (_247_t3) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _247_t0 = 250;
    goto BB5;
BB6:
    _247_t4 = 0;
    _247_t5 = _247_x.tag;
    _247_t6 = _247_t5 == _247_t4;
    if (_247_t6) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _247_$retval = _247_t0;
    return _247_$retval;
BB8:
    _247_t0 = 11;
    goto BB5;
BB10:
    $lines[$line_idx++] = "tests/integration/comptime/optional.orng:10:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int64_t _244_main(void){
    int64_t _244_$retval;
    _244_$retval = 261;
    return _244_$retval;
}

int main(void) {
  printf("%ld",_244_main());
  return 0;
}
