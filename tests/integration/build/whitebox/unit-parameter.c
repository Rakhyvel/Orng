/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _1;
};

typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1991_main(void);
int64_t _1993_f(int64_t _1993_x);


/* Function definitions */
int64_t _1991_main(void){
    function0 _1991_t0;
    int64_t _1991_t3;
    int64_t _1991_t1;
    int64_t _1991_$retval;
    _1991_t0 = (function0) _1993_f;
    _1991_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1991_t1 = _1991_t0(_1991_t3);
    $line_idx--;
    _1991_$retval = _1991_t1;
    return _1991_$retval;
}

int64_t _1993_f(int64_t _1993_x){
    int64_t _1993_$retval;
    goto BB2194;
BB2194:
    _1993_$retval = _1993_x;
    return _1993_$retval;
}


int main(void) {
  printf("%ld",_1991_main());
  return 0;
}
