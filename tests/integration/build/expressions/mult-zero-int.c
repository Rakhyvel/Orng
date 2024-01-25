/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _812_main(void);
uint8_t _817_f(int64_t _817_x);


/* Function definitions */
int64_t _812_main(void){
    function0 _812_t1;
    int64_t _812_t3;
    uint8_t _812_t2;
    int64_t _812_t0;
    int64_t _812_$retval;
    _812_t1 = _817_f;
    _812_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _812_t2 = _812_t1(_812_t3);
    $line_idx--;
    if (_812_t2) {
        goto BB1003;
    } else {
        goto BB1007;
    }
BB1003:
    _812_t0 = 187;
    goto BB1006;
BB1007:
    _812_t0 = 4;
    goto BB1006;
BB1006:
    _812_$retval = _812_t0;
    return _812_$retval;
}

uint8_t _817_f(int64_t _817_x){
    uint8_t _817_$retval;
    (void)_817_x;
    _817_$retval = 1;
    return _817_$retval;
}


int main(void) {
  printf("%ld",_812_main());
  return 0;
}
