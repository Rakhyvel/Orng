/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint64_t tag;
    union {
        int32_t _0;
    };
};

/* Function forward definitions */
int64_t _268_f(struct struct0 _268_x);
int64_t _264_main(void);


/* Function definitions */
int64_t _268_f(struct struct0 _268_x){
    uint64_t _268_t1;
    uint64_t _268_t2;
    uint8_t _268_t3;
    int64_t _268_t0;
    uint64_t _268_t4;
    uint64_t _268_t5;
    uint8_t _268_t6;
    int64_t _268_$retval;
    _268_t1 = 0;
    _268_t2 = _268_x.tag;
    _268_t3 = _268_t2==_268_t1;
    if (_268_t3) {
        goto BB266;
    } else {
        goto BB269;
    }
BB266:
    _268_t0 = 250;
    goto BB268;
BB269:
    _268_t4 = 1;
    _268_t5 = _268_x.tag;
    _268_t6 = _268_t5==_268_t4;
    if (_268_t6) {
        goto BB271;
    } else {
        goto BB273;
    }
BB268:
    _268_$retval = _268_t0;
    return _268_$retval;
BB271:
    _268_t0 = 11;
    goto BB268;
BB273:
    $lines[$line_idx++] = "tests/integration/comptime/optional.orng:10:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

int64_t _264_main(void){
    int64_t _264_$retval;
    _264_$retval = 261;
    return _264_$retval;
}


int main(void) {
  printf("%ld",_264_main());
  return 0;
}
