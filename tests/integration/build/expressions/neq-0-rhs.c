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
int64_t _819_main(void);
int64_t _821_f(int64_t _821_x);


/* Function definitions */
int64_t _819_main(void){
    function0 _819_t0;
    int64_t _819_t2;
    int64_t _819_t1;
    int64_t _819_$retval;
    _819_t0 = (function0) _821_f;
    _819_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _819_t1 = _819_t0(_819_t2);
    $line_idx--;
    _819_$retval = _819_t1;
    return _819_$retval;
}

int64_t _821_f(int64_t _821_x){
    int64_t _821_t1;
    uint8_t _821_t3;
    int64_t _821_t0;
    int64_t _821_$retval;
    _821_t1 = 0;
    _821_t3 = _821_x==_821_t1;
    if (_821_t3) {
        goto BB991;
    } else {
        goto BB987;
    }
BB991:
    _821_t0 = 3;
    goto BB990;
BB987:
    _821_t0 = 173;
    goto BB990;
BB990:
    _821_$retval = _821_t0;
    return _821_$retval;
}


int main(void) {
  printf("%ld",_819_main());
  return 0;
}
