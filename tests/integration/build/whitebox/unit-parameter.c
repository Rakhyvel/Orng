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
int64_t _1751_main(void);
int64_t _1753_f(int64_t _1753_x);


/* Function definitions */
int64_t _1751_main(void){
    function0 _1751_t0;
    int64_t _1751_t3;
    int64_t _1751_t1;
    int64_t _1751_$retval;
    _1751_t0 = _1753_f;
    _1751_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1751_t1 = _1751_t0(_1751_t3);
    $line_idx--;
    _1751_$retval = _1751_t1;
    return _1751_$retval;
}

int64_t _1753_f(int64_t _1753_x){
    int64_t _1753_$retval;
    _1753_$retval = _1753_x;
    return _1753_$retval;
}


int main(void) {
  printf("%ld",_1751_main());
  return 0;
}
