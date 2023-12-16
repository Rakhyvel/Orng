/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function1)(int64_t);

typedef function1(*function0)(void);

/* Function forward definitions */
int64_t _950_main(void);
function1 _952_f(void);
int64_t _954_add_four(int64_t _954_x);

/* Function definitions */
int64_t _950_main(void){
    function0 _950_t0;
    function1 _950_t1;
    int64_t _950_t3;
    int64_t _950_t2;
    int64_t _950_$retval;
    _950_t0 = _952_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _950_t1 = _950_t0();
    $line_idx--;
    _950_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _950_t2 = _950_t1(_950_t3);
    $line_idx--;
    _950_$retval = _950_t2;
    return _950_$retval;
}

function1 _952_f(void){
    function1 _952_$retval;
    _952_$retval = _954_add_four;
    return _952_$retval;
}

int64_t _954_add_four(int64_t _954_x){
    int64_t _954_t0;
    int64_t _954_$retval;
    _954_t0 = 4;
    _954_$retval = $add_int64_t(_954_x, _954_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _954_$retval;
}

int main(void) {
  printf("%ld",_950_main());
  return 0;
}
