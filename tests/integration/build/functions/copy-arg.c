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
int64_t _954_main(void);
int64_t _956_g(int64_t _956_x);
int64_t _958_f(int64_t _958_x);


/* Function definitions */
int64_t _954_main(void){
    function0 _954_t0;
    int64_t _954_t2;
    int64_t _954_t1;
    int64_t _954_$retval;
    _954_t0 = (function0) _956_g;
    _954_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _954_t1 = _954_t0(_954_t2);
    $line_idx--;
    _954_$retval = _954_t1;
    return _954_$retval;
}

int64_t _956_g(int64_t _956_x){
    int64_t _957_z;
    function0 _956_t1;
    int64_t _956_t2;
    int64_t _956_$retval;
    _957_z = _956_x;
    _956_t1 = (function0) _958_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _956_t2 = _956_t1(_957_z);
    $line_idx--;
    _956_$retval = _956_t2;
    return _956_$retval;
}

int64_t _958_f(int64_t _958_x){
    int64_t _958_$retval;
    goto BB1133;
BB1133:
    _958_$retval = _958_x;
    return _958_$retval;
}


int main(void) {
  printf("%ld",_954_main());
  return 0;
}
