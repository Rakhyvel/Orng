/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _783_main(void);
uint8_t _788_f(int64_t _788_x);

/* Function definitions */
int64_t _783_main(void){
    function0 _783_t1;
    int64_t _783_t3;
    uint8_t _783_t2;
    int64_t _783_t0;
    int64_t _783_$retval;
    _783_t1 = _788_f;
    _783_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _783_t2 = _783_t1(_783_t3);
    $line_idx--;
    if (_783_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _783_t0 = 186;
    goto BB4;
BB5:
    _783_t0 = 4;
    goto BB4;
BB4:
    _783_$retval = _783_t0;
    return _783_$retval;
}

uint8_t _788_f(int64_t _788_x){
    uint8_t _788_$retval;
    (void)_788_x;
    _788_$retval = 1;
    return _788_$retval;
}

int main(void) {
  printf("%ld",_783_main());
  return 0;
}
