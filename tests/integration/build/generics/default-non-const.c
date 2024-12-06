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
int64_t _1061_main(void);
int64_t _1063_$anon101(int64_t _1063_m);


/* Function definitions */
int64_t _1061_main(void){
    function0 _1061_t0;
    int64_t _1061_t2;
    int64_t _1061_t1;
    int64_t _1061_$retval;
    _1061_t0 = (function0) _1063_$anon101;
    _1061_t2 = 300;
    $lines[$line_idx++] = "tests/integration/generics/default-non-const.orng:8:12:\n    getval(16)\n          ^";
    _1061_t1 = _1061_t0(_1061_t2);
    $line_idx--;
    _1061_$retval = _1061_t1;
    return _1061_$retval;
}

int64_t _1063_$anon101(int64_t _1063_m){
    int64_t _1063_t0;
    int64_t _1063_$retval;
    _1063_t0 = 16;
    _1063_$retval = $add_int64_t(_1063_t0, _1063_m, "tests/integration/generics/default-non-const.orng:4:8:\n    n + m\n      ^");
    return _1063_$retval;
}


int main(void) {
  printf("%ld",_1061_main());
  return 0;
}
