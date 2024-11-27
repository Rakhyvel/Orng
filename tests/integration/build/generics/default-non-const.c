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
int64_t _40_main(void);
int64_t _42_$anon7(int64_t _42_m);


/* Function definitions */
int64_t _40_main(void){
    function0 _40_t0;
    int64_t _40_t2;
    int64_t _40_t1;
    int64_t _40_$retval;
    _40_t0 = (function0) _42_$anon7;
    _40_t2 = 300;
    $lines[$line_idx++] = "tests/integration/generics/default-non-const.orng:8:12:\n    getval(16)\n          ^";
    _40_t1 = _40_t0(_40_t2);
    $line_idx--;
    _40_$retval = _40_t1;
    return _40_$retval;
}

int64_t _42_$anon7(int64_t _42_m){
    int64_t _42_t0;
    int64_t _42_$retval;
    _42_t0 = 16;
    _42_$retval = $add_int64_t(_42_t0, _42_m, "tests/integration/generics/default-non-const.orng:4:8:\n    n + m\n      ^");
    return _42_$retval;
}


int main(void) {
  printf("%ld",_40_main());
  return 0;
}
