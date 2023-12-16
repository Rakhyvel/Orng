/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _890_main(void);
int64_t _892_g(int64_t _892_x);
int64_t _894_f(int64_t _894_x);

/* Function definitions */
int64_t _890_main(void){
    function0 _890_t0;
    int64_t _890_t2;
    int64_t _890_t1;
    int64_t _890_$retval;
    _890_t0 = _892_g;
    _890_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _890_t1 = _890_t0(_890_t2);
    $line_idx--;
    _890_$retval = _890_t1;
    return _890_$retval;
}

int64_t _892_g(int64_t _892_x){
    int64_t _893_z;
    function0 _892_t0;
    int64_t _892_t1;
    int64_t _892_$retval;
    _893_z = _892_x;
    _892_t0 = _894_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _892_t1 = _892_t0(_893_z);
    $line_idx--;
    _892_$retval = _892_t1;
    return _892_$retval;
}

int64_t _894_f(int64_t _894_x){
    int64_t _894_$retval;
    _894_$retval = _894_x;
    return _894_$retval;
}

int main(void) {
  printf("%ld",_890_main());
  return 0;
}
