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
int64_t _2043_main(void);
int64_t _2045_f(int64_t _2045_x);


/* Function definitions */
int64_t _2043_main(void){
    function0 _2043_t0;
    int64_t _2043_t3;
    int64_t _2043_t1;
    int64_t _2043_$retval;
    _2043_t0 = (function0) _2045_f;
    _2043_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _2043_t1 = _2043_t0(_2043_t3);
    $line_idx--;
    _2043_$retval = _2043_t1;
    return _2043_$retval;
}

int64_t _2045_f(int64_t _2045_x){
    int64_t _2045_$retval;
    goto BB2245;
BB2245:
    _2045_$retval = _2045_x;
    return _2045_$retval;
}


int main(void) {
  printf("%ld",_2043_main());
  return 0;
}
