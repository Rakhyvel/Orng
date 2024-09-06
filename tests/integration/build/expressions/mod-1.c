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
int64_t _756_main(void);
uint8_t _761_f(int64_t _761_x);


/* Function definitions */
int64_t _756_main(void){
    function0 _756_t1;
    int64_t _756_t3;
    uint8_t _756_t2;
    int64_t _756_t0;
    int64_t _756_$retval;
    _756_t1 = (function0) _761_f;
    _756_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _756_t2 = _756_t1(_756_t3);
    $line_idx--;
    if (_756_t2) {
        goto BB882;
    } else {
        goto BB886;
    }
BB882:
    _756_t0 = 192;
    goto BB885;
BB886:
    _756_t0 = 4;
    goto BB885;
BB885:
    _756_$retval = _756_t0;
    return _756_$retval;
}

uint8_t _761_f(int64_t _761_x){
    uint8_t _761_$retval;
    (void)_761_x;
    goto BB877;
BB877:
    _761_$retval = 1;
    return _761_$retval;
}


int main(void) {
  printf("%ld",_756_main());
  return 0;
}
