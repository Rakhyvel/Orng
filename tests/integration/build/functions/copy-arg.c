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
int64_t _969_main(void);
int64_t _971_g(int64_t _971_x);
int64_t _973_f(int64_t _973_x);


/* Function definitions */
int64_t _969_main(void){
    function0 _969_t0;
    int64_t _969_t2;
    int64_t _969_t1;
    int64_t _969_$retval;
    _969_t0 = (function0) _971_g;
    _969_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _969_t1 = _969_t0(_969_t2);
    $line_idx--;
    _969_$retval = _969_t1;
    return _969_$retval;
}

int64_t _971_g(int64_t _971_x){
    int64_t _972_z;
    function0 _971_t1;
    int64_t _971_t2;
    int64_t _971_$retval;
    _972_z = _971_x;
    _971_t1 = (function0) _973_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _971_t2 = _971_t1(_972_z);
    $line_idx--;
    _971_$retval = _971_t2;
    return _971_$retval;
}

int64_t _973_f(int64_t _973_x){
    int64_t _973_$retval;
    _973_$retval = _973_x;
    return _973_$retval;
}


int main(void) {
  printf("%ld",_969_main());
  return 0;
}
