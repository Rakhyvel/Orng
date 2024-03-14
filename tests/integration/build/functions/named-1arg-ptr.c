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
int64_t _1014_main(void);
int64_t _1016_lol(int64_t _1016_x);


/* Function definitions */
int64_t _1014_main(void){
    function0 _1015_f;
    int64_t _1014_t3;
    int64_t _1014_t2;
    int64_t _1014_$retval;
    _1015_f = (function0) _1016_lol;
    _1014_t3 = 309;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg-ptr.orng:5:7:\n    f(.x = 309)\n     ^";
    _1014_t2 = _1015_f(_1014_t3);
    $line_idx--;
    _1014_$retval = _1014_t2;
    return _1014_$retval;
}

int64_t _1016_lol(int64_t _1016_x){
    int64_t _1016_$retval;
    _1016_$retval = _1016_x;
    return _1016_$retval;
}


int main(void) {
  printf("%ld",_1014_main());
  return 0;
}
