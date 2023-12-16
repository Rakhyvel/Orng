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
int64_t _939_main(void);
function1 _941_f(void);
int64_t _943_add_four(int64_t _943_x);

/* Function definitions */
int64_t _939_main(void){
    function0 _939_t0;
    function1 _939_t1;
    int64_t _939_t3;
    int64_t _939_t2;
    int64_t _939_$retval;
    _939_t0 = _941_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _939_t1 = _939_t0();
    $line_idx--;
    _939_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _939_t2 = _939_t1(_939_t3);
    $line_idx--;
    _939_$retval = _939_t2;
    return _939_$retval;
}

function1 _941_f(void){
    function1 _941_$retval;
    _941_$retval = _943_add_four;
    return _941_$retval;
}

int64_t _943_add_four(int64_t _943_x){
    int64_t _943_t0;
    int64_t _943_$retval;
    _943_t0 = 4;
    _943_$retval = $add_int64_t(_943_x, _943_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _943_$retval;
}

int main(void) {
  printf("%ld",_939_main());
  return 0;
}
