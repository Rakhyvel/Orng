/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _970_main(void);
uint8_t _975_f(int64_t _975_x);

/* Function definitions */
int64_t _970_main(void){
    function0 _970_t1;
    int64_t _970_t3;
    uint8_t _970_t2;
    int64_t _970_t0;
    int64_t _970_$retval;
    _970_t1 = _975_f;
    _970_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _970_t2 = _970_t1(_970_t3);
    $line_idx--;
    if (_970_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _970_t0 = 0;
    goto BB4;
BB5:
    _970_t0 = 223;
    goto BB4;
BB4:
    _970_$retval = _970_t0;
    return _970_$retval;
}

uint8_t _975_f(int64_t _975_x){
    uint8_t _975_$retval;
    (void)_975_x;
    _975_$retval = 0;
    return _975_$retval;
}

int main(void) {
  printf("%ld",_970_main());
  return 0;
}
