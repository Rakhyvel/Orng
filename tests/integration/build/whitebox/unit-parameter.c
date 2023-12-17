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
int64_t _1808_main(void);
int64_t _1810_f(int64_t _1810_x);

/* Function definitions */
int64_t _1808_main(void){
    function0 _1808_t0;
    int64_t _1808_t3;
    int64_t _1808_t1;
    int64_t _1808_$retval;
    _1808_t0 = _1810_f;
    _1808_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1808_t1 = _1808_t0(_1808_t3);
    $line_idx--;
    _1808_$retval = _1808_t1;
    return _1808_$retval;
}

int64_t _1810_f(int64_t _1810_x){
    int64_t _1810_$retval;
    _1810_$retval = _1810_x;
    return _1810_$retval;
}

int main(void) {
  printf("%ld",_1808_main());
  return 0;
}
