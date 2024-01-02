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
int64_t _1650_main(void);
int64_t _1652_f(int64_t _1652_x);

/* Function definitions */
int64_t _1650_main(void){
    function0 _1650_t0;
    int64_t _1650_t3;
    int64_t _1650_t1;
    int64_t _1650_$retval;
    _1650_t0 = _1652_f;
    _1650_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1650_t1 = _1650_t0(_1650_t3);
    $line_idx--;
    _1650_$retval = _1650_t1;
    return _1650_$retval;
}

int64_t _1652_f(int64_t _1652_x){
    int64_t _1652_$retval;
    _1652_$retval = _1652_x;
    return _1652_$retval;
}

int main(void) {
  printf("%ld",_1650_main());
  return 0;
}
