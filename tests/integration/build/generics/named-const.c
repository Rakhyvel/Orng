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
int64_t _39_main(void);
int64_t _41_$anon7(void);


/* Function definitions */
int64_t _39_main(void){
    function0 _39_t0;
    int64_t _39_t1;
    int64_t _39_$retval;
    _39_t0 = (function0) _41_$anon7;
    $lines[$line_idx++] = "tests/integration/generics/named-const.orng:12:12:\n    getval(.n = 317)\n          ^";
    _39_t1 = _39_t0();
    $line_idx--;
    _39_$retval = _39_t1;
    return _39_$retval;
}

int64_t _41_$anon7(void){
    int64_t _41_$retval;
    _41_$retval = 317;
    return _41_$retval;
}


int main(void) {
  printf("%ld",_39_main());
  return 0;
}
