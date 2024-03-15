/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _935_main(void);
int64_t _937_g(int64_t _937_x);
int64_t _939_f(int64_t _939_x);


/* Function definitions */
int64_t _935_main(void){
    function0 _935_t0;
    int64_t _935_t2;
    int64_t _935_t1;
    int64_t _935_$retval;
    _935_t0 = (function0) _937_g;
    _935_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _935_t1 = _935_t0(_935_t2);
    $line_idx--;
    _935_$retval = _935_t1;
    return _935_$retval;
}

int64_t _937_g(int64_t _937_x){
    int64_t _938_z;
    function0 _937_t1;
    int64_t _937_t2;
    int64_t _937_$retval;
    _938_z = _937_x;
    _937_t1 = (function0) _939_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _937_t2 = _937_t1(_938_z);
    $line_idx--;
    _937_$retval = _937_t2;
    return _937_$retval;
}

int64_t _939_f(int64_t _939_x){
    int64_t _939_$retval;
    _939_$retval = _939_x;
    return _939_$retval;
}


int main(void) {
  printf("%ld",_935_main());
  return 0;
}
