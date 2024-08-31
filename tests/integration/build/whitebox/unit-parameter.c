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
int64_t _1891_main(void);
int64_t _1893_f(int64_t _1893_x);


/* Function definitions */
int64_t _1891_main(void){
    function0 _1891_t0;
    int64_t _1891_t3;
    int64_t _1891_t1;
    int64_t _1891_$retval;
    _1891_t0 = (function0) _1893_f;
    _1891_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1891_t1 = _1891_t0(_1891_t3);
    $line_idx--;
    _1891_$retval = _1891_t1;
    return _1891_$retval;
}

int64_t _1893_f(int64_t _1893_x){
    int64_t _1893_$retval;
    _1893_$retval = _1893_x;
    return _1893_$retval;
}


int main(void) {
  printf("%ld",_1891_main());
  return 0;
}
