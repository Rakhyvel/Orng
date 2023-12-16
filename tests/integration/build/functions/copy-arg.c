/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _961_main(void);
int64_t _963_g(int64_t _963_x);
int64_t _965_f(int64_t _965_x);

/* Function definitions */
int64_t _961_main(void){
    function0 _961_t0;
    int64_t _961_t2;
    int64_t _961_t1;
    int64_t _961_$retval;
    _961_t0 = _963_g;
    _961_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _961_t1 = _961_t0(_961_t2);
    $line_idx--;
    _961_$retval = _961_t1;
    return _961_$retval;
}

int64_t _963_g(int64_t _963_x){
    int64_t _964_z;
    function0 _963_t0;
    int64_t _963_t1;
    int64_t _963_$retval;
    _964_z = _963_x;
    _963_t0 = _965_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _963_t1 = _963_t0(_964_z);
    $line_idx--;
    _963_$retval = _963_t1;
    return _963_$retval;
}

int64_t _965_f(int64_t _965_x){
    int64_t _965_$retval;
    _965_$retval = _965_x;
    return _965_$retval;
}

int main(void) {
  printf("%ld",_961_main());
  return 0;
}
