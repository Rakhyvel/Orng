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
int64_t _950_main(void);
int64_t _952_return53(int64_t _952_x);


/* Function definitions */
int64_t _950_main(void){
    function0 _950_t0;
    int64_t _950_t2;
    int64_t _950_t1;
    int64_t _950_$retval;
    _950_t0 = (function0) _952_return53;
    _950_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _950_t1 = _950_t0(_950_t2);
    $line_idx--;
    _950_$retval = _950_t1;
    return _950_$retval;
}

int64_t _952_return53(int64_t _952_x){
    int64_t _952_$retval;
    goto BB1123;
BB1123:
    _952_$retval = _952_x;
    return _952_$retval;
}


int main(void) {
  printf("%ld",_950_main());
  return 0;
}
