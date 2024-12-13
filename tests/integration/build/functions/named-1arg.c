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
int64_t _1016_main(void);
int64_t _1018_id(int64_t _1018_x);


/* Function definitions */
int64_t _1016_main(void){
    function0 _1016_t0;
    int64_t _1016_t2;
    int64_t _1016_t1;
    int64_t _1016_$retval;
    _1016_t0 = (function0) _1018_id;
    _1016_t2 = 52;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    _1016_t1 = _1016_t0(_1016_t2);
    $line_idx--;
    _1016_$retval = _1016_t1;
    return _1016_$retval;
}

int64_t _1018_id(int64_t _1018_x){
    int64_t _1018_$retval;
    goto BB1195;
BB1195:
    _1018_$retval = _1018_x;
    return _1018_$retval;
}


int main(void) {
  printf("%ld",_1016_main());
  return 0;
}
