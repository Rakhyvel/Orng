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
int64_t _1680_main(void);
int64_t _1682_f(int64_t _1682_x);

/* Function definitions */
int64_t _1680_main(void){
    function0 _1680_t0;
    int64_t _1680_t3;
    int64_t _1680_t1;
    int64_t _1680_$retval;
    _1680_t0 = _1682_f;
    _1680_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1680_t1 = _1680_t0(_1680_t3);
    $line_idx--;
    _1680_$retval = _1680_t1;
    return _1680_$retval;
}

int64_t _1682_f(int64_t _1682_x){
    int64_t _1682_$retval;
    _1682_$retval = _1682_x;
    return _1682_$retval;
}

int main(void) {
  printf("%ld",_1680_main());
  return 0;
}
