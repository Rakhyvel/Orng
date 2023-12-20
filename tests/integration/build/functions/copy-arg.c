/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _927_main(void);
int64_t _929_g(int64_t _929_x);
int64_t _931_f(int64_t _931_x);

/* Function definitions */
int64_t _927_main(void){
    function0 _927_t0;
    int64_t _927_t2;
    int64_t _927_t1;
    int64_t _927_$retval;
    _927_t0 = _929_g;
    _927_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _927_t1 = _927_t0(_927_t2);
    $line_idx--;
    _927_$retval = _927_t1;
    return _927_$retval;
}

int64_t _929_g(int64_t _929_x){
    int64_t _930_z;
    function0 _929_t0;
    int64_t _929_t1;
    int64_t _929_$retval;
    _930_z = _929_x;
    _929_t0 = _931_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _929_t1 = _929_t0(_930_z);
    $line_idx--;
    _929_$retval = _929_t1;
    return _929_$retval;
}

int64_t _931_f(int64_t _931_x){
    int64_t _931_$retval;
    _931_$retval = _931_x;
    return _931_$retval;
}

int main(void) {
  printf("%ld",_927_main());
  return 0;
}
