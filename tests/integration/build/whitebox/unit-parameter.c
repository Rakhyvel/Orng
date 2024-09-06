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
int64_t _1996_main(void);
int64_t _1998_f(int64_t _1998_x);


/* Function definitions */
int64_t _1996_main(void){
    function0 _1996_t0;
    int64_t _1996_t3;
    int64_t _1996_t1;
    int64_t _1996_$retval;
    _1996_t0 = (function0) _1998_f;
    _1996_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1996_t1 = _1996_t0(_1996_t3);
    $line_idx--;
    _1996_$retval = _1996_t1;
    return _1996_$retval;
}

int64_t _1998_f(int64_t _1998_x){
    int64_t _1998_$retval;
    goto BB2198;
BB2198:
    _1998_$retval = _1998_x;
    return _1998_$retval;
}


int main(void) {
  printf("%ld",_1996_main());
  return 0;
}
