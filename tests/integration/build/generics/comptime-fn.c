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
int64_t _1017_main(void);
int64_t _1019_$anon94(void);


/* Function definitions */
int64_t _1017_main(void){
    function0 _1017_t0;
    int64_t _1017_t1;
    int64_t _1017_$retval;
    _1017_t0 = (function0) _1019_$anon94;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn.orng:11:9:\n    add(Int)\n       ^";
    _1017_t1 = _1017_t0();
    $line_idx--;
    _1017_$retval = _1017_t1;
    return _1017_$retval;
}

int64_t _1019_$anon94(void){
    int64_t _1019_$retval;
    _1019_$retval = 311;
    return _1019_$retval;
}


int main(void) {
  printf("%ld",_1017_main());
  return 0;
}
