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
int64_t _1692_main(void);
int64_t _1695_f(int64_t _1695_x);

/* Function definitions */
int64_t _1692_main(void) {
    function0 _1692_t0;
    int64_t _1692_t2;
    int64_t _1692_t1;
    int64_t _1692_$retval;
    _1692_t0 = _1695_f;
    _1692_t2 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1692_t1 = _1692_t0(_1692_t2);
    $line_idx--;
    _1692_$retval = _1692_t1;
    return _1692_$retval;
}

int64_t _1695_f(int64_t _1695_x) {
    int64_t _1695_$retval;
    _1695_$retval = _1695_x;
    return _1695_$retval;
}

int main(void) {
  printf("%ld",_1692_main());
  return 0;
}
