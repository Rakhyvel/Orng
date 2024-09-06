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
int64_t _1055_main(void);
int64_t _1057_$anon100(int64_t _1057_m);


/* Function definitions */
int64_t _1055_main(void){
    function0 _1055_t0;
    int64_t _1055_t2;
    int64_t _1055_t1;
    int64_t _1055_$retval;
    _1055_t0 = (function0) _1057_$anon100;
    _1055_t2 = 300;
    $lines[$line_idx++] = "tests/integration/generics/default-non-const.orng:8:12:\n    getval(16)\n          ^";
    _1055_t1 = _1055_t0(_1055_t2);
    $line_idx--;
    _1055_$retval = _1055_t1;
    return _1055_$retval;
}

int64_t _1057_$anon100(int64_t _1057_m){
    int64_t _1057_t0;
    int64_t _1057_$retval;
    _1057_t0 = 16;
    _1057_$retval = $add_int64_t(_1057_t0, _1057_m, "tests/integration/generics/default-non-const.orng:4:8:\n    n + m\n      ^");
    return _1057_$retval;
}


int main(void) {
  printf("%ld",_1055_main());
  return 0;
}
