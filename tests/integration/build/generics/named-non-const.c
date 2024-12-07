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
int64_t _1082_main(void);
int64_t _1084_$anon103(int64_t _1084_m);


/* Function definitions */
int64_t _1082_main(void){
    function0 _1082_t0;
    int64_t _1082_t2;
    int64_t _1082_t1;
    int64_t _1082_$retval;
    _1082_t0 = (function0) _1084_$anon103;
    _1082_t2 = 18;
    $lines[$line_idx++] = "tests/integration/generics/named-non-const.orng:12:12:\n    getval(.m = 18, .n = 300)\n          ^";
    _1082_t1 = _1082_t0(_1082_t2);
    $line_idx--;
    _1082_$retval = _1082_t1;
    return _1082_$retval;
}

int64_t _1084_$anon103(int64_t _1084_m){
    int64_t _1084_t5;
    int64_t _1084_$retval;
    goto BB1264;
BB1264:
    _1084_t5 = 300;
    _1084_$retval = $add_int64_t(_1084_t5, _1084_m, "tests/integration/generics/named-non-const.orng:5:12:\n        n + m\n          ^");
    return _1084_$retval;
}


int main(void) {
  printf("%ld",_1082_main());
  return 0;
}
