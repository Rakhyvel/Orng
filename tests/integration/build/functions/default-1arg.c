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
int64_t _961_main(void);
int64_t _963_return53(int64_t _963_x);


/* Function definitions */
int64_t _961_main(void){
    function0 _961_t0;
    int64_t _961_t2;
    int64_t _961_t1;
    int64_t _961_$retval;
    _961_t0 = (function0) _963_return53;
    _961_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _961_t1 = _961_t0(_961_t2);
    $line_idx--;
    _961_$retval = _961_t1;
    return _961_$retval;
}

int64_t _963_return53(int64_t _963_x){
    int64_t _963_$retval;
    goto BB1139;
BB1139:
    _963_$retval = _963_x;
    return _963_$retval;
}


int main(void) {
  printf("%ld",_961_main());
  return 0;
}
