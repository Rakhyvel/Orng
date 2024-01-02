/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _857_main(void);
uint8_t _862_f(int64_t _862_x);

/* Function definitions */
int64_t _857_main(void){
    function0 _857_t1;
    int64_t _857_t3;
    uint8_t _857_t2;
    int64_t _857_t0;
    int64_t _857_$retval;
    _857_t1 = _862_f;
    _857_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _857_t2 = _857_t1(_857_t3);
    $line_idx--;
    if (_857_t2) {
        goto BB1066;
    } else {
        goto BB1070;
    }
BB1066:
    _857_t0 = 0;
    goto BB1069;
BB1070:
    _857_t0 = 226;
    goto BB1069;
BB1069:
    _857_$retval = _857_t0;
    return _857_$retval;
}

uint8_t _862_f(int64_t _862_x){
    uint8_t _862_$retval;
    (void)_862_x;
    _862_$retval = 0;
    return _862_$retval;
}

int main(void) {
  printf("%ld",_857_main());
  return 0;
}
