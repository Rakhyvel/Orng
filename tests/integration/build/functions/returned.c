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
int64_t _1103_main(void);
function1 _1105_f(void);
int64_t _1107_add_four(int64_t _1107_x);

/* Function definitions */
int64_t _1103_main(void){
    function0 _1103_t0;
    function1 _1103_t1;
    int64_t _1103_t3;
    int64_t _1103_t2;
    int64_t _1103_$retval;
    _1103_t0 = _1105_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _1103_t1 = _1103_t0();
    $line_idx--;
    _1103_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _1103_t2 = _1103_t1(_1103_t3);
    $line_idx--;
    _1103_$retval = _1103_t2;
    return _1103_$retval;
}

function1 _1105_f(void){
    function1 _1105_$retval;
    _1105_$retval = _1107_add_four;
    return _1105_$retval;
}

int64_t _1107_add_four(int64_t _1107_x){
    int64_t _1107_t0;
    int64_t _1107_$retval;
    _1107_t0 = 4;
    _1107_$retval = $add_int64_t(_1107_x, _1107_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _1107_$retval;
}

int main(void) {
  printf("%ld",_1103_main());
  return 0;
}
