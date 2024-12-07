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
int64_t _1061_main(void);
int64_t _1063_$anon100(void);


/* Function definitions */
int64_t _1061_main(void){
    function0 _1061_t0;
    int64_t _1061_t1;
    int64_t _1061_$retval;
    _1061_t0 = (function0) _1063_$anon100;
    $lines[$line_idx++] = "tests/integration/generics/default-const.orng:12:12:\n    getval()\n          ^";
    _1061_t1 = _1061_t0();
    $line_idx--;
    _1061_$retval = _1061_t1;
    return _1061_$retval;
}

int64_t _1063_$anon100(void){
    int64_t _1063_$retval;
    goto BB1236;
BB1236:
    _1063_$retval = 315;
    return _1063_$retval;
}


int main(void) {
  printf("%ld",_1061_main());
  return 0;
}
