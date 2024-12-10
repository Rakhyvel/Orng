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
int64_t _1094_main(void);
int64_t _1096_$anon107(void);


/* Function definitions */
int64_t _1094_main(void){
    function0 _1094_t0;
    int64_t _1094_t1;
    int64_t _1094_$retval;
    _1094_t0 = (function0) _1096_$anon107;
    $lines[$line_idx++] = "tests/integration/generics/named-const.orng:12:12:\n    getval(.n = 317)\n          ^";
    _1094_t1 = _1094_t0();
    $line_idx--;
    _1094_$retval = _1094_t1;
    return _1094_$retval;
}

int64_t _1096_$anon107(void){
    int64_t _1096_$retval;
    goto BB1271;
BB1271:
    _1096_$retval = 317;
    return _1096_$retval;
}


int main(void) {
  printf("%ld",_1094_main());
  return 0;
}
