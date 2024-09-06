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
int64_t _1022_main(void);
int64_t _1024_$anon95(void);


/* Function definitions */
int64_t _1022_main(void){
    function0 _1022_t0;
    int64_t _1022_t1;
    int64_t _1022_$retval;
    _1022_t0 = (function0) _1024_$anon95;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-non-type.orng:6:12:\n    getval(300, 14)\n          ^";
    _1022_t1 = _1022_t0();
    $line_idx--;
    _1022_$retval = _1022_t1;
    return _1022_$retval;
}

int64_t _1024_$anon95(void){
    int64_t _1024_$retval;
    _1024_$retval = 314;
    return _1024_$retval;
}


int main(void) {
  printf("%ld",_1022_main());
  return 0;
}
