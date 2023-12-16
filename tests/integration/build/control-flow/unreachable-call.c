/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _399_main(void);
int64_t _401_f(void);
int64_t _403_g(void);

/* Function definitions */
int64_t _399_main(void){
    function0 _399_t0;
    int64_t _399_t1;
    int64_t _399_$retval;
    _399_t0 = _401_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _399_t1 = _399_t0();
    $line_idx--;
    _399_$retval = _399_t1;
    return _399_$retval;
}

int64_t _401_f(void){
    function0 _401_t0;
    int64_t _401_t1;
    int64_t _401_$retval;
    _401_t0 = _403_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _401_t1 = _401_t0();
    $line_idx--;
    _401_$retval = _401_t1;
    return _401_$retval;
}

int64_t _403_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_399_main());
  return 0;
}
