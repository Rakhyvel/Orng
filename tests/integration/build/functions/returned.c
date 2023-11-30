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
int64_t _920_main(void);
function1 _922_f(void);
int64_t _924_add_four(int64_t _924_x);

/* Function definitions */
int64_t _920_main(void) {
    function0 _920_t0;
    function1 _920_t1;
    int64_t _920_t3;
    int64_t _920_t2;
    int64_t _920_$retval;
    _920_t0 = _922_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _920_t1 = _920_t0();
    $line_idx--;
    _920_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _920_t2 = _920_t1(_920_t3);
    $line_idx--;
    _920_$retval = _920_t2;
    return _920_$retval;
}

function1 _922_f(void) {
    function1 _922_$retval;
    _922_$retval = _924_add_four;
    return _922_$retval;
}

int64_t _924_add_four(int64_t _924_x) {
    int64_t _924_t0;
    int64_t _924_$retval;
    _924_t0 = 4;
    _924_$retval = $add_int64_t(_924_x, _924_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _924_$retval;
}

int main(void) {
  printf("%ld",_920_main());
  return 0;
}
