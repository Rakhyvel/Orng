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
int64_t _1074_main(void);
int64_t _1076_$anon103(int64_t _1076_m);


/* Function definitions */
int64_t _1074_main(void){
    function0 _1074_t0;
    int64_t _1074_t2;
    int64_t _1074_t1;
    int64_t _1074_$retval;
    _1074_t0 = (function0) _1076_$anon103;
    _1074_t2 = 300;
    $lines[$line_idx++] = "tests/integration/generics/default-non-const.orng:8:12:\n    getval(16)\n          ^";
    _1074_t1 = _1074_t0(_1074_t2);
    $line_idx--;
    _1074_$retval = _1074_t1;
    return _1074_$retval;
}

int64_t _1076_$anon103(int64_t _1076_m){
    int64_t _1076_t0;
    int64_t _1076_$retval;
    _1076_t0 = 16;
    _1076_$retval = $add_int64_t(_1076_t0, _1076_m, "tests/integration/generics/default-non-const.orng:4:8:\n    n + m\n      ^");
    return _1076_$retval;
}


int main(void) {
  printf("%ld",_1074_main());
  return 0;
}
