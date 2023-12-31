/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _468_main(void);
int64_t _470_f(void);
int64_t _472_g(void);

/* Function definitions */
int64_t _468_main(void){
    function0 _468_t0;
    int64_t _468_t1;
    int64_t _468_$retval;
    _468_t0 = _470_f;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:2:21:\nfn main() -> Int {f()}\n                   ^";
    _468_t1 = _468_t0();
    $line_idx--;
    _468_$retval = _468_t1;
    return _468_$retval;
}

int64_t _470_f(void){
    function0 _470_t0;
    int64_t _470_t1;
    int64_t _470_$retval;
    _470_t0 = _472_g;
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:4:18:\nfn f() -> Int {g()}\n                ^";
    _470_t1 = _470_t0();
    $line_idx--;
    _470_$retval = _470_t1;
    return _470_$retval;
}

int64_t _472_g(void){
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:27:\nfn g() -> Int {unreachable}\n                         ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_468_main());
  return 0;
}
