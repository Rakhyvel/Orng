/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    uint64_t tag;
    union {
        int32_t _0;
    };
};

/* Function forward definitions */
int64_t _249_f(struct struct0 _249_x);
int64_t _246_main(void);

/* Function definitions */
int64_t _249_f(struct struct0 _249_x){
    uint64_t _249_t1;
    uint64_t _249_t2;
    uint8_t _249_t3;
    int64_t _249_t0;
    uint64_t _249_t4;
    uint64_t _249_t5;
    uint8_t _249_t6;
    int64_t _249_$retval;
    _249_t1 = 0;
    _249_t2 = _249_x.tag;
    _249_t3 = _249_t2==_249_t1;
    if (_249_t3) {
        goto BB251;
    } else {
        goto BB254;
    }
BB251:
    _249_t0 = 250;
    goto BB253;
BB254:
    _249_t4 = 1;
    _249_t5 = _249_x.tag;
    _249_t6 = _249_t5==_249_t4;
    if (_249_t6) {
        goto BB256;
    } else {
        goto BB258;
    }
BB253:
    _249_$retval = _249_t0;
    return _249_$retval;
BB256:
    _249_t0 = 11;
    goto BB253;
BB258:
    $lines[$line_idx++] = "tests/integration/comptime/optional.orng:10:25:\n        _ => unreachable\n                       ^";
    $panic("reached unreachable code\n");
}

int64_t _246_main(void){
    int64_t _246_$retval;
    _246_$retval = 261;
    return _246_$retval;
}

int main(void) {
  printf("%ld",_246_main());
  return 0;
}
