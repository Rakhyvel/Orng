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
int64_t _1897_main(void);
int64_t _1899_f(int64_t _1899_x);

/* Function definitions */
int64_t _1897_main(void){
    function0 _1897_t0;
    int64_t _1897_t3;
    int64_t _1897_t1;
    int64_t _1897_$retval;
    _1897_t0 = _1899_f;
    _1897_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1897_t1 = _1897_t0(_1897_t3);
    $line_idx--;
    _1897_$retval = _1897_t1;
    return _1897_$retval;
}

int64_t _1899_f(int64_t _1899_x){
    int64_t _1899_$retval;
    _1899_$retval = _1899_x;
    return _1899_$retval;
}

int main(void) {
  printf("%ld",_1897_main());
  return 0;
}
