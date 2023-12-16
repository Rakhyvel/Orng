/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _380_main(void);
int64_t _382_f(void);
int64_t _384_g(void);

/* Function definitions */
int64_t _380_main(void) {
    function0 _380_t0;
    int64_t _380_t1;
    int64_t _380_$retval;
    _380_t0 = _382_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _380_t1 = _380_t0();
    $line_idx--;
    _380_$retval = _380_t1;
    return _380_$retval;
}

int64_t _382_f(void) {
    function0 _382_t0;
    int64_t _382_t1;
    int64_t _382_$retval;
    _382_t0 = _384_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _382_t1 = _382_t0();
    $line_idx--;
    _382_$retval = _382_t1;
    return _382_$retval;
}

int64_t _384_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_380_main());
  return 0;
}
