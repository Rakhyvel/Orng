/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _712_main(void);
int64_t _714_g(int64_t _714_x);
int64_t _716_f(int64_t _716_x);

/* Function definitions */
int64_t _712_main(void) {
    function0 _712_t0;
    int64_t _712_t2;
    int64_t _712_t1;
    int64_t _712_$retval;
    _712_t0 = _714_g;
    _712_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _712_t1 = _712_t0(_712_t2);
    $line_idx--;
    _712_$retval = _712_t1;
    return _712_$retval;
}

int64_t _714_g(int64_t _714_x) {
    int64_t _715_z;
    function0 _714_t0;
    int64_t _714_t1;
    int64_t _714_$retval;
    _715_z = _714_x;
    _714_t0 = _716_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _714_t1 = _714_t0(_715_z);
    $line_idx--;
    _714_$retval = _714_t1;
    return _714_$retval;
}

int64_t _716_f(int64_t _716_x) {
    int64_t _716_$retval;
    _716_$retval = _716_x;
    return _716_$retval;
}

int main(void) {
  printf("%ld",_712_main());
  return 0;
}
