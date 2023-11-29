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
int64_t _63_main(void);
function1 _65_f(void);
int64_t _67_add_four(int64_t _67_x);

/* Function definitions */
int64_t _63_main(void) {
    function0 _63_t0;
    function1 _63_t1;
    int64_t _63_t3;
    int64_t _63_t2;
    int64_t _63_$retval;
    _63_t0 = _65_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _63_t1 = _63_t0();
    $line_idx--;
    _63_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _63_t2 = _63_t1(_63_t3);
    $line_idx--;
    _63_$retval = _63_t2;
    return _63_$retval;
}

function1 _65_f(void) {
    function1 _65_$retval;
    _65_$retval = _67_add_four;
    return _65_$retval;
}

int64_t _67_add_four(int64_t _67_x) {
    int64_t _67_t0;
    int64_t _67_$retval;
    _67_t0 = 4;
    _67_$retval = $add_int64_t(_67_x, _67_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _67_$retval;
}

int main(void) {
  printf("%ld",_63_main());
  return 0;
}
