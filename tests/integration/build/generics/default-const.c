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
int64_t _32_main(void);
int64_t _34_$anon6(void);


/* Function definitions */
int64_t _32_main(void){
    function0 _32_t0;
    int64_t _32_t1;
    int64_t _32_$retval;
    _32_t0 = (function0) _34_$anon6;
    $lines[$line_idx++] = "tests/integration/generics/default-const.orng:12:12:\n    getval()\n          ^";
    _32_t1 = _32_t0();
    $line_idx--;
    _32_$retval = _32_t1;
    return _32_$retval;
}

int64_t _34_$anon6(void){
    int64_t _34_$retval;
    goto BB27;
BB27:
    _34_$retval = 315;
    return _34_$retval;
}


int main(void) {
  printf("%ld",_32_main());
  return 0;
}
