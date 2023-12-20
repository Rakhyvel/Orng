/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(double);

/* Function forward definitions */
int64_t _765_main(void);
uint8_t _770_f(double _770_x);

/* Function definitions */
int64_t _765_main(void){
    function0 _765_t1;
    double _765_t3;
    uint8_t _765_t2;
    int64_t _765_t0;
    int64_t _765_$retval;
    _765_t1 = _770_f;
    _765_t3 = 4.0e+00;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-float.orng:3:10:\n    if f(4.0) {\n        ^";
    _765_t2 = _765_t1(_765_t3);
    $line_idx--;
    if (_765_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _765_t0 = 188;
    goto BB4;
BB5:
    _765_t0 = 4;
    goto BB4;
BB4:
    _765_$retval = _765_t0;
    return _765_$retval;
}

uint8_t _770_f(double _770_x){
    uint8_t _770_$retval;
    (void)_770_x;
    _770_$retval = 1;
    return _770_$retval;
}

int main(void) {
  printf("%ld",_765_main());
  return 0;
}
