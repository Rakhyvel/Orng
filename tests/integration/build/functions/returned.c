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
int64_t _1095_main(void);
function1 _1097_f(void);
int64_t _1099_add_four(int64_t _1099_x);

/* Function definitions */
int64_t _1095_main(void){
    function0 _1095_t0;
    function1 _1095_t1;
    int64_t _1095_t3;
    int64_t _1095_t2;
    int64_t _1095_$retval;
    _1095_t0 = _1097_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _1095_t1 = _1095_t0();
    $line_idx--;
    _1095_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _1095_t2 = _1095_t1(_1095_t3);
    $line_idx--;
    _1095_$retval = _1095_t2;
    return _1095_$retval;
}

function1 _1097_f(void){
    function1 _1097_$retval;
    _1097_$retval = _1099_add_four;
    return _1097_$retval;
}

int64_t _1099_add_four(int64_t _1099_x){
    int64_t _1099_t0;
    int64_t _1099_$retval;
    _1099_t0 = 4;
    _1099_$retval = $add_int64_t(_1099_x, _1099_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _1099_$retval;
}

int main(void) {
  printf("%ld",_1095_main());
  return 0;
}
