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
int64_t _750_main(void);
function1 _752_f(void);
int64_t _754_add_four(int64_t _754_x);

/* Function definitions */
int64_t _750_main(void) {
    function0 _750_t0;
    function1 _750_t1;
    int64_t _750_t3;
    int64_t _750_t2;
    int64_t _750_$retval;
    _750_t0 = _752_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _750_t1 = _750_t0();
    $line_idx--;
    _750_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _750_t2 = _750_t1(_750_t3);
    $line_idx--;
    _750_$retval = _750_t2;
    return _750_$retval;
}

function1 _752_f(void) {
    function1 _752_$retval;
    _752_$retval = _754_add_four;
    return _752_$retval;
}

int64_t _754_add_four(int64_t _754_x) {
    int64_t _754_t0;
    int64_t _754_$retval;
    _754_t0 = 4;
    _754_$retval = $add_int64_t(_754_x, _754_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _754_$retval;
}

int main(void) {
  printf("%ld",_750_main());
  return 0;
}
