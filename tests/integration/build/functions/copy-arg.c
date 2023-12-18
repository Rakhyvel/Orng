/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1053_main(void);
int64_t _1055_g(int64_t _1055_x);
int64_t _1057_f(int64_t _1057_x);

/* Function definitions */
int64_t _1053_main(void){
    function0 _1053_t0;
    int64_t _1053_t2;
    int64_t _1053_t1;
    int64_t _1053_$retval;
    _1053_t0 = _1055_g;
    _1053_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _1053_t1 = _1053_t0(_1053_t2);
    $line_idx--;
    _1053_$retval = _1053_t1;
    return _1053_$retval;
}

int64_t _1055_g(int64_t _1055_x){
    int64_t _1056_z;
    function0 _1055_t0;
    int64_t _1055_t1;
    int64_t _1055_$retval;
    _1056_z = _1055_x;
    _1055_t0 = _1057_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _1055_t1 = _1055_t0(_1056_z);
    $line_idx--;
    _1055_$retval = _1055_t1;
    return _1055_$retval;
}

int64_t _1057_f(int64_t _1057_x){
    int64_t _1057_$retval;
    _1057_$retval = _1057_x;
    return _1057_$retval;
}

int main(void) {
  printf("%ld",_1053_main());
  return 0;
}
