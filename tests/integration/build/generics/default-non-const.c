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
int64_t _1049_main(void);
int64_t _1051_$anon100(int64_t _1051_m);


/* Function definitions */
int64_t _1049_main(void){
    function0 _1049_t0;
    int64_t _1049_t2;
    int64_t _1049_t1;
    int64_t _1049_$retval;
    _1049_t0 = (function0) _1051_$anon100;
    _1049_t2 = 300;
    $lines[$line_idx++] = "tests/integration/generics/default-non-const.orng:8:12:\n    getval(16)\n          ^";
    _1049_t1 = _1049_t0(_1049_t2);
    $line_idx--;
    _1049_$retval = _1049_t1;
    return _1049_$retval;
}

int64_t _1051_$anon100(int64_t _1051_m){
    int64_t _1051_t0;
    int64_t _1051_$retval;
    _1051_t0 = 16;
    _1051_$retval = $add_int64_t(_1051_t0, _1051_m, "tests/integration/generics/default-non-const.orng:4:8:\n    n + m\n      ^");
    return _1051_$retval;
}


int main(void) {
  printf("%ld",_1049_main());
  return 0;
}
