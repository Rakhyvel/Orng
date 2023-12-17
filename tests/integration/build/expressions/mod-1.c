/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _860_main(void);
uint8_t _865_f(int64_t _865_x);

/* Function definitions */
int64_t _860_main(void){
    function0 _860_t1;
    int64_t _860_t3;
    uint8_t _860_t2;
    int64_t _860_t0;
    int64_t _860_$retval;
    _860_t1 = _865_f;
    _860_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _860_t2 = _860_t1(_860_t3);
    $line_idx--;
    if (_860_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _860_t0 = 192;
    goto BB4;
BB5:
    _860_t0 = 4;
    goto BB4;
BB4:
    _860_$retval = _860_t0;
    return _860_$retval;
}

uint8_t _865_f(int64_t _865_x){
    uint8_t _865_$retval;
    (void)_865_x;
    _865_$retval = 1;
    return _865_$retval;
}

int main(void) {
  printf("%ld",_860_main());
  return 0;
}
