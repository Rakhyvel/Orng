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
int64_t _1087_main(void);
int64_t _1089_$anon105(int64_t _1089_m);


/* Function definitions */
int64_t _1087_main(void){
    function0 _1087_t0;
    int64_t _1087_t2;
    int64_t _1087_t1;
    int64_t _1087_$retval;
    _1087_t0 = (function0) _1089_$anon105;
    _1087_t2 = 18;
    $lines[$line_idx++] = "tests/integration/generics/named-non-const.orng:12:12:\n    getval(.m = 18, .n = 300)\n          ^";
    _1087_t1 = _1087_t0(_1087_t2);
    $line_idx--;
    _1087_$retval = _1087_t1;
    return _1087_$retval;
}

int64_t _1089_$anon105(int64_t _1089_m){
    int64_t _1089_t5;
    int64_t _1089_$retval;
    goto BB1267;
BB1267:
    _1089_t5 = 300;
    _1089_$retval = $add_int64_t(_1089_t5, _1089_m, "tests/integration/generics/named-non-const.orng:5:12:\n        n + m\n          ^");
    return _1089_$retval;
}


int main(void) {
  printf("%ld",_1087_main());
  return 0;
}
