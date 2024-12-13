/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _1096_main(void);
int64_t _1098_$anon107(void);


/* Function definitions */
int64_t _1096_main(void){
    function0 _1096_t0;
    int64_t _1096_t1;
    int64_t _1096_$retval;
    _1096_t0 = (function0) _1098_$anon107;
    $lines[$line_idx++] = "tests/integration/generics/named-const.orng:12:12:\n    getval(.n = 317)\n          ^";
    _1096_t1 = _1096_t0();
    $line_idx--;
    _1096_$retval = _1096_t1;
    return _1096_$retval;
}

int64_t _1098_$anon107(void){
    int64_t _1098_$retval;
    goto BB1273;
BB1273:
    _1098_$retval = 317;
    return _1098_$retval;
}


int main(void) {
  printf("%ld",_1096_main());
  return 0;
}
