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
int64_t _1218_main(void);
int64_t _1221_f(int64_t _1221_x);

/* Function definitions */
int64_t _1218_main(void) {
    function0 _1218_t0;
    int64_t _1218_t2;
    int64_t _1218_t1;
    int64_t _1218_$retval;
    _1218_t0 = _1221_f;
    _1218_t2 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1218_t1 = _1218_t0(_1218_t2);
    $line_idx--;
    _1218_$retval = _1218_t1;
    return _1218_$retval;
}

int64_t _1221_f(int64_t _1221_x) {
    int64_t _1221_$retval;
    _1221_$retval = _1221_x;
    return _1221_$retval;
}

int main(void) {
  printf("%ld",_1218_main());
  return 0;
}
