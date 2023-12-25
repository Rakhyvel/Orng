/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _792_main(void);
int64_t _794_f(int64_t _794_x);

/* Function definitions */
int64_t _792_main(void){
    function0 _792_t0;
    int64_t _792_t2;
    int64_t _792_t1;
    int64_t _792_$retval;
    _792_t0 = _794_f;
    _792_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _792_t1 = _792_t0(_792_t2);
    $line_idx--;
    _792_$retval = _792_t1;
    return _792_$retval;
}

int64_t _794_f(int64_t _794_x){
    int64_t _794_t1;
    uint8_t _794_t2;
    int64_t _794_t0;
    int64_t _794_$retval;
    _794_t1 = 0;
    _794_t2 = _794_x!=_794_t1;
    if (_794_t2) {
        goto BB1024;
    } else {
        goto BB1028;
    }
BB1024:
    _794_t0 = 173;
    goto BB1027;
BB1028:
    _794_t0 = 3;
    goto BB1027;
BB1027:
    _794_$retval = _794_t0;
    return _794_$retval;
}

int main(void) {
  printf("%ld",_792_main());
  return 0;
}
