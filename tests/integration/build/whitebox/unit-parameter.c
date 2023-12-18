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
int64_t _1909_main(void);
int64_t _1911_f(int64_t _1911_x);

/* Function definitions */
int64_t _1909_main(void){
    function0 _1909_t0;
    int64_t _1909_t3;
    int64_t _1909_t1;
    int64_t _1909_$retval;
    _1909_t0 = _1911_f;
    _1909_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1909_t1 = _1909_t0(_1909_t3);
    $line_idx--;
    _1909_$retval = _1909_t1;
    return _1909_$retval;
}

int64_t _1911_f(int64_t _1911_x){
    int64_t _1911_$retval;
    _1911_$retval = _1911_x;
    return _1911_$retval;
}

int main(void) {
  printf("%ld",_1909_main());
  return 0;
}
