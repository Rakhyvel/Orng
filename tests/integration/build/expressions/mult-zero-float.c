/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _889_main(void);
uint8_t _894_f(double _894_x);

/* Function definitions */
int64_t _889_main(void){
    function0 _889_t1;
    double _889_t3;
    uint8_t _889_t2;
    int64_t _889_t0;
    int64_t _889_$retval;
    _889_t1 = _894_f;
    _889_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _889_t2 = _889_t1(_889_t3);
    $line_idx--;
    if (_889_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _889_t0 = 188;
    goto BB4;
BB5:
    _889_t0 = 4;
    goto BB4;
BB4:
    _889_$retval = _889_t0;
    return _889_$retval;
}

uint8_t _894_f(double _894_x){
    uint8_t _894_$retval;
    (void)_894_x;
    _894_$retval = 1;
    return _894_$retval;
}

int main(void) {
  printf("%ld",_889_main());
  return 0;
}
