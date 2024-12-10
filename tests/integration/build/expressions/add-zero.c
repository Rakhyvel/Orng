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
int64_t _644_main(void);
uint8_t _649_f(int64_t _649_x);


/* Function definitions */
int64_t _644_main(void){
    function0 _644_t1;
    int64_t _644_t3;
    uint8_t _644_t2;
    int64_t _644_t0;
    int64_t _644_$retval;
    _644_t1 = (function0) _649_f;
    _644_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _644_t2 = _644_t1(_644_t3);
    $line_idx--;
    if (_644_t2) {
        goto BB755;
    } else {
        goto BB759;
    }
BB755:
    _644_t0 = 182;
    goto BB758;
BB759:
    _644_t0 = 4;
    goto BB758;
BB758:
    _644_$retval = _644_t0;
    return _644_$retval;
}

uint8_t _649_f(int64_t _649_x){
    uint8_t _649_$retval;
    (void)_649_x;
    goto BB750;
BB750:
    _649_$retval = 1;
    return _649_$retval;
}


int main(void) {
  printf("%ld",_644_main());
  return 0;
}
