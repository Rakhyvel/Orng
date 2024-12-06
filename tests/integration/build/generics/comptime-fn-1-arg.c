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
int64_t _1026_main(void);
int64_t _1028_$anon94(void);


/* Function definitions */
int64_t _1026_main(void){
    function0 _1026_t0;
    int64_t _1026_t1;
    int64_t _1026_$retval;
    _1026_t0 = (function0) _1028_$anon94;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-1-arg.orng:6:12:\n    getval(Int)\n          ^";
    _1026_t1 = _1026_t0();
    $line_idx--;
    _1026_$retval = _1026_t1;
    return _1026_$retval;
}

int64_t _1028_$anon94(void){
    int64_t _1028_$retval;
    _1028_$retval = 313;
    return _1028_$retval;
}


int main(void) {
  printf("%ld",_1026_main());
  return 0;
}
