/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _14_main(void);
int64_t _16_g(int64_t _16_x);
int64_t _18_f(int64_t _18_x);

/* Function definitions */
int64_t _14_main(void) {
    function0 _14_t0;
    int64_t _14_t2;
    int64_t _14_t1;
    int64_t _14_$retval;
    _14_t0 = _16_g;
    _14_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _14_t1 = _14_t0(_14_t2);
    $line_idx--;
    _14_$retval = _14_t1;
    return _14_$retval;
}

int64_t _16_g(int64_t _16_x) {
    int64_t _17_z;
    function0 _16_t0;
    int64_t _16_t1;
    int64_t _16_$retval;
    _17_z = _16_x;
    _16_t0 = _18_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _16_t1 = _16_t0(_17_z);
    $line_idx--;
    _16_$retval = _16_t1;
    return _16_$retval;
}

int64_t _18_f(int64_t _18_x) {
    int64_t _18_$retval;
    _18_$retval = _18_x;
    return _18_$retval;
}

int main(void) {
  printf("%ld",_14_main());
  return 0;
}
