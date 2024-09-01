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
int64_t _47_main(void);
int64_t _49_$anon8(int64_t _49_m);


/* Function definitions */
int64_t _47_main(void){
    function0 _47_t0;
    int64_t _47_t2;
    int64_t _47_t1;
    int64_t _47_$retval;
    _47_t0 = (function0) _49_$anon8;
    _47_t2 = 18;
    $lines[$line_idx++] = "tests/integration/generics/named-non-const.orng:12:12:\n    getval(.m = 18, .n = 300)\n          ^";
    _47_t1 = _47_t0(_47_t2);
    $line_idx--;
    _47_$retval = _47_t1;
    return _47_$retval;
}

int64_t _49_$anon8(int64_t _49_m){
    int64_t _49_t5;
    int64_t _49_$retval;
    _49_t5 = 300;
    _49_$retval = $add_int64_t(_49_t5, _49_m, "tests/integration/generics/named-non-const.orng:5:12:\n        n + m\n          ^");
    return _49_$retval;
}


int main(void) {
  printf("%ld",_47_main());
  return 0;
}
