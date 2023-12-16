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
int64_t _1663_main(void);
int64_t _1665_f(int64_t _1665_x);

/* Function definitions */
int64_t _1663_main(void){
    function0 _1663_t0;
    int64_t _1663_t3;
    int64_t _1663_t1;
    int64_t _1663_$retval;
    _1663_t0 = _1665_f;
    _1663_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1663_t1 = _1663_t0(_1663_t3);
    $line_idx--;
    _1663_$retval = _1663_t1;
    return _1663_$retval;
}

int64_t _1665_f(int64_t _1665_x){
    int64_t _1665_$retval;
    _1665_$retval = _1665_x;
    return _1665_$retval;
}

int main(void) {
  printf("%ld",_1663_main());
  return 0;
}
