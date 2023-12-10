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
int64_t _1279_main(void);
int64_t _1281_f(int64_t _1281_x);

/* Function definitions */
int64_t _1279_main(void) {
    function0 _1279_t0;
    int64_t _1279_t3;
    int64_t _1279_t1;
    int64_t _1279_$retval;
    _1279_t0 = _1281_f;
    _1279_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1279_t1 = _1279_t0(_1279_t3);
    $line_idx--;
    _1279_$retval = _1279_t1;
    return _1279_$retval;
}

int64_t _1281_f(int64_t _1281_x) {
    int64_t _1281_$retval;
    _1281_$retval = _1281_x;
    return _1281_$retval;
}

int main(void) {
  printf("%ld",_1279_main());
  return 0;
}
