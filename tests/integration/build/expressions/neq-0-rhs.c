/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _817_main(void);
int64_t _819_f(int64_t _819_x);


/* Function definitions */
int64_t _817_main(void){
    function0 _817_t0;
    int64_t _817_t2;
    int64_t _817_t1;
    int64_t _817_$retval;
    _817_t0 = (function0) _819_f;
    _817_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _817_t1 = _817_t0(_817_t2);
    $line_idx--;
    _817_$retval = _817_t1;
    return _817_$retval;
}

int64_t _819_f(int64_t _819_x){
    int64_t _819_t1;
    uint8_t _819_t3;
    int64_t _819_t0;
    int64_t _819_$retval;
    _819_t1 = 0;
    _819_t3 = _819_x==_819_t1;
    if (_819_t3) {
        goto BB989;
    } else {
        goto BB985;
    }
BB989:
    _819_t0 = 3;
    goto BB988;
BB985:
    _819_t0 = 173;
    goto BB988;
BB988:
    _819_$retval = _819_t0;
    return _819_$retval;
}


int main(void) {
  printf("%ld",_817_main());
  return 0;
}
