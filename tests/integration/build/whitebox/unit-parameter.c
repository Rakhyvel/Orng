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
int64_t _1930_main(void);
int64_t _1932_f(int64_t _1932_x);


/* Function definitions */
int64_t _1930_main(void){
    function0 _1930_t0;
    int64_t _1930_t3;
    int64_t _1930_t1;
    int64_t _1930_$retval;
    _1930_t0 = (function0) _1932_f;
    _1930_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1930_t1 = _1930_t0(_1930_t3);
    $line_idx--;
    _1930_$retval = _1930_t1;
    return _1930_$retval;
}

int64_t _1932_f(int64_t _1932_x){
    int64_t _1932_$retval;
    _1932_$retval = _1932_x;
    return _1932_$retval;
}


int main(void) {
  printf("%ld",_1930_main());
  return 0;
}
