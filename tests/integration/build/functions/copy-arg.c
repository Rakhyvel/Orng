/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _685_main(void);
int64_t _687_g(int64_t _687_x);
int64_t _689_f(int64_t _689_x);

/* Function definitions */
int64_t _685_main(void) {
    function0 _685_t0;
    int64_t _685_t2;
    int64_t _685_t1;
    int64_t _685_$retval;
    _685_t0 = _687_g;
    _685_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _685_t1 = _685_t0(_685_t2);
    $line_idx--;
    _685_$retval = _685_t1;
    return _685_$retval;
}

int64_t _687_g(int64_t _687_x) {
    int64_t _688_z;
    function0 _687_t0;
    int64_t _687_t1;
    int64_t _687_$retval;
    _688_z = _687_x;
    _687_t0 = _689_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _687_t1 = _687_t0(_688_z);
    $line_idx--;
    _687_$retval = _687_t1;
    return _687_$retval;
}

int64_t _689_f(int64_t _689_x) {
    int64_t _689_$retval;
    _689_$retval = _689_x;
    return _689_$retval;
}

int main(void) {
  printf("%ld",_685_main());
  return 0;
}
