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
int64_t _1655_main(void);
int64_t _1657_f(int64_t _1657_x);

/* Function definitions */
int64_t _1655_main(void){
    function0 _1655_t0;
    int64_t _1655_t3;
    int64_t _1655_t1;
    int64_t _1655_$retval;
    _1655_t0 = _1657_f;
    _1655_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1655_t1 = _1655_t0(_1655_t3);
    $line_idx--;
    _1655_$retval = _1655_t1;
    return _1655_$retval;
}

int64_t _1657_f(int64_t _1657_x){
    int64_t _1657_$retval;
    _1657_$retval = _1657_x;
    return _1657_$retval;
}

int main(void) {
  printf("%ld",_1655_main());
  return 0;
}
