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
int64_t _233_f(struct0 _233_x);
int64_t _230_main(void);

/* Function definitions */
int64_t _233_f(struct0 _233_x){
    uint64_t _233_t1;
    uint64_t _233_t2;
    uint8_t _233_t3;
    int64_t _233_t0;
    uint64_t _233_t4;
    uint64_t _233_t5;
    uint8_t _233_t6;
    int64_t _233_$retval;
    _233_t1 = 1;
    _233_t2 = _233_x.tag;
    _233_t3 = _233_t2 == _233_t1;
    if (_233_t3) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _233_t0 = 250;
    goto BB5;
BB6:
    _233_t4 = 0;
    _233_t5 = _233_x.tag;
    _233_t6 = _233_t5 == _233_t4;
    if (_233_t6) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _233_$retval = _233_t0;
    return _233_$retval;
BB8:
    _233_t0 = 11;
    goto BB5;
BB10:
    $lines[$line_idx++] = "tests/integration/comptime/optional.orng:10:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int64_t _230_main(void){
    int64_t _230_$retval;
    _230_$retval = 261;
    return _230_$retval;
}

int main(void) {
  printf("%ld",_230_main());
  return 0;
}
