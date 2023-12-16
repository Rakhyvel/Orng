/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _775_main(void);
uint8_t _780_f(int64_t _780_x);

/* Function definitions */
int64_t _775_main(void){
    function0 _775_t1;
    int64_t _775_t3;
    uint8_t _775_t2;
    int64_t _775_t0;
    int64_t _775_$retval;
    _775_t1 = _780_f;
    _775_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _775_t2 = _775_t1(_775_t3);
    $line_idx--;
    if (_775_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _775_t0 = 192;
    goto BB4;
BB5:
    _775_t0 = 4;
    goto BB4;
BB4:
    _775_$retval = _775_t0;
    return _775_$retval;
}

uint8_t _780_f(int64_t _780_x){
    uint8_t _780_$retval;
    (void)_780_x;
    _780_$retval = 1;
    return _780_$retval;
}

int main(void) {
  printf("%ld",_775_main());
  return 0;
}
