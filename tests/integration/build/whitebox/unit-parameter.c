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
int64_t _1886_main(void);
int64_t _1888_f(int64_t _1888_x);


/* Function definitions */
int64_t _1886_main(void){
    function0 _1886_t0;
    int64_t _1886_t3;
    int64_t _1886_t1;
    int64_t _1886_$retval;
    _1886_t0 = (function0) _1888_f;
    _1886_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1886_t1 = _1886_t0(_1886_t3);
    $line_idx--;
    _1886_$retval = _1886_t1;
    return _1886_$retval;
}

int64_t _1888_f(int64_t _1888_x){
    int64_t _1888_$retval;
    _1888_$retval = _1888_x;
    return _1888_$retval;
}


int main(void) {
  printf("%ld",_1886_main());
  return 0;
}
