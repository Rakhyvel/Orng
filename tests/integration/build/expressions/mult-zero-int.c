/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _773_main(void);
uint8_t _778_f(int64_t _778_x);

/* Function definitions */
int64_t _773_main(void){
    function0 _773_t1;
    int64_t _773_t3;
    uint8_t _773_t2;
    int64_t _773_t0;
    int64_t _773_$retval;
    _773_t1 = _778_f;
    _773_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _773_t2 = _773_t1(_773_t3);
    $line_idx--;
    if (_773_t2) {
        goto BB1006;
    } else {
        goto BB1010;
    }
BB1006:
    _773_t0 = 187;
    goto BB1009;
BB1010:
    _773_t0 = 4;
    goto BB1009;
BB1009:
    _773_$retval = _773_t0;
    return _773_$retval;
}

uint8_t _778_f(int64_t _778_x){
    uint8_t _778_$retval;
    (void)_778_x;
    _778_$retval = 1;
    return _778_$retval;
}

int main(void) {
  printf("%ld",_773_main());
  return 0;
}
