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
int64_t _762_main(void);
uint8_t _767_f(int64_t _767_x);


/* Function definitions */
int64_t _762_main(void){
    function0 _762_t1;
    int64_t _762_t3;
    uint8_t _762_t2;
    int64_t _762_t0;
    int64_t _762_$retval;
    _762_t1 = (function0) _767_f;
    _762_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _762_t2 = _762_t1(_762_t3);
    $line_idx--;
    if (_762_t2) {
        goto BB885;
    } else {
        goto BB889;
    }
BB885:
    _762_t0 = 191;
    goto BB888;
BB889:
    _762_t0 = 4;
    goto BB888;
BB888:
    _762_$retval = _762_t0;
    return _762_$retval;
}

uint8_t _767_f(int64_t _767_x){
    uint8_t _767_$retval;
    (void)_767_x;
    goto BB880;
BB880:
    _767_$retval = 1;
    return _767_$retval;
}


int main(void) {
  printf("%ld",_762_main());
  return 0;
}
