/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1_main(void);
function0 _3_f(void);
int64_t _5_add_four(int64_t _5_x);

/* Function definitions */
int64_t _1_main(void) {
    function0 _1_t0;
    int64_t _1_t1;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _1_t0 = _3_f();
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _1_t1 = _1_t0(45);
    $line_idx--;
    _1_$retval = _1_t1;
    return _1_$retval;
}

function0 _3_f(void) {
    function0 _3_$retval;
    _3_$retval = _5_add_four;
    return _3_$retval;
}

int64_t _5_add_four(int64_t _5_x) {
    int64_t _5_$retval;
    _5_$retval = $add_int64_t(_5_x, 4, "tests/integration/functions/returned.orng:8:3:\nfn add_four(x: Int)->Int {x + 4}\n ^");
    return _5_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
