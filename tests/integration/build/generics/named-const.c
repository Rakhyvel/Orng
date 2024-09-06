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
int64_t _1055_main(void);
int64_t _1057_$anon101(void);


/* Function definitions */
int64_t _1055_main(void){
    function0 _1055_t0;
    int64_t _1055_t1;
    int64_t _1055_$retval;
    _1055_t0 = (function0) _1057_$anon101;
    $lines[$line_idx++] = "tests/integration/generics/named-const.orng:12:12:\n    getval(.n = 317)\n          ^";
    _1055_t1 = _1055_t0();
    $line_idx--;
    _1055_$retval = _1055_t1;
    return _1055_$retval;
}

int64_t _1057_$anon101(void){
    int64_t _1057_$retval;
    goto BB1229;
BB1229:
    _1057_$retval = 317;
    return _1057_$retval;
}


int main(void) {
  printf("%ld",_1055_main());
  return 0;
}
