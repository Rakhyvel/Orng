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
int64_t _710_main(void);
function1 _712_f(void);
int64_t _714_add_four(int64_t _714_x);

/* Function definitions */
int64_t _710_main(void) {
    function0 _710_t0;
    function1 _710_t1;
    int64_t _710_t3;
    int64_t _710_t2;
    int64_t _710_$retval;
    _710_t0 = _712_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _710_t1 = _710_t0();
    $line_idx--;
    _710_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _710_t2 = _710_t1(_710_t3);
    $line_idx--;
    _710_$retval = _710_t2;
    return _710_$retval;
}

function1 _712_f(void) {
    function1 _712_$retval;
    _712_$retval = _714_add_four;
    return _712_$retval;
}

int64_t _714_add_four(int64_t _714_x) {
    int64_t _714_t0;
    int64_t _714_$retval;
    _714_t0 = 4;
    _714_$retval = $add_int64_t(_714_x, _714_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _714_$retval;
}

int main(void) {
  printf("%ld",_710_main());
  return 0;
}
