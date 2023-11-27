/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _629_main(void);
int64_t _631_g(int64_t _631_x);
int64_t _633_f(int64_t _633_x);

/* Function definitions */
int64_t _629_main(void) {
    function0 _629_t0;
    int64_t _629_t2;
    int64_t _629_t1;
    int64_t _629_$retval;
    _629_t0 = _631_g;
    _629_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _629_t1 = _629_t0(_629_t2);
    $line_idx--;
    _629_$retval = _629_t1;
    return _629_$retval;
}

int64_t _631_g(int64_t _631_x) {
    int64_t _632_z;
    function0 _631_t0;
    int64_t _631_t1;
    int64_t _631_$retval;
    _632_z = _631_x;
    _631_t0 = _633_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _631_t1 = _631_t0(_632_z);
    $line_idx--;
    _631_$retval = _631_t1;
    return _631_$retval;
}

int64_t _633_f(int64_t _633_x) {
    int64_t _633_$retval;
    _633_$retval = _633_x;
    return _633_$retval;
}

int main(void) {
  printf("%ld",_629_main());
  return 0;
}
