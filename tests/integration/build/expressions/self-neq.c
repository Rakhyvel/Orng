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
int64_t _863_main(void);
uint8_t _868_f(int64_t _868_x);


/* Function definitions */
int64_t _863_main(void){
    function0 _863_t1;
    int64_t _863_t3;
    uint8_t _863_t2;
    int64_t _863_t0;
    int64_t _863_$retval;
    _863_t1 = (function0) _868_f;
    _863_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _863_t2 = _863_t1(_863_t3);
    $line_idx--;
    if (_863_t2) {
        goto BB1043;
    } else {
        goto BB1047;
    }
BB1043:
    _863_t0 = 0;
    goto BB1046;
BB1047:
    _863_t0 = 223;
    goto BB1046;
BB1046:
    _863_$retval = _863_t0;
    return _863_$retval;
}

uint8_t _868_f(int64_t _868_x){
    uint8_t _868_$retval;
    (void)_868_x;
    goto BB1038;
BB1038:
    _868_$retval = 0;
    return _868_$retval;
}


int main(void) {
  printf("%ld",_863_main());
  return 0;
}
