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
int64_t _36_main(void);
int64_t _38_lol(int64_t _38_x);


/* Function definitions */
int64_t _36_main(void){
    function0 _37_f;
    int64_t _36_t3;
    int64_t _36_t2;
    int64_t _36_$retval;
    _37_f = (function0) _38_lol;
    _36_t3 = 4;
    $lines[$line_idx++] = "tests/integration/functions/expect-annot.orng:3:7:\n    f(.x = 4)\n     ^";
    _36_t2 = _37_f(_36_t3);
    $line_idx--;
    _36_$retval = _36_t2;
    return _36_$retval;
}

int64_t _38_lol(int64_t _38_x){
    int64_t _38_$retval;
    _38_$retval = _38_x;
    return _38_$retval;
}


int main(void) {
  printf("%ld",_36_main());
  return 0;
}
