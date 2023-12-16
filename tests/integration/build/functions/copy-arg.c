/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _901_main(void);
int64_t _903_g(int64_t _903_x);
int64_t _905_f(int64_t _905_x);

/* Function definitions */
int64_t _901_main(void){
    function0 _901_t0;
    int64_t _901_t2;
    int64_t _901_t1;
    int64_t _901_$retval;
    _901_t0 = _903_g;
    _901_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _901_t1 = _901_t0(_901_t2);
    $line_idx--;
    _901_$retval = _901_t1;
    return _901_$retval;
}

int64_t _903_g(int64_t _903_x){
    int64_t _904_z;
    function0 _903_t0;
    int64_t _903_t1;
    int64_t _903_$retval;
    _904_z = _903_x;
    _903_t0 = _905_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _903_t1 = _903_t0(_904_z);
    $line_idx--;
    _903_$retval = _903_t1;
    return _903_$retval;
}

int64_t _905_f(int64_t _905_x){
    int64_t _905_$retval;
    _905_$retval = _905_x;
    return _905_$retval;
}

int main(void) {
  printf("%ld",_901_main());
  return 0;
}
