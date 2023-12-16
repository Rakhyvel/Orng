/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _877_main(void);
uint8_t _882_f(int64_t _882_x);

/* Function definitions */
int64_t _877_main(void){
    function0 _877_t1;
    int64_t _877_t3;
    uint8_t _877_t2;
    int64_t _877_t0;
    int64_t _877_$retval;
    _877_t1 = _882_f;
    _877_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _877_t2 = _877_t1(_877_t3);
    $line_idx--;
    if (_877_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _877_t0 = 0;
    goto BB4;
BB5:
    _877_t0 = 226;
    goto BB4;
BB4:
    _877_$retval = _877_t0;
    return _877_$retval;
}

uint8_t _882_f(int64_t _882_x){
    uint8_t _882_$retval;
    (void)_882_x;
    _882_$retval = 0;
    return _882_$retval;
}

int main(void) {
  printf("%ld",_877_main());
  return 0;
}
