/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _969_main(void);
uint8_t _974_f(int64_t _974_x);

/* Function definitions */
int64_t _969_main(void){
    function0 _969_t1;
    int64_t _969_t3;
    uint8_t _969_t2;
    int64_t _969_t0;
    int64_t _969_$retval;
    _969_t1 = _974_f;
    _969_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _969_t2 = _969_t1(_969_t3);
    $line_idx--;
    if (_969_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _969_t0 = 0;
    goto BB4;
BB5:
    _969_t0 = 226;
    goto BB4;
BB4:
    _969_$retval = _969_t0;
    return _969_$retval;
}

uint8_t _974_f(int64_t _974_x){
    uint8_t _974_$retval;
    (void)_974_x;
    _974_$retval = 0;
    return _974_$retval;
}

int main(void) {
  printf("%ld",_969_main());
  return 0;
}
