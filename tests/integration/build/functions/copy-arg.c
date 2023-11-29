/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _855_main(void);
int64_t _857_g(int64_t _857_x);
int64_t _860_f(int64_t _860_x);

/* Function definitions */
int64_t _855_main(void) {
    function0 _855_t0;
    int64_t _855_t2;
    int64_t _855_t1;
    int64_t _855_$retval;
    _855_t0 = _857_g;
    _855_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _855_t1 = _855_t0(_855_t2);
    $line_idx--;
    _855_$retval = _855_t1;
    return _855_$retval;
}

int64_t _857_g(int64_t _857_x) {
    int64_t _859_z;
    function0 _857_t0;
    int64_t _857_t1;
    int64_t _857_$retval;
    _859_z = _857_x;
    _857_t0 = _860_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _857_t1 = _857_t0(_859_z);
    $line_idx--;
    _857_$retval = _857_t1;
    return _857_$retval;
}

int64_t _860_f(int64_t _860_x) {
    int64_t _860_$retval;
    _860_$retval = _860_x;
    return _860_$retval;
}

int main(void) {
  printf("%ld",_855_main());
  return 0;
}
