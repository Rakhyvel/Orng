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
int64_t _26_main(void);
int64_t _28_$anon5(void);


/* Function definitions */
int64_t _26_main(void){
    function0 _26_t0;
    int64_t _26_t1;
    int64_t _26_$retval;
    _26_t0 = (function0) _28_$anon5;
    $lines[$line_idx++] = "tests/integration/generics/default-const.orng:12:12:\n    getval()\n          ^";
    _26_t1 = _26_t0();
    $line_idx--;
    _26_$retval = _26_t1;
    return _26_$retval;
}

int64_t _28_$anon5(void){
    int64_t _28_$retval;
    _28_$retval = 315;
    return _28_$retval;
}


int main(void) {
  printf("%ld",_26_main());
  return 0;
}
