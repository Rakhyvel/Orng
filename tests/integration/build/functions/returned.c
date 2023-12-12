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
int64_t _742_main(void);
function1 _744_f(void);
int64_t _746_add_four(int64_t _746_x);

/* Function definitions */
int64_t _742_main(void) {
    function0 _742_t0;
    function1 _742_t1;
    int64_t _742_t3;
    int64_t _742_t2;
    int64_t _742_$retval;
    _742_t0 = _744_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _742_t1 = _742_t0();
    $line_idx--;
    _742_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _742_t2 = _742_t1(_742_t3);
    $line_idx--;
    _742_$retval = _742_t2;
    return _742_$retval;
}

function1 _744_f(void) {
    function1 _744_$retval;
    _744_$retval = _746_add_four;
    return _744_$retval;
}

int64_t _746_add_four(int64_t _746_x) {
    int64_t _746_t0;
    int64_t _746_$retval;
    _746_t0 = 4;
    _746_$retval = $add_int64_t(_746_x, _746_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _746_$retval;
}

int main(void) {
  printf("%ld",_742_main());
  return 0;
}
