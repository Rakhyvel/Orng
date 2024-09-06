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
int64_t _1060_main(void);
int64_t _1062_$anon101(void);


/* Function definitions */
int64_t _1060_main(void){
    function0 _1060_t0;
    int64_t _1060_t1;
    int64_t _1060_$retval;
    _1060_t0 = (function0) _1062_$anon101;
    $lines[$line_idx++] = "tests/integration/generics/named-const.orng:12:12:\n    getval(.n = 317)\n          ^";
    _1060_t1 = _1060_t0();
    $line_idx--;
    _1060_$retval = _1060_t1;
    return _1060_$retval;
}

int64_t _1062_$anon101(void){
    int64_t _1062_$retval;
    goto BB1233;
BB1233:
    _1062_$retval = 317;
    return _1062_$retval;
}


int main(void) {
  printf("%ld",_1060_main());
  return 0;
}
