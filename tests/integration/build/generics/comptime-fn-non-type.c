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
int64_t _15_main(void);
int64_t _17_$anon2(void);


/* Function definitions */
int64_t _15_main(void){
    function0 _15_t0;
    int64_t _15_t1;
    int64_t _15_$retval;
    _15_t0 = (function0) _17_$anon2;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-non-type.orng:6:12:\n    getval(300, 14)\n          ^";
    _15_t1 = _15_t0();
    $line_idx--;
    _15_$retval = _15_t1;
    return _15_$retval;
}

int64_t _17_$anon2(void){
    int64_t _17_$retval;
    _17_$retval = 314;
    return _17_$retval;
}


int main(void) {
  printf("%ld",_15_main());
  return 0;
}
