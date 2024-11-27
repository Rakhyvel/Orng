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
int64_t _53_main(void);
int64_t _55_$anon9(int64_t _55_m);


/* Function definitions */
int64_t _53_main(void){
    function0 _53_t0;
    int64_t _53_t2;
    int64_t _53_t1;
    int64_t _53_$retval;
    _53_t0 = (function0) _55_$anon9;
    _53_t2 = 18;
    $lines[$line_idx++] = "tests/integration/generics/named-non-const.orng:12:12:\n    getval(.m = 18, .n = 300)\n          ^";
    _53_t1 = _53_t0(_53_t2);
    $line_idx--;
    _53_$retval = _53_t1;
    return _53_$retval;
}

int64_t _55_$anon9(int64_t _55_m){
    int64_t _55_t5;
    int64_t _55_$retval;
    goto BB55;
BB55:
    _55_t5 = 300;
    _55_$retval = $add_int64_t(_55_t5, _55_m, "tests/integration/generics/named-non-const.orng:5:12:\n        n + m\n          ^");
    return _55_$retval;
}


int main(void) {
  printf("%ld",_53_main());
  return 0;
}
