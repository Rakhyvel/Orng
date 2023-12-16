/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _869_main(void);
uint8_t _874_f(int64_t _874_x);

/* Function definitions */
int64_t _869_main(void){
    function0 _869_t1;
    int64_t _869_t3;
    uint8_t _869_t2;
    int64_t _869_t0;
    int64_t _869_$retval;
    _869_t1 = _874_f;
    _869_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _869_t2 = _869_t1(_869_t3);
    $line_idx--;
    if (_869_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _869_t0 = 228;
    goto BB4;
BB5:
    _869_t0 = 0;
    goto BB4;
BB4:
    _869_$retval = _869_t0;
    return _869_$retval;
}

uint8_t _874_f(int64_t _874_x){
    uint8_t _874_$retval;
    (void)_874_x;
    _874_$retval = 1;
    return _874_$retval;
}

int main(void) {
  printf("%ld",_869_main());
  return 0;
}
