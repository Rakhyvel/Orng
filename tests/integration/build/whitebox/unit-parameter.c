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
int64_t _1954_main(void);
int64_t _1956_f(int64_t _1956_x);


/* Function definitions */
int64_t _1954_main(void){
    function0 _1954_t0;
    int64_t _1954_t3;
    int64_t _1954_t1;
    int64_t _1954_$retval;
    _1954_t0 = (function0) _1956_f;
    _1954_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1954_t1 = _1954_t0(_1954_t3);
    $line_idx--;
    _1954_$retval = _1954_t1;
    return _1954_$retval;
}

int64_t _1956_f(int64_t _1956_x){
    int64_t _1956_$retval;
    goto BB2186;
BB2186:
    _1956_$retval = _1956_x;
    return _1956_$retval;
}


int main(void) {
  printf("%ld",_1954_main());
  return 0;
}
