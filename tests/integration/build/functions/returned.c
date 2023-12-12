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
int64_t _761_main(void);
function1 _763_f(void);
int64_t _765_add_four(int64_t _765_x);

/* Function definitions */
int64_t _761_main(void) {
    function0 _761_t0;
    function1 _761_t1;
    int64_t _761_t3;
    int64_t _761_t2;
    int64_t _761_$retval;
    _761_t0 = _763_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _761_t1 = _761_t0();
    $line_idx--;
    _761_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _761_t2 = _761_t1(_761_t3);
    $line_idx--;
    _761_$retval = _761_t2;
    return _761_$retval;
}

function1 _763_f(void) {
    function1 _763_$retval;
    _763_$retval = _765_add_four;
    return _763_$retval;
}

int64_t _765_add_four(int64_t _765_x) {
    int64_t _765_t0;
    int64_t _765_$retval;
    _765_t0 = 4;
    _765_$retval = $add_int64_t(_765_x, _765_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _765_$retval;
}

int main(void) {
  printf("%ld",_761_main());
  return 0;
}
