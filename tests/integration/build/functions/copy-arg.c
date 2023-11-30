/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _857_main(void);
int64_t _859_g(int64_t _859_x);
int64_t _862_f(int64_t _862_x);

/* Function definitions */
int64_t _857_main(void) {
    function0 _857_t0;
    int64_t _857_t2;
    int64_t _857_t1;
    int64_t _857_$retval;
    _857_t0 = _859_g;
    _857_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _857_t1 = _857_t0(_857_t2);
    $line_idx--;
    _857_$retval = _857_t1;
    return _857_$retval;
}

int64_t _859_g(int64_t _859_x) {
    int64_t _861_z;
    function0 _859_t0;
    int64_t _859_t1;
    int64_t _859_$retval;
    _861_z = _859_x;
    _859_t0 = _862_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _859_t1 = _859_t0(_861_z);
    $line_idx--;
    _859_$retval = _859_t1;
    return _859_$retval;
}

int64_t _862_f(int64_t _862_x) {
    int64_t _862_$retval;
    _862_$retval = _862_x;
    return _862_$retval;
}

int main(void) {
  printf("%ld",_857_main());
  return 0;
}
