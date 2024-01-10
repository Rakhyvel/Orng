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
int64_t _1652_main(void);
int64_t _1654_f(int64_t _1654_x);

/* Function definitions */
int64_t _1652_main(void){
    function0 _1652_t0;
    int64_t _1652_t3;
    int64_t _1652_t1;
    int64_t _1652_$retval;
    _1652_t0 = _1654_f;
    _1652_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1652_t1 = _1652_t0(_1652_t3);
    $line_idx--;
    _1652_$retval = _1652_t1;
    return _1652_$retval;
}

int64_t _1654_f(int64_t _1654_x){
    int64_t _1654_$retval;
    _1654_$retval = _1654_x;
    return _1654_$retval;
}

int main(void) {
  printf("%ld",_1652_main());
  return 0;
}
