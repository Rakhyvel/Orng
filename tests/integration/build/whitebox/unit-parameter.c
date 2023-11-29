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
int64_t _1713_main(void);
int64_t _1716_f(int64_t _1716_x);

/* Function definitions */
int64_t _1713_main(void) {
    function0 _1713_t0;
    int64_t _1713_t2;
    int64_t _1713_t1;
    int64_t _1713_$retval;
    _1713_t0 = _1716_f;
    _1713_t2 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1713_t1 = _1713_t0(_1713_t2);
    $line_idx--;
    _1713_$retval = _1713_t1;
    return _1713_$retval;
}

int64_t _1716_f(int64_t _1716_x) {
    int64_t _1716_$retval;
    _1716_$retval = _1716_x;
    return _1716_$retval;
}

int main(void) {
  printf("%ld",_1713_main());
  return 0;
}
