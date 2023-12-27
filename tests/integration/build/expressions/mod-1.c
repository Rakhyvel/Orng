/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _743_main(void);
uint8_t _748_f(int64_t _748_x);

/* Function definitions */
int64_t _743_main(void){
    function0 _743_t1;
    int64_t _743_t3;
    uint8_t _743_t2;
    int64_t _743_t0;
    int64_t _743_$retval;
    _743_t1 = _748_f;
    _743_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _743_t2 = _743_t1(_743_t3);
    $line_idx--;
    if (_743_t2) {
        goto BB914;
    } else {
        goto BB918;
    }
BB914:
    _743_t0 = 192;
    goto BB917;
BB918:
    _743_t0 = 4;
    goto BB917;
BB917:
    _743_$retval = _743_t0;
    return _743_$retval;
}

uint8_t _748_f(int64_t _748_x){
    uint8_t _748_$retval;
    (void)_748_x;
    _748_$retval = 1;
    return _748_$retval;
}

int main(void) {
  printf("%ld",_743_main());
  return 0;
}
