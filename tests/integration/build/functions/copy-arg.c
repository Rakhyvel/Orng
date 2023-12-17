/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1046_main(void);
int64_t _1048_g(int64_t _1048_x);
int64_t _1050_f(int64_t _1050_x);

/* Function definitions */
int64_t _1046_main(void){
    function0 _1046_t0;
    int64_t _1046_t2;
    int64_t _1046_t1;
    int64_t _1046_$retval;
    _1046_t0 = _1048_g;
    _1046_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _1046_t1 = _1046_t0(_1046_t2);
    $line_idx--;
    _1046_$retval = _1046_t1;
    return _1046_$retval;
}

int64_t _1048_g(int64_t _1048_x){
    int64_t _1049_z;
    function0 _1048_t0;
    int64_t _1048_t1;
    int64_t _1048_$retval;
    _1049_z = _1048_x;
    _1048_t0 = _1050_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _1048_t1 = _1048_t0(_1049_z);
    $line_idx--;
    _1048_$retval = _1048_t1;
    return _1048_$retval;
}

int64_t _1050_f(int64_t _1050_x){
    int64_t _1050_$retval;
    _1050_$retval = _1050_x;
    return _1050_$retval;
}

int main(void) {
  printf("%ld",_1046_main());
  return 0;
}
