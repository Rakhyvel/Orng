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
int64_t _2041_main(void);
int64_t _2043_f(int64_t _2043_x);


/* Function definitions */
int64_t _2041_main(void){
    function0 _2041_t0;
    int64_t _2041_t3;
    int64_t _2041_t1;
    int64_t _2041_$retval;
    _2041_t0 = (function0) _2043_f;
    _2041_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _2041_t1 = _2041_t0(_2041_t3);
    $line_idx--;
    _2041_$retval = _2041_t1;
    return _2041_$retval;
}

int64_t _2043_f(int64_t _2043_x){
    int64_t _2043_$retval;
    goto BB2243;
BB2243:
    _2043_$retval = _2043_x;
    return _2043_$retval;
}


int main(void) {
  printf("%ld",_2041_main());
  return 0;
}
