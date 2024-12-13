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
int64_t _978_main(void);
int64_t _980_return53(int64_t _980_x);


/* Function definitions */
int64_t _978_main(void){
    function0 _978_t0;
    int64_t _978_t2;
    int64_t _978_t1;
    int64_t _978_$retval;
    _978_t0 = (function0) _980_return53;
    _978_t2 = 53;
    $lines[$line_idx++] = "tests/integration/functions/default-1arg.orng:3:14:\n    return53()\n            ^";
    _978_t1 = _978_t0(_978_t2);
    $line_idx--;
    _978_$retval = _978_t1;
    return _978_$retval;
}

int64_t _980_return53(int64_t _980_x){
    int64_t _980_$retval;
    goto BB1157;
BB1157:
    _980_$retval = _980_x;
    return _980_$retval;
}


int main(void) {
  printf("%ld",_978_main());
  return 0;
}
