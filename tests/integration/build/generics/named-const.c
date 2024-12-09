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
int64_t _1079_main(void);
int64_t _1081_$anon104(void);


/* Function definitions */
int64_t _1079_main(void){
    function0 _1079_t0;
    int64_t _1079_t1;
    int64_t _1079_$retval;
    _1079_t0 = (function0) _1081_$anon104;
    $lines[$line_idx++] = "tests/integration/generics/named-const.orng:12:12:\n    getval(.n = 317)\n          ^";
    _1079_t1 = _1079_t0();
    $line_idx--;
    _1079_$retval = _1079_t1;
    return _1079_$retval;
}

int64_t _1081_$anon104(void){
    int64_t _1081_$retval;
    goto BB1255;
BB1255:
    _1081_$retval = 317;
    return _1081_$retval;
}


int main(void) {
  printf("%ld",_1079_main());
  return 0;
}
