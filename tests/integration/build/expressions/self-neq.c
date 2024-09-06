/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _866_main(void);
uint8_t _871_f(int64_t _871_x);


/* Function definitions */
int64_t _866_main(void){
    function0 _866_t1;
    int64_t _866_t3;
    uint8_t _866_t2;
    int64_t _866_t0;
    int64_t _866_$retval;
    _866_t1 = (function0) _871_f;
    _866_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _866_t2 = _866_t1(_866_t3);
    $line_idx--;
    if (_866_t2) {
        goto BB1046;
    } else {
        goto BB1050;
    }
BB1046:
    _866_t0 = 0;
    goto BB1049;
BB1050:
    _866_t0 = 223;
    goto BB1049;
BB1049:
    _866_$retval = _866_t0;
    return _866_$retval;
}

uint8_t _871_f(int64_t _871_x){
    uint8_t _871_$retval;
    (void)_871_x;
    goto BB1041;
BB1041:
    _871_$retval = 0;
    return _871_$retval;
}


int main(void) {
  printf("%ld",_866_main());
  return 0;
}
