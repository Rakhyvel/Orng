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
int64_t _748_main(void);
uint8_t _753_f(int64_t _753_x);


/* Function definitions */
int64_t _748_main(void){
    function0 _748_t1;
    int64_t _748_t3;
    uint8_t _748_t2;
    int64_t _748_t0;
    int64_t _748_$retval;
    _748_t1 = (function0) _753_f;
    _748_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _748_t2 = _748_t1(_748_t3);
    $line_idx--;
    if (_748_t2) {
        goto BB876;
    } else {
        goto BB880;
    }
BB876:
    _748_t0 = 192;
    goto BB879;
BB880:
    _748_t0 = 4;
    goto BB879;
BB879:
    _748_$retval = _748_t0;
    return _748_$retval;
}

uint8_t _753_f(int64_t _753_x){
    uint8_t _753_$retval;
    (void)_753_x;
    _753_$retval = 1;
    return _753_$retval;
}


int main(void) {
  printf("%ld",_748_main());
  return 0;
}
