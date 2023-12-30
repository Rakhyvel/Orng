/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _785_main(void);
uint8_t _790_f(int64_t _790_x);

/* Function definitions */
int64_t _785_main(void){
    function0 _785_t1;
    int64_t _785_t3;
    uint8_t _785_t2;
    int64_t _785_t0;
    int64_t _785_$retval;
    _785_t1 = _790_f;
    _785_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _785_t2 = _785_t1(_785_t3);
    $line_idx--;
    if (_785_t2) {
        goto BB991;
    } else {
        goto BB995;
    }
BB991:
    _785_t0 = 187;
    goto BB994;
BB995:
    _785_t0 = 4;
    goto BB994;
BB994:
    _785_$retval = _785_t0;
    return _785_$retval;
}

uint8_t _790_f(int64_t _790_x){
    uint8_t _790_$retval;
    (void)_790_x;
    _790_$retval = 1;
    return _790_$retval;
}

int main(void) {
  printf("%ld",_785_main());
  return 0;
}
