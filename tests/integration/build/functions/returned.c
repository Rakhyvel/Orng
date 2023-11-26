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
int64_t _647_main(void);
function1 _649_f(void);
int64_t _651_add_four(int64_t _651_x);

/* Function definitions */
int64_t _647_main(void) {
    function0 _647_t0;
    function1 _647_t1;
    int64_t _647_t3;
    int64_t _647_t2;
    int64_t _647_$retval;
    _647_t0 = _649_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _647_t1 = _647_t0();
    $line_idx--;
    _647_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _647_t2 = _647_t1(_647_t3);
    $line_idx--;
    _647_$retval = _647_t2;
    return _647_$retval;
}

function1 _649_f(void) {
    function1 _649_$retval;
    _649_$retval = _651_add_four;
    return _649_$retval;
}

int64_t _651_add_four(int64_t _651_x) {
    int64_t _651_t0;
    int64_t _651_$retval;
    _651_t0 = 4;
    _651_$retval = $add_int64_t(_651_x, _651_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _651_$retval;
}

int main(void) {
  printf("%ld",_647_main());
  return 0;
}
