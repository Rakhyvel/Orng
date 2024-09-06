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
int64_t _988_main(void);
int64_t _990_id(int64_t _990_x);


/* Function definitions */
int64_t _988_main(void){
    function0 _988_t0;
    int64_t _988_t2;
    int64_t _988_t1;
    int64_t _988_$retval;
    _988_t0 = (function0) _990_id;
    _988_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _988_t1 = _988_t0(_988_t2);
    $line_idx--;
    _988_$retval = _988_t1;
    return _988_$retval;
}

int64_t _990_id(int64_t _990_x){
    int64_t _990_$retval;
    goto BB1161;
BB1161:
    _990_$retval = _990_x;
    return _990_$retval;
}


int main(void) {
  printf("%ld",_988_main());
  return 0;
}
