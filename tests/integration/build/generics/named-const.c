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
int64_t _1054_main(void);
int64_t _1056_$anon101(void);


/* Function definitions */
int64_t _1054_main(void){
    function0 _1054_t0;
    int64_t _1054_t1;
    int64_t _1054_$retval;
    _1054_t0 = (function0) _1056_$anon101;
    $lines[$line_idx++] = "tests/integration/generics/named-const.orng:12:12:\n    getval(.n = 317)\n          ^";
    _1054_t1 = _1054_t0();
    $line_idx--;
    _1054_$retval = _1054_t1;
    return _1054_$retval;
}

int64_t _1056_$anon101(void){
    int64_t _1056_$retval;
    _1056_$retval = 317;
    return _1056_$retval;
}


int main(void) {
  printf("%ld",_1054_main());
  return 0;
}