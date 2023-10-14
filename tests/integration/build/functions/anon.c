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
int64_t _3_$anon0(int64_t _3_x);
int64_t _5_apply(function0 _5_f,int64_t _5_x);

/* Function definitions */
int64_t _1_main(void) {
    function0 _2_id;
    int64_t _1_t1;
    int64_t _1_$retval;
    _2_id = _3_$anon0;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _1_t1 = _5_apply(_2_id, 43);
    $line_idx--;
    _1_$retval = _1_t1;
    return _1_$retval;
}

int64_t _3_$anon0(int64_t _3_x) {
    int64_t _3_$retval;
    _3_$retval = _3_x;
    return _3_$retval;
}

int64_t _5_apply(function0 _5_f,int64_t _5_x) {
    int64_t _5_t0;
    int64_t _5_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _5_t0 = _5_f(_5_x);
    $line_idx--;
    _5_$retval = _5_t0;
    return _5_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
