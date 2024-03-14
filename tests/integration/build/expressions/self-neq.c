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
int64_t _892_main(void);
uint8_t _897_f(int64_t _897_x);


/* Function definitions */
int64_t _892_main(void){
    function0 _892_t1;
    int64_t _892_t3;
    uint8_t _892_t2;
    int64_t _892_t0;
    int64_t _892_$retval;
    _892_t1 = (function0) _897_f;
    _892_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _892_t2 = _892_t1(_892_t3);
    $line_idx--;
    if (_892_t2) {
        goto BB1093;
    } else {
        goto BB1097;
    }
BB1093:
    _892_t0 = 0;
    goto BB1096;
BB1097:
    _892_t0 = 223;
    goto BB1096;
BB1096:
    _892_$retval = _892_t0;
    return _892_$retval;
}

uint8_t _897_f(int64_t _897_x){
    uint8_t _897_$retval;
    (void)_897_x;
    _897_$retval = 0;
    return _897_$retval;
}


int main(void) {
  printf("%ld",_892_main());
  return 0;
}
