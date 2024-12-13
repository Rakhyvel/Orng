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
int64_t _770_main(void);
uint8_t _775_f(int64_t _775_x);


/* Function definitions */
int64_t _770_main(void){
    function0 _770_t1;
    int64_t _770_t3;
    uint8_t _770_t2;
    int64_t _770_t0;
    int64_t _770_$retval;
    _770_t1 = (function0) _775_f;
    _770_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _770_t2 = _770_t1(_770_t3);
    $line_idx--;
    if (_770_t2) {
        goto BB897;
    } else {
        goto BB901;
    }
BB897:
    _770_t0 = 192;
    goto BB900;
BB901:
    _770_t0 = 4;
    goto BB900;
BB900:
    _770_$retval = _770_t0;
    return _770_$retval;
}

uint8_t _775_f(int64_t _775_x){
    uint8_t _775_$retval;
    (void)_775_x;
    goto BB892;
BB892:
    _775_$retval = 1;
    return _775_$retval;
}


int main(void) {
  printf("%ld",_770_main());
  return 0;
}
