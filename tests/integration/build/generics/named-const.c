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
int64_t _45_main(void);
int64_t _47_$anon8(void);


/* Function definitions */
int64_t _45_main(void){
    function0 _45_t0;
    int64_t _45_t1;
    int64_t _45_$retval;
    _45_t0 = (function0) _47_$anon8;
    $lines[$line_idx++] = "tests/integration/generics/named-const.orng:12:12:\n    getval(.n = 317)\n          ^";
    _45_t1 = _45_t0();
    $line_idx--;
    _45_$retval = _45_t1;
    return _45_$retval;
}

int64_t _47_$anon8(void){
    int64_t _47_$retval;
    goto BB43;
BB43:
    _47_$retval = 317;
    return _47_$retval;
}


int main(void) {
  printf("%ld",_45_main());
  return 0;
}
