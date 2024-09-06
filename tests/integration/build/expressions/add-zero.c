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
int64_t _632_main(void);
uint8_t _637_f(int64_t _637_x);


/* Function definitions */
int64_t _632_main(void){
    function0 _632_t1;
    int64_t _632_t3;
    uint8_t _632_t2;
    int64_t _632_t0;
    int64_t _632_$retval;
    _632_t1 = (function0) _637_f;
    _632_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _632_t2 = _632_t1(_632_t3);
    $line_idx--;
    if (_632_t2) {
        goto BB742;
    } else {
        goto BB746;
    }
BB742:
    _632_t0 = 182;
    goto BB745;
BB746:
    _632_t0 = 4;
    goto BB745;
BB745:
    _632_$retval = _632_t0;
    return _632_$retval;
}

uint8_t _637_f(int64_t _637_x){
    uint8_t _637_$retval;
    (void)_637_x;
    goto BB737;
BB737:
    _637_$retval = 1;
    return _637_$retval;
}


int main(void) {
  printf("%ld",_632_main());
  return 0;
}
