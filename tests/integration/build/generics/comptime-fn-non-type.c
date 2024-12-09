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
int64_t _1049_main(void);
int64_t _1051_$anon98(void);


/* Function definitions */
int64_t _1049_main(void){
    function0 _1049_t0;
    int64_t _1049_t1;
    int64_t _1049_$retval;
    _1049_t0 = (function0) _1051_$anon98;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-non-type.orng:6:12:\n    getval(300, 14)\n          ^";
    _1049_t1 = _1049_t0();
    $line_idx--;
    _1049_$retval = _1049_t1;
    return _1049_$retval;
}

int64_t _1051_$anon98(void){
    int64_t _1051_$retval;
    _1051_$retval = 314;
    return _1051_$retval;
}


int main(void) {
  printf("%ld",_1049_main());
  return 0;
}
