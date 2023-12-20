/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _459_main(void);
int64_t _461_f(void);
int64_t _463_g(void);

/* Function definitions */
int64_t _459_main(void){
    function0 _459_t0;
    int64_t _459_t1;
    int64_t _459_$retval;
    _459_t0 = _461_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _459_t1 = _459_t0();
    $line_idx--;
    _459_$retval = _459_t1;
    return _459_$retval;
}

int64_t _461_f(void){
    function0 _461_t0;
    int64_t _461_t1;
    int64_t _461_$retval;
    _461_t0 = _463_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _461_t1 = _461_t0();
    $line_idx--;
    _461_$retval = _461_t1;
    return _461_$retval;
}

int64_t _463_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_459_main());
  return 0;
}
