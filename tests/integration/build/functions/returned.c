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
int64_t _931_main(void);
function1 _933_f(void);
int64_t _935_add_four(int64_t _935_x);

/* Function definitions */
int64_t _931_main(void) {
    function0 _931_t0;
    function1 _931_t1;
    int64_t _931_t3;
    int64_t _931_t2;
    int64_t _931_$retval;
    _931_t0 = _933_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _931_t1 = _931_t0();
    $line_idx--;
    _931_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _931_t2 = _931_t1(_931_t3);
    $line_idx--;
    _931_$retval = _931_t2;
    return _931_$retval;
}

function1 _933_f(void) {
    function1 _933_$retval;
    _933_$retval = _935_add_four;
    return _933_$retval;
}

int64_t _935_add_four(int64_t _935_x) {
    int64_t _935_t0;
    int64_t _935_$retval;
    _935_t0 = 4;
    _935_$retval = $add_int64_t(_935_x, _935_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _935_$retval;
}

int main(void) {
  printf("%ld",_931_main());
  return 0;
}
