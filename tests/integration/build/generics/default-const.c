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
int64_t _1066_main(void);
int64_t _1068_$anon102(void);


/* Function definitions */
int64_t _1066_main(void){
    function0 _1066_t0;
    int64_t _1066_t1;
    int64_t _1066_$retval;
    _1066_t0 = (function0) _1068_$anon102;
    $lines[$line_idx++] = "tests/integration/generics/default-const.orng:12:12:\n    getval()\n          ^";
    _1066_t1 = _1066_t0();
    $line_idx--;
    _1066_$retval = _1066_t1;
    return _1066_$retval;
}

int64_t _1068_$anon102(void){
    int64_t _1068_$retval;
    goto BB1239;
BB1239:
    _1068_$retval = 315;
    return _1068_$retval;
}


int main(void) {
  printf("%ld",_1066_main());
  return 0;
}
