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
int64_t _2026_main(void);
int64_t _2028_f(int64_t _2028_x);


/* Function definitions */
int64_t _2026_main(void){
    function0 _2026_t0;
    int64_t _2026_t3;
    int64_t _2026_t1;
    int64_t _2026_$retval;
    _2026_t0 = (function0) _2028_f;
    _2026_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _2026_t1 = _2026_t0(_2026_t3);
    $line_idx--;
    _2026_$retval = _2026_t1;
    return _2026_$retval;
}

int64_t _2028_f(int64_t _2028_x){
    int64_t _2028_$retval;
    goto BB2227;
BB2227:
    _2028_$retval = _2028_x;
    return _2028_$retval;
}


int main(void) {
  printf("%ld",_2026_main());
  return 0;
}
