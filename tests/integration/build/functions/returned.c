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
int64_t _918_main(void);
function1 _920_f(void);
int64_t _922_add_four(int64_t _922_x);

/* Function definitions */
int64_t _918_main(void) {
    function0 _918_t0;
    function1 _918_t1;
    int64_t _918_t3;
    int64_t _918_t2;
    int64_t _918_$retval;
    _918_t0 = _920_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _918_t1 = _918_t0();
    $line_idx--;
    _918_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _918_t2 = _918_t1(_918_t3);
    $line_idx--;
    _918_$retval = _918_t2;
    return _918_$retval;
}

function1 _920_f(void) {
    function1 _920_$retval;
    _920_$retval = _922_add_four;
    return _920_$retval;
}

int64_t _922_add_four(int64_t _922_x) {
    int64_t _922_t0;
    int64_t _922_$retval;
    _922_t0 = 4;
    _922_$retval = $add_int64_t(_922_x, _922_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _922_$retval;
}

int main(void) {
  printf("%ld",_918_main());
  return 0;
}
