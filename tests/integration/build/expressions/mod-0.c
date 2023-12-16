/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _767_main(void);
uint8_t _772_f(int64_t _772_x);

/* Function definitions */
int64_t _767_main(void){
    function0 _767_t1;
    int64_t _767_t3;
    uint8_t _767_t2;
    int64_t _767_t0;
    int64_t _767_$retval;
    _767_t1 = _772_f;
    _767_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _767_t2 = _767_t1(_767_t3);
    $line_idx--;
    if (_767_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _767_t0 = 191;
    goto BB4;
BB5:
    _767_t0 = 4;
    goto BB4;
BB4:
    _767_$retval = _767_t0;
    return _767_$retval;
}

uint8_t _772_f(int64_t _772_x){
    uint8_t _772_$retval;
    (void)_772_x;
    _772_$retval = 1;
    return _772_$retval;
}

int main(void) {
  printf("%ld",_767_main());
  return 0;
}
