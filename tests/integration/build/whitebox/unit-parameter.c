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
int64_t _1819_main(void);
int64_t _1821_f(int64_t _1821_x);


/* Function definitions */
int64_t _1819_main(void){
    function0 _1819_t0;
    int64_t _1819_t3;
    int64_t _1819_t1;
    int64_t _1819_$retval;
    _1819_t0 = (function0) _1821_f;
    _1819_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1819_t1 = _1819_t0(_1819_t3);
    $line_idx--;
    _1819_$retval = _1819_t1;
    return _1819_$retval;
}

int64_t _1821_f(int64_t _1821_x){
    int64_t _1821_$retval;
    _1821_$retval = _1821_x;
    return _1821_$retval;
}


int main(void) {
  printf("%ld",_1819_main());
  return 0;
}
