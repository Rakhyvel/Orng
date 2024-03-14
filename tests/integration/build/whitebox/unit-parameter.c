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
int64_t _1875_main(void);
int64_t _1877_f(int64_t _1877_x);


/* Function definitions */
int64_t _1875_main(void){
    function0 _1875_t0;
    int64_t _1875_t3;
    int64_t _1875_t1;
    int64_t _1875_$retval;
    _1875_t0 = (function0) _1877_f;
    _1875_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1875_t1 = _1875_t0(_1875_t3);
    $line_idx--;
    _1875_$retval = _1875_t1;
    return _1875_$retval;
}

int64_t _1877_f(int64_t _1877_x){
    int64_t _1877_$retval;
    _1877_$retval = _1877_x;
    return _1877_$retval;
}


int main(void) {
  printf("%ld",_1875_main());
  return 0;
}
