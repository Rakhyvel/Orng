/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _701_main(void);
int64_t _703_g(int64_t _703_x);
int64_t _705_f(int64_t _705_x);

/* Function definitions */
int64_t _701_main(void) {
    function0 _701_t0;
    int64_t _701_t2;
    int64_t _701_t1;
    int64_t _701_$retval;
    _701_t0 = _703_g;
    _701_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _701_t1 = _701_t0(_701_t2);
    $line_idx--;
    _701_$retval = _701_t1;
    return _701_$retval;
}

int64_t _703_g(int64_t _703_x) {
    int64_t _704_z;
    function0 _703_t0;
    int64_t _703_t1;
    int64_t _703_$retval;
    _704_z = _703_x;
    _703_t0 = _705_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _703_t1 = _703_t0(_704_z);
    $line_idx--;
    _703_$retval = _703_t1;
    return _703_$retval;
}

int64_t _705_f(int64_t _705_x) {
    int64_t _705_$retval;
    _705_$retval = _705_x;
    return _705_$retval;
}

int main(void) {
  printf("%ld",_701_main());
  return 0;
}
