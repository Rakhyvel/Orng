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
int64_t _1723_main(void);
int64_t _1725_f(int64_t _1725_x);

/* Function definitions */
int64_t _1723_main(void){
    function0 _1723_t0;
    int64_t _1723_t3;
    int64_t _1723_t1;
    int64_t _1723_$retval;
    _1723_t0 = _1725_f;
    _1723_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1723_t1 = _1723_t0(_1723_t3);
    $line_idx--;
    _1723_$retval = _1723_t1;
    return _1723_$retval;
}

int64_t _1725_f(int64_t _1725_x){
    int64_t _1725_$retval;
    _1725_$retval = _1725_x;
    return _1725_$retval;
}

int main(void) {
  printf("%ld",_1723_main());
  return 0;
}
