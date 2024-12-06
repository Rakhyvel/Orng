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
int64_t _1053_main(void);
int64_t _1055_$anon100(void);


/* Function definitions */
int64_t _1053_main(void){
    function0 _1053_t0;
    int64_t _1053_t1;
    int64_t _1053_$retval;
    _1053_t0 = (function0) _1055_$anon100;
    $lines[$line_idx++] = "tests/integration/generics/default-const.orng:12:12:\n    getval()\n          ^";
    _1053_t1 = _1053_t0();
    $line_idx--;
    _1053_$retval = _1053_t1;
    return _1053_$retval;
}

int64_t _1055_$anon100(void){
    int64_t _1055_$retval;
    goto BB1226;
BB1226:
    _1055_$retval = 315;
    return _1055_$retval;
}


int main(void) {
  printf("%ld",_1053_main());
  return 0;
}
