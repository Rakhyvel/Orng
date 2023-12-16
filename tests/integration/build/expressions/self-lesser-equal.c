/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _798_main(void);
uint8_t _803_f(int64_t _803_x);

/* Function definitions */
int64_t _798_main(void){
    function0 _798_t1;
    int64_t _798_t3;
    uint8_t _798_t2;
    int64_t _798_t0;
    int64_t _798_$retval;
    _798_t1 = _803_f;
    _798_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _798_t2 = _798_t1(_798_t3);
    $line_idx--;
    if (_798_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _798_t0 = 228;
    goto BB4;
BB5:
    _798_t0 = 0;
    goto BB4;
BB4:
    _798_$retval = _798_t0;
    return _798_$retval;
}

uint8_t _803_f(int64_t _803_x){
    uint8_t _803_$retval;
    (void)_803_x;
    _803_$retval = 1;
    return _803_$retval;
}

int main(void) {
  printf("%ld",_798_main());
  return 0;
}
