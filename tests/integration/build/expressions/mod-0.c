/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _735_main(void);
uint8_t _740_f(int64_t _740_x);

/* Function definitions */
int64_t _735_main(void){
    function0 _735_t1;
    int64_t _735_t3;
    uint8_t _735_t2;
    int64_t _735_t0;
    int64_t _735_$retval;
    _735_t1 = _740_f;
    _735_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _735_t2 = _735_t1(_735_t3);
    $line_idx--;
    if (_735_t2) {
        goto BB930;
    } else {
        goto BB934;
    }
BB930:
    _735_t0 = 191;
    goto BB933;
BB934:
    _735_t0 = 4;
    goto BB933;
BB933:
    _735_$retval = _735_t0;
    return _735_$retval;
}

uint8_t _740_f(int64_t _740_x){
    uint8_t _740_$retval;
    (void)_740_x;
    _740_$retval = 1;
    return _740_$retval;
}

int main(void) {
  printf("%ld",_735_main());
  return 0;
}
