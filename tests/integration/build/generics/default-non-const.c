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
int64_t _34_main(void);
int64_t _36_$anon6(int64_t _36_m);


/* Function definitions */
int64_t _34_main(void){
    function0 _34_t0;
    int64_t _34_t2;
    int64_t _34_t1;
    int64_t _34_$retval;
    _34_t0 = (function0) _36_$anon6;
    _34_t2 = 300;
    $lines[$line_idx++] = "tests/integration/generics/default-non-const.orng:8:12:\n    getval(16)\n          ^";
    _34_t1 = _34_t0(_34_t2);
    $line_idx--;
    _34_$retval = _34_t1;
    return _34_$retval;
}

int64_t _36_$anon6(int64_t _36_m){
    int64_t _36_t0;
    int64_t _36_$retval;
    _36_t0 = 16;
    _36_$retval = $add_int64_t(_36_t0, _36_m, "tests/integration/generics/default-non-const.orng:4:8:\n    n + m\n      ^");
    return _36_$retval;
}


int main(void) {
  printf("%ld",_34_main());
  return 0;
}
