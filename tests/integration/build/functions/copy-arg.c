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
int64_t _941_main(void);
int64_t _943_g(int64_t _943_x);
int64_t _945_f(int64_t _945_x);


/* Function definitions */
int64_t _941_main(void){
    function0 _941_t0;
    int64_t _941_t2;
    int64_t _941_t1;
    int64_t _941_$retval;
    _941_t0 = (function0) _943_g;
    _941_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _941_t1 = _941_t0(_941_t2);
    $line_idx--;
    _941_$retval = _941_t1;
    return _941_$retval;
}

int64_t _943_g(int64_t _943_x){
    int64_t _944_z;
    function0 _943_t1;
    int64_t _943_t2;
    int64_t _943_$retval;
    _944_z = _943_x;
    _943_t1 = (function0) _945_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _943_t2 = _943_t1(_944_z);
    $line_idx--;
    _943_$retval = _943_t2;
    return _943_$retval;
}

int64_t _945_f(int64_t _945_x){
    int64_t _945_$retval;
    goto BB1120;
BB1120:
    _945_$retval = _945_x;
    return _945_$retval;
}


int main(void) {
  printf("%ld",_941_main());
  return 0;
}
