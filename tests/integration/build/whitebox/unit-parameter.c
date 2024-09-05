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
int64_t _1941_main(void);
int64_t _1943_f(int64_t _1943_x);


/* Function definitions */
int64_t _1941_main(void){
    function0 _1941_t0;
    int64_t _1941_t3;
    int64_t _1941_t1;
    int64_t _1941_$retval;
    _1941_t0 = (function0) _1943_f;
    _1941_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1941_t1 = _1941_t0(_1941_t3);
    $line_idx--;
    _1941_$retval = _1941_t1;
    return _1941_$retval;
}

int64_t _1943_f(int64_t _1943_x){
    int64_t _1943_$retval;
    _1943_$retval = _1943_x;
    return _1943_$retval;
}


int main(void) {
  printf("%ld",_1941_main());
  return 0;
}
