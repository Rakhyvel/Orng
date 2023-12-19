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
int64_t _1916_main(void);
int64_t _1918_f(int64_t _1918_x);

/* Function definitions */
int64_t _1916_main(void){
    function0 _1916_t0;
    int64_t _1916_t3;
    int64_t _1916_t1;
    int64_t _1916_$retval;
    _1916_t0 = _1918_f;
    _1916_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1916_t1 = _1916_t0(_1916_t3);
    $line_idx--;
    _1916_$retval = _1916_t1;
    return _1916_$retval;
}

int64_t _1918_f(int64_t _1918_x){
    int64_t _1918_$retval;
    _1918_$retval = _1918_x;
    return _1918_$retval;
}

int main(void) {
  printf("%ld",_1916_main());
  return 0;
}
