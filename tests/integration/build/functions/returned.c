/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function1)(int64_t);

typedef function1(*function0)(void);

/* Function forward definitions */
int64_t _1003_main(void);
function1 _1005_f(void);
int64_t _1007_add_four(int64_t _1007_x);

/* Function definitions */
int64_t _1003_main(void){
    function0 _1003_t0;
    function1 _1003_t1;
    int64_t _1003_t3;
    int64_t _1003_t2;
    int64_t _1003_$retval;
    _1003_t0 = _1005_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _1003_t1 = _1003_t0();
    $line_idx--;
    _1003_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _1003_t2 = _1003_t1(_1003_t3);
    $line_idx--;
    _1003_$retval = _1003_t2;
    return _1003_$retval;
}

function1 _1005_f(void){
    function1 _1005_$retval;
    _1005_$retval = _1007_add_four;
    return _1005_$retval;
}

int64_t _1007_add_four(int64_t _1007_x){
    int64_t _1007_t0;
    int64_t _1007_$retval;
    _1007_t0 = 4;
    _1007_$retval = $add_int64_t(_1007_x, _1007_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _1007_$retval;
}

int main(void) {
  printf("%ld",_1003_main());
  return 0;
}
