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
int64_t _1961_main(void);
int64_t _1963_f(int64_t _1963_x);


/* Function definitions */
int64_t _1961_main(void){
    function0 _1961_t0;
    int64_t _1961_t3;
    int64_t _1961_t1;
    int64_t _1961_$retval;
    _1961_t0 = (function0) _1963_f;
    _1961_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1961_t1 = _1961_t0(_1961_t3);
    $line_idx--;
    _1961_$retval = _1961_t1;
    return _1961_$retval;
}

int64_t _1963_f(int64_t _1963_x){
    int64_t _1963_$retval;
    goto BB2194;
BB2194:
    _1963_$retval = _1963_x;
    return _1963_$retval;
}


int main(void) {
  printf("%ld",_1961_main());
  return 0;
}
