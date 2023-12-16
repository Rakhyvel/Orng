/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _814_main(void);
uint8_t _819_f(int64_t _819_x);

/* Function definitions */
int64_t _814_main(void){
    function0 _814_t1;
    int64_t _814_t3;
    uint8_t _814_t2;
    int64_t _814_t0;
    int64_t _814_$retval;
    _814_t1 = _819_f;
    _814_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _814_t2 = _814_t1(_814_t3);
    $line_idx--;
    if (_814_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _814_t0 = 0;
    goto BB4;
BB5:
    _814_t0 = 223;
    goto BB4;
BB4:
    _814_$retval = _814_t0;
    return _814_$retval;
}

uint8_t _819_f(int64_t _819_x){
    uint8_t _819_$retval;
    (void)_819_x;
    _819_$retval = 0;
    return _819_$retval;
}

int main(void) {
  printf("%ld",_814_main());
  return 0;
}
