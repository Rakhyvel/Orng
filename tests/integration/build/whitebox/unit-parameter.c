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
int64_t _1617_main(void);
int64_t _1619_f(int64_t _1619_x);

/* Function definitions */
int64_t _1617_main(void){
    function0 _1617_t0;
    int64_t _1617_t3;
    int64_t _1617_t1;
    int64_t _1617_$retval;
    _1617_t0 = _1619_f;
    _1617_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1617_t1 = _1617_t0(_1617_t3);
    $line_idx--;
    _1617_$retval = _1617_t1;
    return _1617_$retval;
}

int64_t _1619_f(int64_t _1619_x){
    int64_t _1619_$retval;
    _1619_$retval = _1619_x;
    return _1619_$retval;
}

int main(void) {
  printf("%ld",_1617_main());
  return 0;
}
