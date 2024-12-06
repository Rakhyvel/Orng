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
int64_t _2013_main(void);
int64_t _2015_f(int64_t _2015_x);


/* Function definitions */
int64_t _2013_main(void){
    function0 _2013_t0;
    int64_t _2013_t3;
    int64_t _2013_t1;
    int64_t _2013_$retval;
    _2013_t0 = (function0) _2015_f;
    _2013_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _2013_t1 = _2013_t0(_2013_t3);
    $line_idx--;
    _2013_$retval = _2013_t1;
    return _2013_$retval;
}

int64_t _2015_f(int64_t _2015_x){
    int64_t _2015_$retval;
    goto BB2214;
BB2214:
    _2015_$retval = _2015_x;
    return _2015_$retval;
}


int main(void) {
  printf("%ld",_2013_main());
  return 0;
}
