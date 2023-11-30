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
int64_t _1715_main(void);
int64_t _1718_f(int64_t _1718_x);

/* Function definitions */
int64_t _1715_main(void) {
    function0 _1715_t0;
    int64_t _1715_t2;
    int64_t _1715_t1;
    int64_t _1715_$retval;
    _1715_t0 = _1718_f;
    _1715_t2 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1715_t1 = _1715_t0(_1715_t2);
    $line_idx--;
    _1715_$retval = _1715_t1;
    return _1715_$retval;
}

int64_t _1718_f(int64_t _1718_x) {
    int64_t _1718_$retval;
    _1718_$retval = _1718_x;
    return _1718_$retval;
}

int main(void) {
  printf("%ld",_1715_main());
  return 0;
}
