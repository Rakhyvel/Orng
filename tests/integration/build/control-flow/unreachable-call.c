/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _270_main(void);
int64_t _272_f(void);
int64_t _274_g(void);

/* Function definitions */
int64_t _270_main(void) {
    function0 _270_t0;
    int64_t _270_t1;
    int64_t _270_$retval;
    _270_t0 = _272_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _270_t1 = _270_t0();
    $line_idx--;
    _270_$retval = _270_t1;
    return _270_$retval;
}

int64_t _272_f(void) {
    function0 _272_t0;
    int64_t _272_t1;
    int64_t _272_$retval;
    _272_t0 = _274_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _272_t1 = _272_t0();
    $line_idx--;
    _272_$retval = _272_t1;
    return _272_$retval;
}

int64_t _274_g(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_270_main());
  return 0;
}
