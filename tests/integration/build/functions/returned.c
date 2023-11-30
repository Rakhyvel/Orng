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
int64_t _897_main(void);
function1 _899_f(void);
int64_t _901_add_four(int64_t _901_x);

/* Function definitions */
int64_t _897_main(void) {
    function0 _897_t0;
    function1 _897_t1;
    int64_t _897_t3;
    int64_t _897_t2;
    int64_t _897_$retval;
    _897_t0 = _899_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _897_t1 = _897_t0();
    $line_idx--;
    _897_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _897_t2 = _897_t1(_897_t3);
    $line_idx--;
    _897_$retval = _897_t2;
    return _897_$retval;
}

function1 _899_f(void) {
    function1 _899_$retval;
    _899_$retval = _901_add_four;
    return _899_$retval;
}

int64_t _901_add_four(int64_t _901_x) {
    int64_t _901_t0;
    int64_t _901_$retval;
    _901_t0 = 4;
    _901_$retval = $add_int64_t(_901_x, _901_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _901_$retval;
}

int main(void) {
  printf("%ld",_897_main());
  return 0;
}
