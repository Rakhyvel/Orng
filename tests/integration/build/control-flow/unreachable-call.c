/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_f(void);
int64_t _5_g(void);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    $line_idx--;
    _1_$retval = _3_f();
    return _1_$retval;
}

int64_t _3_f(void) {
    int64_t _3_$retval;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    $line_idx--;
    _3_$retval = _5_g();
    return _3_$retval;
}

int64_t _5_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
