/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _793_main(void);
uint8_t _798_f(int64_t _798_x);

/* Function definitions */
int64_t _793_main(void){
    function0 _793_t1;
    int64_t _793_t3;
    uint8_t _793_t2;
    int64_t _793_t0;
    int64_t _793_$retval;
    _793_t1 = _798_f;
    _793_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater-equal.orng:3:10:\n    if f(4) {\n        ^";
    _793_t2 = _793_t1(_793_t3);
    $line_idx--;
    if (_793_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _793_t0 = 227;
    goto BB4;
BB5:
    _793_t0 = 0;
    goto BB4;
BB4:
    _793_$retval = _793_t0;
    return _793_$retval;
}

uint8_t _798_f(int64_t _798_x){
    uint8_t _798_$retval;
    (void)_798_x;
    _798_$retval = 1;
    return _798_$retval;
}

int main(void) {
  printf("%ld",_793_main());
  return 0;
}
