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
int64_t _753_main(void);
uint8_t _758_f(int64_t _758_x);


/* Function definitions */
int64_t _753_main(void){
    function0 _753_t1;
    int64_t _753_t3;
    uint8_t _753_t2;
    int64_t _753_t0;
    int64_t _753_$retval;
    _753_t1 = (function0) _758_f;
    _753_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _753_t2 = _753_t1(_753_t3);
    $line_idx--;
    if (_753_t2) {
        goto BB879;
    } else {
        goto BB883;
    }
BB879:
    _753_t0 = 192;
    goto BB882;
BB883:
    _753_t0 = 4;
    goto BB882;
BB882:
    _753_$retval = _753_t0;
    return _753_$retval;
}

uint8_t _758_f(int64_t _758_x){
    uint8_t _758_$retval;
    (void)_758_x;
    goto BB874;
BB874:
    _758_$retval = 1;
    return _758_$retval;
}


int main(void) {
  printf("%ld",_753_main());
  return 0;
}
