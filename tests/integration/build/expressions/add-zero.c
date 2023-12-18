/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _734_main(void);
uint8_t _739_f(int64_t _739_x);

/* Function definitions */
int64_t _734_main(void){
    function0 _734_t1;
    int64_t _734_t3;
    uint8_t _734_t2;
    int64_t _734_t0;
    int64_t _734_$retval;
    _734_t1 = _739_f;
    _734_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _734_t2 = _734_t1(_734_t3);
    $line_idx--;
    if (_734_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _734_t0 = 182;
    goto BB4;
BB5:
    _734_t0 = 4;
    goto BB4;
BB4:
    _734_$retval = _734_t0;
    return _734_$retval;
}

uint8_t _739_f(int64_t _739_x){
    uint8_t _739_$retval;
    (void)_739_x;
    _739_$retval = 1;
    return _739_$retval;
}

int main(void) {
  printf("%ld",_734_main());
  return 0;
}
