/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _723_main(void);
uint8_t _728_f(int64_t _728_x);

/* Function definitions */
int64_t _723_main(void){
    function0 _723_t1;
    int64_t _723_t3;
    uint8_t _723_t2;
    int64_t _723_t0;
    int64_t _723_$retval;
    _723_t1 = _728_f;
    _723_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _723_t2 = _723_t1(_723_t3);
    $line_idx--;
    if (_723_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _723_t0 = 186;
    goto BB4;
BB5:
    _723_t0 = 4;
    goto BB4;
BB4:
    _723_$retval = _723_t0;
    return _723_$retval;
}

uint8_t _728_f(int64_t _728_x){
    uint8_t _728_$retval;
    (void)_728_x;
    _728_$retval = 1;
    return _728_$retval;
}

int main(void) {
  printf("%ld",_723_main());
  return 0;
}
