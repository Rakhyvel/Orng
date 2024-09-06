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
int64_t _1986_main(void);
int64_t _1988_f(int64_t _1988_x);


/* Function definitions */
int64_t _1986_main(void){
    function0 _1986_t0;
    int64_t _1986_t3;
    int64_t _1986_t1;
    int64_t _1986_$retval;
    _1986_t0 = (function0) _1988_f;
    _1986_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1986_t1 = _1986_t0(_1986_t3);
    $line_idx--;
    _1986_$retval = _1986_t1;
    return _1986_$retval;
}

int64_t _1988_f(int64_t _1988_x){
    int64_t _1988_$retval;
    goto BB2194;
BB2194:
    _1988_$retval = _1988_x;
    return _1988_$retval;
}


int main(void) {
  printf("%ld",_1986_main());
  return 0;
}
