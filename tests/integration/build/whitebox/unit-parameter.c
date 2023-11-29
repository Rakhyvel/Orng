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
int64_t _1341_main(void);
int64_t _1344_f(int64_t _1344_x);

/* Function definitions */
int64_t _1341_main(void) {
    function0 _1341_t0;
    int64_t _1341_t2;
    int64_t _1341_t1;
    int64_t _1341_$retval;
    _1341_t0 = _1344_f;
    _1341_t2 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1341_t1 = _1341_t0(_1341_t2);
    $line_idx--;
    _1341_$retval = _1341_t1;
    return _1341_$retval;
}

int64_t _1344_f(int64_t _1344_x) {
    int64_t _1344_$retval;
    _1344_$retval = _1344_x;
    return _1344_$retval;
}

int main(void) {
  printf("%ld",_1341_main());
  return 0;
}
