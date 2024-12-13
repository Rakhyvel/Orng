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
int64_t _971_main(void);
int64_t _973_g(int64_t _973_x);
int64_t _975_f(int64_t _975_x);


/* Function definitions */
int64_t _971_main(void){
    function0 _971_t0;
    int64_t _971_t2;
    int64_t _971_t1;
    int64_t _971_$retval;
    _971_t0 = (function0) _973_g;
    _971_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _971_t1 = _971_t0(_971_t2);
    $line_idx--;
    _971_$retval = _971_t1;
    return _971_$retval;
}

int64_t _973_g(int64_t _973_x){
    int64_t _974_z;
    function0 _973_t1;
    int64_t _973_t2;
    int64_t _973_$retval;
    _974_z = _973_x;
    _973_t1 = (function0) _975_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _973_t2 = _973_t1(_974_z);
    $line_idx--;
    _973_$retval = _973_t2;
    return _973_$retval;
}

int64_t _975_f(int64_t _975_x){
    int64_t _975_$retval;
    goto BB1151;
BB1151:
    _975_$retval = _975_x;
    return _975_$retval;
}


int main(void) {
  printf("%ld",_971_main());
  return 0;
}
