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
int64_t _1069_main(void);
int64_t _1071_$anon101(int64_t _1071_m);


/* Function definitions */
int64_t _1069_main(void){
    function0 _1069_t0;
    int64_t _1069_t2;
    int64_t _1069_t1;
    int64_t _1069_$retval;
    _1069_t0 = (function0) _1071_$anon101;
    _1069_t2 = 300;
    $lines[$line_idx++] = "tests/integration/generics/default-non-const.orng:8:12:\n    getval(16)\n          ^";
    _1069_t1 = _1069_t0(_1069_t2);
    $line_idx--;
    _1069_$retval = _1069_t1;
    return _1069_$retval;
}

int64_t _1071_$anon101(int64_t _1071_m){
    int64_t _1071_t0;
    int64_t _1071_$retval;
    _1071_t0 = 16;
    _1071_$retval = $add_int64_t(_1071_t0, _1071_m, "tests/integration/generics/default-non-const.orng:4:8:\n    n + m\n      ^");
    return _1071_$retval;
}


int main(void) {
  printf("%ld",_1069_main());
  return 0;
}
