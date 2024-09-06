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
int64_t _1068_main(void);
int64_t _1070_$anon102(int64_t _1070_m);


/* Function definitions */
int64_t _1068_main(void){
    function0 _1068_t0;
    int64_t _1068_t2;
    int64_t _1068_t1;
    int64_t _1068_$retval;
    _1068_t0 = (function0) _1070_$anon102;
    _1068_t2 = 18;
    $lines[$line_idx++] = "tests/integration/generics/named-non-const.orng:12:12:\n    getval(.m = 18, .n = 300)\n          ^";
    _1068_t1 = _1068_t0(_1068_t2);
    $line_idx--;
    _1068_$retval = _1068_t1;
    return _1068_$retval;
}

int64_t _1070_$anon102(int64_t _1070_m){
    int64_t _1070_t5;
    int64_t _1070_$retval;
    goto BB1245;
BB1245:
    _1070_t5 = 300;
    _1070_$retval = $add_int64_t(_1070_t5, _1070_m, "tests/integration/generics/named-non-const.orng:5:12:\n        n + m\n          ^");
    return _1070_$retval;
}


int main(void) {
  printf("%ld",_1068_main());
  return 0;
}
