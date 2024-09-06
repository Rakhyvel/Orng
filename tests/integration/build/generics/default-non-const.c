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
int64_t _1050_main(void);
int64_t _1052_$anon100(int64_t _1052_m);


/* Function definitions */
int64_t _1050_main(void){
    function0 _1050_t0;
    int64_t _1050_t2;
    int64_t _1050_t1;
    int64_t _1050_$retval;
    _1050_t0 = (function0) _1052_$anon100;
    _1050_t2 = 300;
    $lines[$line_idx++] = "tests/integration/generics/default-non-const.orng:8:12:\n    getval(16)\n          ^";
    _1050_t1 = _1050_t0(_1050_t2);
    $line_idx--;
    _1050_$retval = _1050_t1;
    return _1050_$retval;
}

int64_t _1052_$anon100(int64_t _1052_m){
    int64_t _1052_t0;
    int64_t _1052_$retval;
    _1052_t0 = 16;
    _1052_$retval = $add_int64_t(_1052_t0, _1052_m, "tests/integration/generics/default-non-const.orng:4:8:\n    n + m\n      ^");
    return _1052_$retval;
}


int main(void) {
  printf("%ld",_1050_main());
  return 0;
}
