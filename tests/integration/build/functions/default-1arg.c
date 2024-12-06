/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _948_main(void);
int64_t _950_return53(int64_t _950_x);


/* Function definitions */
int64_t _948_main(void){
    function0 _948_t0;
    int64_t _948_t2;
    int64_t _948_t1;
    int64_t _948_$retval;
    _948_t0 = (function0) _950_return53;
    _948_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _948_t1 = _948_t0(_948_t2);
    $line_idx--;
    _948_$retval = _948_t1;
    return _948_$retval;
}

int64_t _950_return53(int64_t _950_x){
    int64_t _950_$retval;
    goto BB1126;
BB1126:
    _950_$retval = _950_x;
    return _950_$retval;
}


int main(void) {
  printf("%ld",_948_main());
  return 0;
}
