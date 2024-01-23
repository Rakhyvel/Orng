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
int64_t _1008_main(void);
function1 _1010_f(void);
int64_t _1012_add_four(int64_t _1012_x);


/* Function definitions */
int64_t _1008_main(void){
    function0 _1008_t0;
    function1 _1008_t1;
    int64_t _1008_t3;
    int64_t _1008_t2;
    int64_t _1008_$retval;
    _1008_t0 = _1010_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _1008_t1 = _1008_t0();
    $line_idx--;
    _1008_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _1008_t2 = _1008_t1(_1008_t3);
    $line_idx--;
    _1008_$retval = _1008_t2;
    return _1008_$retval;
}

function1 _1010_f(void){
    function1 _1010_$retval;
    _1010_$retval = _1012_add_four;
    return _1010_$retval;
}

int64_t _1012_add_four(int64_t _1012_x){
    int64_t _1012_t0;
    int64_t _1012_$retval;
    _1012_t0 = 4;
    _1012_$retval = $add_int64_t(_1012_x, _1012_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _1012_$retval;
}


int main(void) {
  printf("%ld",_1008_main());
  return 0;
}
