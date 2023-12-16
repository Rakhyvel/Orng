/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _825_main(void);
uint8_t _830_f(int64_t _830_x);

/* Function definitions */
int64_t _825_main(void){
    function0 _825_t1;
    int64_t _825_t3;
    uint8_t _825_t2;
    int64_t _825_t0;
    int64_t _825_$retval;
    _825_t1 = _830_f;
    _825_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _825_t2 = _825_t1(_825_t3);
    $line_idx--;
    if (_825_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _825_t0 = 0;
    goto BB4;
BB5:
    _825_t0 = 223;
    goto BB4;
BB4:
    _825_$retval = _825_t0;
    return _825_$retval;
}

uint8_t _830_f(int64_t _830_x){
    uint8_t _830_$retval;
    (void)_830_x;
    _830_$retval = 0;
    return _830_$retval;
}

int main(void) {
  printf("%ld",_825_main());
  return 0;
}
