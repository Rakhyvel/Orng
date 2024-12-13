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
int64_t _1104_main(void);
int64_t _1106_$anon108(int64_t _1106_m);


/* Function definitions */
int64_t _1104_main(void){
    function0 _1104_t0;
    int64_t _1104_t2;
    int64_t _1104_t1;
    int64_t _1104_$retval;
    _1104_t0 = (function0) _1106_$anon108;
    _1104_t2 = 18;
    $lines[$line_idx++] = "tests/integration/generics/named-non-const.orng:12:12:\n    getval(.m = 18, .n = 300)\n          ^";
    _1104_t1 = _1104_t0(_1104_t2);
    $line_idx--;
    _1104_$retval = _1104_t1;
    return _1104_$retval;
}

int64_t _1106_$anon108(int64_t _1106_m){
    int64_t _1106_t5;
    int64_t _1106_$retval;
    goto BB1285;
BB1285:
    _1106_t5 = 300;
    _1106_$retval = $add_int64_t(_1106_t5, _1106_m, "tests/integration/generics/named-non-const.orng:5:12:\n        n + m\n          ^");
    return _1106_$retval;
}


int main(void) {
  printf("%ld",_1104_main());
  return 0;
}
