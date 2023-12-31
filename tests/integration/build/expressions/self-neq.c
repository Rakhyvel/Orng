/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _865_main(void);
uint8_t _870_f(int64_t _870_x);

/* Function definitions */
int64_t _865_main(void){
    function0 _865_t1;
    int64_t _865_t3;
    uint8_t _865_t2;
    int64_t _865_t0;
    int64_t _865_$retval;
    _865_t1 = _870_f;
    _865_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _865_t2 = _865_t1(_865_t3);
    $line_idx--;
    if (_865_t2) {
        goto BB1088;
    } else {
        goto BB1092;
    }
BB1088:
    _865_t0 = 0;
    goto BB1091;
BB1092:
    _865_t0 = 223;
    goto BB1091;
BB1091:
    _865_$retval = _865_t0;
    return _865_$retval;
}

uint8_t _870_f(int64_t _870_x){
    uint8_t _870_$retval;
    (void)_870_x;
    _870_$retval = 0;
    return _870_$retval;
}

int main(void) {
  printf("%ld",_865_main());
  return 0;
}
