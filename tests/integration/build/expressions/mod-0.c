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
int64_t _760_main(void);
uint8_t _765_f(int64_t _765_x);


/* Function definitions */
int64_t _760_main(void){
    function0 _760_t1;
    int64_t _760_t3;
    uint8_t _760_t2;
    int64_t _760_t0;
    int64_t _760_$retval;
    _760_t1 = (function0) _765_f;
    _760_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _760_t2 = _760_t1(_760_t3);
    $line_idx--;
    if (_760_t2) {
        goto BB883;
    } else {
        goto BB887;
    }
BB883:
    _760_t0 = 191;
    goto BB886;
BB887:
    _760_t0 = 4;
    goto BB886;
BB886:
    _760_$retval = _760_t0;
    return _760_$retval;
}

uint8_t _765_f(int64_t _765_x){
    uint8_t _765_$retval;
    (void)_765_x;
    goto BB878;
BB878:
    _765_$retval = 1;
    return _765_$retval;
}


int main(void) {
  printf("%ld",_760_main());
  return 0;
}
