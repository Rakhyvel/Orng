/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _763_main(void);
uint8_t _768_f(int64_t _768_x);

/* Function definitions */
int64_t _763_main(void){
    function0 _763_t1;
    int64_t _763_t3;
    uint8_t _763_t2;
    int64_t _763_t0;
    int64_t _763_$retval;
    _763_t1 = _768_f;
    _763_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _763_t2 = _763_t1(_763_t3);
    $line_idx--;
    if (_763_t2) {
        goto BB943;
    } else {
        goto BB947;
    }
BB943:
    _763_t0 = 186;
    goto BB946;
BB947:
    _763_t0 = 4;
    goto BB946;
BB946:
    _763_$retval = _763_t0;
    return _763_$retval;
}

uint8_t _768_f(int64_t _768_x){
    uint8_t _768_$retval;
    (void)_768_x;
    _768_$retval = 1;
    return _768_$retval;
}

int main(void) {
  printf("%ld",_763_main());
  return 0;
}
