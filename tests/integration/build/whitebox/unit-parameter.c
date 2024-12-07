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
int64_t _2021_main(void);
int64_t _2023_f(int64_t _2023_x);


/* Function definitions */
int64_t _2021_main(void){
    function0 _2021_t0;
    int64_t _2021_t3;
    int64_t _2021_t1;
    int64_t _2021_$retval;
    _2021_t0 = (function0) _2023_f;
    _2021_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _2021_t1 = _2021_t0(_2021_t3);
    $line_idx--;
    _2021_$retval = _2021_t1;
    return _2021_$retval;
}

int64_t _2023_f(int64_t _2023_x){
    int64_t _2023_$retval;
    goto BB2224;
BB2224:
    _2023_$retval = _2023_x;
    return _2023_$retval;
}


int main(void) {
  printf("%ld",_2021_main());
  return 0;
}
