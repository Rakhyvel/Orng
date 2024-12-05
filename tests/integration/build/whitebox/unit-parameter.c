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
int64_t _2007_main(void);
int64_t _2009_f(int64_t _2009_x);


/* Function definitions */
int64_t _2007_main(void){
    function0 _2007_t0;
    int64_t _2007_t3;
    int64_t _2007_t1;
    int64_t _2007_$retval;
    _2007_t0 = (function0) _2009_f;
    _2007_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _2007_t1 = _2007_t0(_2007_t3);
    $line_idx--;
    _2007_$retval = _2007_t1;
    return _2007_$retval;
}

int64_t _2009_f(int64_t _2009_x){
    int64_t _2009_$retval;
    goto BB2205;
BB2205:
    _2009_$retval = _2009_x;
    return _2009_$retval;
}


int main(void) {
  printf("%ld",_2007_main());
  return 0;
}
