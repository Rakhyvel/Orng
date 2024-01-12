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
int64_t _1662_main(void);
int64_t _1664_f(int64_t _1664_x);

/* Function definitions */
int64_t _1662_main(void){
    function0 _1662_t0;
    int64_t _1662_t3;
    int64_t _1662_t1;
    int64_t _1662_$retval;
    _1662_t0 = _1664_f;
    _1662_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1662_t1 = _1662_t0(_1662_t3);
    $line_idx--;
    _1662_$retval = _1662_t1;
    return _1662_$retval;
}

int64_t _1664_f(int64_t _1664_x){
    int64_t _1664_$retval;
    _1664_$retval = _1664_x;
    return _1664_$retval;
}

int main(void) {
  printf("%ld",_1662_main());
  return 0;
}
