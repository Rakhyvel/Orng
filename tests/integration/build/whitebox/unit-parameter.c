/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
        int64_t _1;
} struct1;

typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1642_main(void);
int64_t _1644_f(int64_t _1644_x);

/* Function definitions */
int64_t _1642_main(void){
    function0 _1642_t0;
    int64_t _1642_t3;
    int64_t _1642_t1;
    int64_t _1642_$retval;
    _1642_t0 = _1644_f;
    _1642_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1642_t1 = _1642_t0(_1642_t3);
    $line_idx--;
    _1642_$retval = _1642_t1;
    return _1642_$retval;
}

int64_t _1644_f(int64_t _1644_x){
    int64_t _1644_$retval;
    _1644_$retval = _1644_x;
    return _1644_$retval;
}

int main(void) {
  printf("%ld",_1642_main());
  return 0;
}
