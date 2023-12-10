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
int64_t _734_main(void);
function1 _736_f(void);
int64_t _738_add_four(int64_t _738_x);

/* Function definitions */
int64_t _734_main(void) {
    function0 _734_t0;
    function1 _734_t1;
    int64_t _734_t3;
    int64_t _734_t2;
    int64_t _734_$retval;
    _734_t0 = _736_f;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _734_t1 = _734_t0();
    $line_idx--;
    _734_t3 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _734_t2 = _734_t1(_734_t3);
    $line_idx--;
    _734_$retval = _734_t2;
    return _734_$retval;
}

function1 _736_f(void) {
    function1 _736_$retval;
    _736_$retval = _738_add_four;
    return _736_$retval;
}

int64_t _738_add_four(int64_t _738_x) {
    int64_t _738_t0;
    int64_t _738_$retval;
    _738_t0 = 4;
    _738_$retval = $add_int64_t(_738_x, _738_t0, "tests/integration/functions/returned.orng:8:30:\nfn add_four(x: Int)->Int {x + 4}\n                            ^");
    return _738_$retval;
}

int main(void) {
  printf("%ld",_734_main());
  return 0;
}
