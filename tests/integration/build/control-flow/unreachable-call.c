/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _544_main(void);
int64_t _546_f(void);
int64_t _548_g(void);

/* Function definitions */
int64_t _544_main(void){
    function0 _544_t0;
    int64_t _544_t1;
    int64_t _544_$retval;
    _544_t0 = _546_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _544_t1 = _544_t0();
    $line_idx--;
    _544_$retval = _544_t1;
    return _544_$retval;
}

int64_t _546_f(void){
    function0 _546_t0;
    int64_t _546_t1;
    int64_t _546_$retval;
    _546_t0 = _548_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _546_t1 = _546_t0();
    $line_idx--;
    _546_$retval = _546_t1;
    return _546_$retval;
}

int64_t _548_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_544_main());
  return 0;
}
