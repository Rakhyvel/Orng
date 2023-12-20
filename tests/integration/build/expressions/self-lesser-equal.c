/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _837_main(void);
uint8_t _842_f(int64_t _842_x);

/* Function definitions */
int64_t _837_main(void){
    function0 _837_t1;
    int64_t _837_t3;
    uint8_t _837_t2;
    int64_t _837_t0;
    int64_t _837_$retval;
    _837_t1 = _842_f;
    _837_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _837_t2 = _837_t1(_837_t3);
    $line_idx--;
    if (_837_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _837_t0 = 228;
    goto BB4;
BB5:
    _837_t0 = 0;
    goto BB4;
BB4:
    _837_$retval = _837_t0;
    return _837_$retval;
}

uint8_t _842_f(int64_t _842_x){
    uint8_t _842_$retval;
    (void)_842_x;
    _842_$retval = 1;
    return _842_$retval;
}

int main(void) {
  printf("%ld",_837_main());
  return 0;
}
