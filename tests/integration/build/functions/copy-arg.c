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
int64_t _949_main(void);
int64_t _951_g(int64_t _951_x);
int64_t _953_f(int64_t _953_x);


/* Function definitions */
int64_t _949_main(void){
    function0 _949_t0;
    int64_t _949_t2;
    int64_t _949_t1;
    int64_t _949_$retval;
    _949_t0 = (function0) _951_g;
    _949_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _949_t1 = _949_t0(_949_t2);
    $line_idx--;
    _949_$retval = _949_t1;
    return _949_$retval;
}

int64_t _951_g(int64_t _951_x){
    int64_t _952_z;
    function0 _951_t1;
    int64_t _951_t2;
    int64_t _951_$retval;
    _952_z = _951_x;
    _951_t1 = (function0) _953_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _951_t2 = _951_t1(_952_z);
    $line_idx--;
    _951_$retval = _951_t2;
    return _951_$retval;
}

int64_t _953_f(int64_t _953_x){
    int64_t _953_$retval;
    goto BB1130;
BB1130:
    _953_$retval = _953_x;
    return _953_$retval;
}


int main(void) {
  printf("%ld",_949_main());
  return 0;
}
