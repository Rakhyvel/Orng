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
int64_t _1047_main(void);
int64_t _1049_$anon100(void);


/* Function definitions */
int64_t _1047_main(void){
    function0 _1047_t0;
    int64_t _1047_t1;
    int64_t _1047_$retval;
    _1047_t0 = (function0) _1049_$anon100;
    $lines[$line_idx++] = "tests/integration/generics/default-const.orng:12:12:\n    getval()\n          ^";
    _1047_t1 = _1047_t0();
    $line_idx--;
    _1047_$retval = _1047_t1;
    return _1047_$retval;
}

int64_t _1049_$anon100(void){
    int64_t _1049_$retval;
    goto BB1217;
BB1217:
    _1049_$retval = 315;
    return _1049_$retval;
}


int main(void) {
  printf("%ld",_1047_main());
  return 0;
}
