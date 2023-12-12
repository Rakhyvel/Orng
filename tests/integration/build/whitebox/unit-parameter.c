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
int64_t _1287_main(void);
int64_t _1289_f(int64_t _1289_x);

/* Function definitions */
int64_t _1287_main(void) {
    function0 _1287_t0;
    int64_t _1287_t3;
    int64_t _1287_t1;
    int64_t _1287_$retval;
    _1287_t0 = _1289_f;
    _1287_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1287_t1 = _1287_t0(_1287_t3);
    $line_idx--;
    _1287_$retval = _1287_t1;
    return _1287_$retval;
}

int64_t _1289_f(int64_t _1289_x) {
    int64_t _1289_$retval;
    _1289_$retval = _1289_x;
    return _1289_$retval;
}

int main(void) {
  printf("%ld",_1287_main());
  return 0;
}
