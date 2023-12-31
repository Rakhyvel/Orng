/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    int64_t _1;
};

typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1647_main(void);
int64_t _1649_f(int64_t _1649_x);

/* Function definitions */
int64_t _1647_main(void){
    function0 _1647_t0;
    int64_t _1647_t3;
    int64_t _1647_t1;
    int64_t _1647_$retval;
    _1647_t0 = _1649_f;
    _1647_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1647_t1 = _1647_t0(_1647_t3);
    $line_idx--;
    _1647_$retval = _1647_t1;
    return _1647_$retval;
}

int64_t _1649_f(int64_t _1649_x){
    int64_t _1649_$retval;
    _1649_$retval = _1649_x;
    return _1649_$retval;
}

int main(void) {
  printf("%ld",_1647_main());
  return 0;
}
