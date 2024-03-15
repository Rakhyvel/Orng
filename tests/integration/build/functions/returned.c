/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function1)(int64_t);

typedef function1(*function0)(void);

/* Function forward definitions */
int64_t _1001_main(void);
function1 _1003_f(void);
int64_t _1005_add_four(int64_t _1005_x);


/* Function definitions */
int64_t _1001_main(void){
    function0 _1001_t0;
    function1 _1001_t1;
    int64_t _1001_t3;
    int64_t _1001_t2;
    int64_t _1001_$retval;
    _1001_t0 = (function0) _1003_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _1001_t1 = _1001_t0();
    $line_idx--;
    _1001_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _1001_t2 = _1001_t1(_1001_t3);
    $line_idx--;
    _1001_$retval = _1001_t2;
    return _1001_$retval;
}

function1 _1003_f(void){
    function1 _1003_$retval;
    _1003_$retval = (function1) _1005_add_four;
    return _1003_$retval;
}

int64_t _1005_add_four(int64_t _1005_x){
    int64_t _1005_t0;
    int64_t _1005_$retval;
    _1005_t0 = 4;
    _1005_$retval = $add_int64_t(_1005_x, _1005_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _1005_$retval;
}


int main(void) {
  printf("%ld",_1001_main());
  return 0;
}
