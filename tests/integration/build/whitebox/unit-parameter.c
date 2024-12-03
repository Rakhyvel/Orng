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
int64_t _2001_main(void);
int64_t _2003_f(int64_t _2003_x);


/* Function definitions */
int64_t _2001_main(void){
    function0 _2001_t0;
    int64_t _2001_t3;
    int64_t _2001_t1;
    int64_t _2001_$retval;
    _2001_t0 = (function0) _2003_f;
    _2001_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _2001_t1 = _2001_t0(_2001_t3);
    $line_idx--;
    _2001_$retval = _2001_t1;
    return _2001_$retval;
}

int64_t _2003_f(int64_t _2003_x){
    int64_t _2003_$retval;
    goto BB2202;
BB2202:
    _2003_$retval = _2003_x;
    return _2003_$retval;
}


int main(void) {
  printf("%ld",_2001_main());
  return 0;
}
