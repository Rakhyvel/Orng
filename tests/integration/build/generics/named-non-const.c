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
int64_t _1063_main(void);
int64_t _1065_$anon102(int64_t _1065_m);


/* Function definitions */
int64_t _1063_main(void){
    function0 _1063_t0;
    int64_t _1063_t2;
    int64_t _1063_t1;
    int64_t _1063_$retval;
    _1063_t0 = (function0) _1065_$anon102;
    _1063_t2 = 18;
    $lines[$line_idx++] = "tests/integration/generics/named-non-const.orng:12:12:\n    getval(.m = 18, .n = 300)\n          ^";
    _1063_t1 = _1063_t0(_1063_t2);
    $line_idx--;
    _1063_$retval = _1063_t1;
    return _1063_$retval;
}

int64_t _1065_$anon102(int64_t _1065_m){
    int64_t _1065_t5;
    int64_t _1065_$retval;
    goto BB1241;
BB1241:
    _1065_t5 = 300;
    _1065_$retval = $add_int64_t(_1065_t5, _1065_m, "tests/integration/generics/named-non-const.orng:5:12:\n        n + m\n          ^");
    return _1065_$retval;
}


int main(void) {
  printf("%ld",_1063_main());
  return 0;
}
