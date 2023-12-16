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
int64_t _1644_main(void);
int64_t _1646_f(int64_t _1646_x);

/* Function definitions */
int64_t _1644_main(void) {
    function0 _1644_t0;
    int64_t _1644_t3;
    int64_t _1644_t1;
    int64_t _1644_$retval;
    _1644_t0 = _1646_f;
    _1644_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1644_t1 = _1644_t0(_1644_t3);
    $line_idx--;
    _1644_$retval = _1644_t1;
    return _1644_$retval;
}

int64_t _1646_f(int64_t _1646_x) {
    int64_t _1646_$retval;
    _1646_$retval = _1646_x;
    return _1646_$retval;
}

int main(void) {
  printf("%ld",_1644_main());
  return 0;
}
