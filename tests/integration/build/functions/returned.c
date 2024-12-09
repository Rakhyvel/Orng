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
int64_t _1020_main(void);
function1 _1022_f(void);
int64_t _1024_add_four(int64_t _1024_x);


/* Function definitions */
int64_t _1020_main(void){
    function0 _1020_t0;
    function1 _1020_t1;
    int64_t _1020_t3;
    int64_t _1020_t2;
    int64_t _1020_$retval;
    _1020_t0 = (function0) _1022_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _1020_t1 = _1020_t0();
    $line_idx--;
    _1020_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _1020_t2 = _1020_t1(_1020_t3);
    $line_idx--;
    _1020_$retval = _1020_t2;
    return _1020_$retval;
}

function1 _1022_f(void){
    function1 _1022_$retval;
    _1022_$retval = (function1) _1024_add_four;
    return _1022_$retval;
}

int64_t _1024_add_four(int64_t _1024_x){
    int64_t _1024_t0;
    int64_t _1024_$retval;
    _1024_t0 = 4;
    _1024_$retval = $add_int64_t(_1024_x, _1024_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _1024_$retval;
}


int main(void) {
  printf("%ld",_1020_main());
  return 0;
}
