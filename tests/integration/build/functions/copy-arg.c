/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _693_main(void);
int64_t _695_g(int64_t _695_x);
int64_t _697_f(int64_t _697_x);

/* Function definitions */
int64_t _693_main(void) {
    function0 _693_t0;
    int64_t _693_t2;
    int64_t _693_t1;
    int64_t _693_$retval;
    _693_t0 = _695_g;
    _693_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _693_t1 = _693_t0(_693_t2);
    $line_idx--;
    _693_$retval = _693_t1;
    return _693_$retval;
}

int64_t _695_g(int64_t _695_x) {
    int64_t _696_z;
    function0 _695_t0;
    int64_t _695_t1;
    int64_t _695_$retval;
    _696_z = _695_x;
    _695_t0 = _697_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _695_t1 = _695_t0(_696_z);
    $line_idx--;
    _695_$retval = _695_t1;
    return _695_$retval;
}

int64_t _697_f(int64_t _697_x) {
    int64_t _697_$retval;
    _697_$retval = _697_x;
    return _697_$retval;
}

int main(void) {
  printf("%ld",_693_main());
  return 0;
}
