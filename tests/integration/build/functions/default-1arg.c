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
int64_t _956_main(void);
int64_t _958_return53(int64_t _958_x);


/* Function definitions */
int64_t _956_main(void){
    function0 _956_t0;
    int64_t _956_t2;
    int64_t _956_t1;
    int64_t _956_$retval;
    _956_t0 = (function0) _958_return53;
    _956_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _956_t1 = _956_t0(_956_t2);
    $line_idx--;
    _956_$retval = _956_t1;
    return _956_$retval;
}

int64_t _958_return53(int64_t _958_x){
    int64_t _958_$retval;
    goto BB1136;
BB1136:
    _958_$retval = _958_x;
    return _958_$retval;
}


int main(void) {
  printf("%ld",_956_main());
  return 0;
}
