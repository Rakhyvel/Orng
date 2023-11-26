/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _78_main(void);
int64_t _80_f(void);
int64_t _82_g(void);

/* Function definitions */
int64_t _78_main(void) {
    function0 _78_t0;
    int64_t _78_t1;
    int64_t _78_$retval;
    _78_t0 = _80_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _78_t1 = _78_t0();
    $line_idx--;
    _78_$retval = _78_t1;
    return _78_$retval;
}

int64_t _80_f(void) {
    function0 _80_t0;
    int64_t _80_t1;
    int64_t _80_$retval;
    _80_t0 = _82_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _80_t1 = _80_t0();
    $line_idx--;
    _80_$retval = _80_t1;
    return _80_$retval;
}

int64_t _82_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_78_main());
  return 0;
}
