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
int64_t _768_main(void);
uint8_t _773_f(int64_t _773_x);


/* Function definitions */
int64_t _768_main(void){
    function0 _768_t1;
    int64_t _768_t3;
    uint8_t _768_t2;
    int64_t _768_t0;
    int64_t _768_$retval;
    _768_t1 = (function0) _773_f;
    _768_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _768_t2 = _768_t1(_768_t3);
    $line_idx--;
    if (_768_t2) {
        goto BB895;
    } else {
        goto BB899;
    }
BB895:
    _768_t0 = 192;
    goto BB898;
BB899:
    _768_t0 = 4;
    goto BB898;
BB898:
    _768_$retval = _768_t0;
    return _768_$retval;
}

uint8_t _773_f(int64_t _773_x){
    uint8_t _773_$retval;
    (void)_773_x;
    goto BB890;
BB890:
    _773_$retval = 1;
    return _773_$retval;
}


int main(void) {
  printf("%ld",_768_main());
  return 0;
}
