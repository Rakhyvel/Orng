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
int64_t _858_main(void);
uint8_t _863_f(int64_t _863_x);


/* Function definitions */
int64_t _858_main(void){
    function0 _858_t1;
    int64_t _858_t3;
    uint8_t _858_t2;
    int64_t _858_t0;
    int64_t _858_$retval;
    _858_t1 = (function0) _863_f;
    _858_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _858_t2 = _858_t1(_858_t3);
    $line_idx--;
    if (_858_t2) {
        goto BB1040;
    } else {
        goto BB1044;
    }
BB1040:
    _858_t0 = 0;
    goto BB1043;
BB1044:
    _858_t0 = 223;
    goto BB1043;
BB1043:
    _858_$retval = _858_t0;
    return _858_$retval;
}

uint8_t _863_f(int64_t _863_x){
    uint8_t _863_$retval;
    (void)_863_x;
    _863_$retval = 0;
    return _863_$retval;
}


int main(void) {
  printf("%ld",_858_main());
  return 0;
}
