/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _661_main(void);
int64_t _663_g(int64_t _663_x);
int64_t _665_f(int64_t _665_x);

/* Function definitions */
int64_t _661_main(void) {
    function0 _661_t0;
    int64_t _661_t2;
    int64_t _661_t1;
    int64_t _661_$retval;
    _661_t0 = _663_g;
    _661_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _661_t1 = _661_t0(_661_t2);
    $line_idx--;
    _661_$retval = _661_t1;
    return _661_$retval;
}

int64_t _663_g(int64_t _663_x) {
    int64_t _664_z;
    function0 _663_t0;
    int64_t _663_t1;
    int64_t _663_$retval;
    _664_z = _663_x;
    _663_t0 = _665_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _663_t1 = _663_t0(_664_z);
    $line_idx--;
    _663_$retval = _663_t1;
    return _663_$retval;
}

int64_t _665_f(int64_t _665_x) {
    int64_t _665_$retval;
    _665_$retval = _665_x;
    return _665_$retval;
}

int main(void) {
  printf("%ld",_661_main());
  return 0;
}
