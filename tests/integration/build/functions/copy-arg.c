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
int64_t _943_main(void);
int64_t _945_g(int64_t _945_x);
int64_t _947_f(int64_t _947_x);


/* Function definitions */
int64_t _943_main(void){
    function0 _943_t0;
    int64_t _943_t2;
    int64_t _943_t1;
    int64_t _943_$retval;
    _943_t0 = (function0) _945_g;
    _943_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _943_t1 = _943_t0(_943_t2);
    $line_idx--;
    _943_$retval = _943_t1;
    return _943_$retval;
}

int64_t _945_g(int64_t _945_x){
    int64_t _946_z;
    function0 _945_t1;
    int64_t _945_t2;
    int64_t _945_$retval;
    _946_z = _945_x;
    _945_t1 = (function0) _947_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _945_t2 = _945_t1(_946_z);
    $line_idx--;
    _945_$retval = _945_t2;
    return _945_$retval;
}

int64_t _947_f(int64_t _947_x){
    int64_t _947_$retval;
    goto BB1117;
BB1117:
    _947_$retval = _947_x;
    return _947_$retval;
}


int main(void) {
  printf("%ld",_943_main());
  return 0;
}
