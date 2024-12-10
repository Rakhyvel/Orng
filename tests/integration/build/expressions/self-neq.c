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
int64_t _878_main(void);
uint8_t _883_f(int64_t _883_x);


/* Function definitions */
int64_t _878_main(void){
    function0 _878_t1;
    int64_t _878_t3;
    uint8_t _878_t2;
    int64_t _878_t0;
    int64_t _878_$retval;
    _878_t1 = (function0) _883_f;
    _878_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _878_t2 = _878_t1(_878_t3);
    $line_idx--;
    if (_878_t2) {
        goto BB1059;
    } else {
        goto BB1063;
    }
BB1059:
    _878_t0 = 0;
    goto BB1062;
BB1063:
    _878_t0 = 223;
    goto BB1062;
BB1062:
    _878_$retval = _878_t0;
    return _878_$retval;
}

uint8_t _883_f(int64_t _883_x){
    uint8_t _883_$retval;
    (void)_883_x;
    goto BB1054;
BB1054:
    _883_$retval = 0;
    return _883_$retval;
}


int main(void) {
  printf("%ld",_878_main());
  return 0;
}
