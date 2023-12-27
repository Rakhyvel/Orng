/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _853_main(void);
uint8_t _858_f(int64_t _858_x);

/* Function definitions */
int64_t _853_main(void){
    function0 _853_t1;
    int64_t _853_t3;
    uint8_t _853_t2;
    int64_t _853_t0;
    int64_t _853_$retval;
    _853_t1 = _858_f;
    _853_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _853_t2 = _853_t1(_853_t3);
    $line_idx--;
    if (_853_t2) {
        goto BB1078;
    } else {
        goto BB1082;
    }
BB1078:
    _853_t0 = 0;
    goto BB1081;
BB1082:
    _853_t0 = 223;
    goto BB1081;
BB1081:
    _853_$retval = _853_t0;
    return _853_$retval;
}

uint8_t _858_f(int64_t _858_x){
    uint8_t _858_$retval;
    (void)_858_x;
    _858_$retval = 0;
    return _858_$retval;
}

int main(void) {
  printf("%ld",_853_main());
  return 0;
}
