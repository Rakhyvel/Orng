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
int64_t _91_f(struct0 _91_x);
int64_t _88_main(void);

/* Function definitions */
int64_t _91_f(struct0 _91_x){
    uint64_t _91_t1;
    uint64_t _91_t2;
    uint8_t _91_t3;
    int64_t _91_t0;
    uint64_t _91_t4;
    uint64_t _91_t5;
    uint8_t _91_t6;
    int64_t _91_$retval;
    _91_t1 = 1;
    _91_t2 = _91_x.tag;
    _91_t3 = _91_t2 == _91_t1;
    if (_91_t3) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _91_t0 = 250;
    goto BB5;
BB6:
    _91_t4 = 0;
    _91_t5 = _91_x.tag;
    _91_t6 = _91_t5 == _91_t4;
    if (_91_t6) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _91_$retval = _91_t0;
    return _91_$retval;
BB8:
    _91_t0 = 11;
    goto BB5;
BB10:
    $lines[$line_idx++] = "tests/integration/comptime/optional.orng:10:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int64_t _88_main(void){
    int64_t _88_$retval;
    _88_$retval = 261;
    return _88_$retval;
}

int main(void) {
  printf("%ld",_88_main());
  return 0;
}
